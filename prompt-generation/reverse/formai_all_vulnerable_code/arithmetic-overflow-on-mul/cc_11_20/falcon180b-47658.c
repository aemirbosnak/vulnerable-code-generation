//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int num1, num2, operation;

    // Generate random numbers
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;

    // Generate random operation
    operation = rand() % 4;

    switch(operation) {
        case 0: // Addition
            printf("Enter the result of %d + %d: ", num1, num2);
            if(scanf("%d", &num1)!= 1 || num1!= num1 + num2) {
                printf("Incorrect answer!\n");
            } else {
                printf("Correct answer!\n");
            }
            break;
        case 1: // Subtraction
            printf("Enter the result of %d - %d: ", num1, num2);
            if(scanf("%d", &num1)!= 1 || num1!= num1 - num2) {
                printf("Incorrect answer!\n");
            } else {
                printf("Correct answer!\n");
            }
            break;
        case 2: // Multiplication
            printf("Enter the result of %d * %d: ", num1, num2);
            if(scanf("%d", &num1)!= 1 || num1!= num1 * num2) {
                printf("Incorrect answer!\n");
            } else {
                printf("Correct answer!\n");
            }
            break;
        case 3: // Division
            printf("Enter the result of %d / %d: ", num1, num2);
            if(scanf("%d", &num1)!= 1 || num1!= num1 / num2) {
                printf("Incorrect answer!\n");
            } else {
                printf("Correct answer!\n");
            }
            break;
        default:
            printf("Invalid operation!\n");
    }

    return 0;
}