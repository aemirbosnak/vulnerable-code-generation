//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shape shifting
#include <stdio.h>
#include <math.h>

int main() {
    int choice, num;
    float result, angle;

    printf("\nC Shape Shifting Scientific Calculator\n");

    do {
        printf("\nPlease select an operation:\n");
        printf("1. Square Root\n");
        printf("2. Sinusoidal\n");
        printf("3. Cosinusoidal\n");
        printf("4. Logarithmic\n");
        printf("5. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter number: ");
                scanf("%d", &num);
                result = sqrt(num);
                printf("\nResult: %.2f", result);
                break;
            case 2:
                printf("\nEnter angle in degrees: ");
                scanf("%f", &angle);
                result = sin(angle * M_PI / 180);
                printf("\nResult: %.2f", result);
                break;
            case 3:
                printf("\nEnter angle in degrees:");
                scanf("%f", &angle);
                result = cos(angle * M_PI / 180);
                printf("\nResult: %.2f", result);
                break;
            case 4:
                printf("\nEnter number: ");
                scanf("%d", &num);
                result = log10(num);
                printf("\nResult: %.2f", result);
                break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}