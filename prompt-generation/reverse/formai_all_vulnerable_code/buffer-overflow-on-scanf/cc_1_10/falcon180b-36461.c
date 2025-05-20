//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operation, result;
    char choice;
    float rand_num;

    printf("Welcome to the Arithmetic Game!\n");
    printf("Please choose a difficulty level:\n");
    printf("1. Easy\n2. Medium\n3. Hard\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You have chosen Easy mode.\n");
            break;
        case 2:
            printf("You have chosen Medium mode.\n");
            break;
        case 3:
            printf("You have chosen Hard mode.\n");
            break;
        default:
            printf("Invalid choice. Exiting program.\n");
            return 0;
    }

    srand(time(NULL));
    rand_num = rand() % 100;

    printf("Please enter the first number:\n");
    scanf("%d", &num1);
    printf("Please enter the second number:\n");
    scanf("%d", &num2);

    operation = rand() % 4;

    switch(operation) {
        case 0:
            printf("The operation is addition.\n");
            result = num1 + num2;
            break;
        case 1:
            printf("The operation is subtraction.\n");
            result = num1 - num2;
            break;
        case 2:
            printf("The operation is multiplication.\n");
            result = num1 * num2;
            break;
        case 3:
            printf("The operation is division.\n");
            if(num2 == 0) {
                printf("Error! Division by zero is not allowed.\n");
                return 0;
            }
            result = num1 / num2;
            break;
    }

    printf("The result is: %d\n", result);
    printf("The answer is correct if it is within %d of the correct answer.\n", rand_num);

    if(abs(result - (num1 + num2)) <= rand_num) {
        printf("Congratulations! You got the answer right!\n");
    } else {
        printf("Sorry, your answer is incorrect.\n");
    }

    return 0;
}