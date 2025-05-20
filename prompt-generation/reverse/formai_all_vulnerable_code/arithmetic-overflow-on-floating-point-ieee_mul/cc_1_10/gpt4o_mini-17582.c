//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function prototypes
void performBasicOperations();
void performAdvancedOperations();
void displayMenu();
int getMenuChoice();
void calculateAreaOfShapes();
void calculateStatistics();

int main() {
    int keepRunning = 1;

    while(keepRunning) {
        displayMenu();
        int choice = getMenuChoice();

        switch(choice) {
            case 1:
                performBasicOperations();
                break;
            case 2:
                performAdvancedOperations();
                break;
            case 3:
                calculateAreaOfShapes();
                break;
            case 4:
                calculateStatistics();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                keepRunning = 0;
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n====================================\n");
    printf("          Math Exercise Menu        \n");
    printf("====================================\n");
    printf("1. Basic Operations\n");
    printf("2. Advanced Operations\n");
    printf("3. Area of Shapes Calculation\n");
    printf("4. Statistical Analysis\n");
    printf("5. Exit\n");
    printf("Please enter your choice: ");
}

int getMenuChoice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

void performBasicOperations() {
    float num1, num2;
    printf("Enter two numbers for basic operations:\n");
    printf("Number 1: ");
    scanf("%f", &num1);
    printf("Number 2: ");
    scanf("%f", &num2);

    printf("Sum: %.2f\n", num1 + num2);
    printf("Difference: %.2f\n", num1 - num2);
    printf("Product: %.2f\n", num1 * num2);
    if (num2 != 0) {
        printf("Quotient: %.2f\n", num1 / num2);
    } else {
        printf("Division by zero error!\n");
    }
}

void performAdvancedOperations() {
    float angleDegrees, angleRadians, result;
    printf("Enter an angle in degrees for advanced operations:\n");
    printf("Angle (degrees): ");
    scanf("%f", &angleDegrees);

    angleRadians = angleDegrees * (M_PI / 180.0); // convert degrees to radians

    result = sin(angleRadians);
    printf("Sine: %.2f\n", result);

    result = cos(angleRadians);
    printf("Cosine: %.2f\n", result);

    result = tan(angleRadians);
    printf("Tangent: %.2f\n", result);

    result = 1 / tan(angleRadians);
    printf("Cotangent: %.2f\n", result);
}

void calculateAreaOfShapes() {
    int shapeChoice;
    printf("\nChoose a shape to calculate its area:\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("Enter your choice: ");
    scanf("%d", &shapeChoice);

    switch (shapeChoice) {
        case 1: {
            float radius;
            printf("Enter the radius of the circle: ");
            scanf("%f", &radius);
            printf("Area of circle: %.2f\n", M_PI * radius * radius);
            break;
        }
        case 2: {
            float length, width;
            printf("Enter the length and width of the rectangle:\n");
            printf("Length: ");
            scanf("%f", &length);
            printf("Width: ");
            scanf("%f", &width);
            printf("Area of rectangle: %.2f\n", length * width);
            break;
        }
        case 3: {
            float base, height;
            printf("Enter the base and height of the triangle:\n");
            printf("Base: ");
            scanf("%f", &base);
            printf("Height: ");
            scanf("%f", &height);
            printf("Area of triangle: %.2f\n", 0.5 * base * height);
            break;
        }
        default:
            printf("Invalid shape choice.\n");
            break;
    }
}

void calculateStatistics() {
    int n, i;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float *data = (float*)malloc(n * sizeof(float));
    printf("Enter the data points:\n");
    for (i = 0; i < n; i++) {
        printf("Data point %d: ", i+1);
        scanf("%f", &data[i]);
    }

    // Calculate mean
    float sum = 0;
    for (i = 0; i < n; i++) {
        sum += data[i];
    }
    float mean = sum / n;
    printf("Mean: %.2f\n", mean);

    // Calculate variance and standard deviation
    float variance_sum = 0;
    for (i = 0; i < n; i++) {
        variance_sum += (data[i] - mean) * (data[i] - mean);
    }
    float variance = variance_sum / n;
    float stddev = sqrt(variance);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", stddev);

    free(data);
}