//Falcon-180B DATASET v1.0 Category: System administration ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    int choice, num, sum = 0;
    char str[50];

    printf("Welcome to the Artistic Calculator!\n");
    printf("Enter a number: ");
    scanf("%d", &num);

    while(1) {
        printf("Select an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square\n");
        printf("6. Cube\n");
        printf("7. Square Root\n");
        printf("8. Cube Root\n");
        printf("9. Logarithm\n");
        printf("10. Exponential\n");
        printf("11. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                sum += num;
                break;
            case 2:
                sum -= num;
                break;
            case 3:
                sum *= num;
                break;
            case 4:
                if(num!= 0) {
                    sum /= num;
                }
                break;
            case 5:
                sum = num * num;
                break;
            case 6:
                sum = num * num * num;
                break;
            case 7:
                sum = sqrt(num);
                break;
            case 8:
                sum = cbrt(num);
                break;
            case 9:
                sum = log(num);
                break;
            case 10:
                sum = exp(num);
                break;
            case 11:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}