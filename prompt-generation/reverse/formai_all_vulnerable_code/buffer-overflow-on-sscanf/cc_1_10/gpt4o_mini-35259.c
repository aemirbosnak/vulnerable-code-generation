//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_HOUSES 100
#define NUM_FEATURES 3

typedef struct {
    float bedrooms;
    float square_footage;
    float age;
    float price;
} House;

House houses[MAX_HOUSES];
int count = 0;

void inputHouseData() {
    printf("Enter house data (bedrooms, square_footage, age, price) one per line (type 'end' to finish):\n");
    while (count < MAX_HOUSES) {
        char input[100];
        fgets(input, sizeof(input), stdin);
        if (strncmp(input, "end", 3) == 0) {
            break;
        }
        sscanf(input, "%f %f %f %f", &houses[count].bedrooms, &houses[count].square_footage, &houses[count].age, &houses[count].price);
        count++;
    }
}

void calculateCoefficients(float *coef) {
    float X[MAX_HOUSES][NUM_FEATURES + 1];
    float Y[MAX_HOUSES];
    float XT[NUM_FEATURES + 1][MAX_HOUSES];
    float XTX[NUM_FEATURES + 1][NUM_FEATURES + 1] = {0};
    float XTY[NUM_FEATURES + 1] = {0};
    
    // Prepare matrices
    for (int i = 0; i < count; i++) {
        X[i][0] = 1.0;  // Intercept
        X[i][1] = houses[i].bedrooms;
        X[i][2] = houses[i].square_footage;
        X[i][3] = houses[i].age;
        Y[i] = houses[i].price;
    }
    
    // Transpose X
    for (int i = 0; i < count; i++) {
        for (int j = 0; j <= NUM_FEATURES; j++) {
            XT[j][i] = X[i][j];
        }
    }
    
    // Calculate XTX
    for (int i = 0; i <= NUM_FEATURES; i++) {
        for (int j = 0; j <= NUM_FEATURES; j++) {
            for (int k = 0; k < count; k++) {
                XTX[i][j] += XT[i][k] * X[k][j];
            }
        }
    }
    
    // Calculate XTY
    for (int i = 0; i <= NUM_FEATURES; i++) {
        for (int k = 0; k < count; k++) {
            XTY[i] += XT[i][k] * Y[k];
        }
    }
    
    // Solve for coefficients using simple Gaussian elimination
    for (int i = 0; i <= NUM_FEATURES; i++) {
        for (int j = 0; j <= NUM_FEATURES; j++) {
            if (i == j) {
                XTX[i][j] += 1e-10;  // To avoid singular matrix
            }
        }
    }
    
    // Simple Gaussian Elimination
    for (int i = 0; i <= NUM_FEATURES; i++) {
        for (int j = i + 1; j <= NUM_FEATURES; j++) {
            float ratio = XTX[j][i] / XTX[i][i];
            for (int k = 0; k <= NUM_FEATURES; k++) {
                XTX[j][k] -= ratio * XTX[i][k];
            }
            XTY[j] -= ratio * XTY[i];
        }
    }

    // Back substitution
    for (int i = NUM_FEATURES; i >= 0; i--) {
        coef[i] = XTY[i];
        for (int j = i + 1; j <= NUM_FEATURES; j++) {
            coef[i] -= XTX[i][j] * coef[j];
        }
        coef[i] /= XTX[i][i];
    }
}

void predictHousePrice(float *coef) {
    float input_features[NUM_FEATURES];
    printf("Enter features for prediction (bedrooms, square_footage, age): ");
    scanf("%f %f %f", &input_features[0], &input_features[1], &input_features[2]);
    
    float predicted_price = coef[0] + coef[1] * input_features[0] + 
                            coef[2] * input_features[1] + coef[3] * input_features[2];
    
    printf("Predicted House Price: %.2f\n", predicted_price);
}

int main() {
    float coefficients[NUM_FEATURES + 1] = {0};

    inputHouseData();
    calculateCoefficients(coefficients);
    predictHousePrice(coefficients);

    return 0;
}