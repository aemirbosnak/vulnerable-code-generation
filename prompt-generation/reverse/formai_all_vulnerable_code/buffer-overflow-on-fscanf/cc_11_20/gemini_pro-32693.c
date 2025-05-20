//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define PIXELS 28
#define DIGITS 10

int main() {
    int image[PIXELS][PIXELS];
    int label;
    int i, j;

    // Read the image and label from a file.
    FILE *fp = fopen("image.txt", "r");
    for (i = 0; i < PIXELS; i++) {
        for (j = 0; j < PIXELS; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }
    fscanf(fp, "%d", &label);
    fclose(fp);

    // Display the image.
    for (i = 0; i < PIXELS; i++) {
        for (j = 0; j < PIXELS; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Train the classifier.
    int weights[PIXELS][PIXELS][DIGITS];
    int biases[DIGITS];
    for (i = 0; i < PIXELS; i++) {
        for (j = 0; j < PIXELS; j++) {
            for (int k = 0; k < DIGITS; k++) {
                weights[i][j][k] = rand() % 10;
            }
        }
    }
    for (i = 0; i < DIGITS; i++) {
        biases[i] = rand() % 10;
    }

    // Classify the image.
    int prediction = -1;
    int max_score = -1;
    for (i = 0; i < DIGITS; i++) {
        int score = 0;
        for (j = 0; j < PIXELS; j++) {
            for (int k = 0; k < PIXELS; k++) {
                score += weights[j][k][i] * image[j][k];
            }
        }
        score += biases[i];
        if (score > max_score) {
            max_score = score;
            prediction = i;
        }
    }

    // Print the prediction.
    printf("Prediction: %d\n", prediction);
}