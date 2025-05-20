//FormAI DATASET v1.0 Category: Unit converter ; Style: surrealist
#include <stdio.h>

// surreal unit conversions
float feet_to_tentacles(float feet) {
    float tentacles = feet * 2.718281828f;
    return tentacles;
}

float dreams_to_reality(float dreams) {
    float reality = dreams / 0.666666666f;
    return reality;
}

float thoughts_to_butterflies(float thoughts) {
    float butterflies = thoughts * 0.0000000005897932f;
    return butterflies;
}

// main function
int main() {
    int choice;
    float input, result;

    printf("Welcome to the Surreal Unit Converter\n");
    printf("1. Feet to Tentacles\n");
    printf("2. Dreams to Reality\n");
    printf("3. Thoughts to Butterflies\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter feet: ");
            scanf("%f", &input);
            result = feet_to_tentacles(input);
            printf("%.2f feet = %.2f tentacles\n", input, result);
            break;
        case 2:
            printf("Enter dreams: ");
            scanf("%f", &input);
            result = dreams_to_reality(input);
            printf("%.2f dreams = %.2f reality\n", input, result);
            break;
        case 3:
            printf("Enter thoughts: ");
            scanf("%f", &input);
            result = thoughts_to_butterflies(input);
            printf("%.2f thoughts = %.2f butterflies\n", input, result);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}