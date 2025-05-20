//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int num1, num2, choice;
    float result;
    char repeat;

    do {
        printf("Enter two numbers: ");
        scanf("%d %d", &num1, &num2);
        printf("Enter your choice:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Square root\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                result = num1 + num2;
                printf("The result is %.2f\n", result);
                break;
            case 2:
                result = num1 - num2;
                printf("The result is %.2f\n", result);
                break;
            case 3:
                result = num1 * num2;
                printf("The result is %.2f\n", result);
                break;
            case 4:
                if(num2 == 0) {
                    printf("Cannot divide by zero!\n");
                } else {
                    result = num1 / num2;
                    printf("The result is %.2f\n", result);
                }
                break;
            case 5:
                if(num1 < 0) {
                    printf("Square root of negative number is undefined!\n");
                } else {
                    result = sqrt(num1);
                    printf("The result is %.2f\n", result);
                }
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &repeat);
    } while(repeat == 'y' || repeat == 'Y');

    return 0;
}