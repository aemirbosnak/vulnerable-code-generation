//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int num1, num2, operation, result;
    char choice;

    srand(time(NULL));
    num1 = rand() % 100;
    num2 = rand() % 100;

    printf("Welcome to the post-apocalyptic world of arithmetic!\n");
    printf("In this world, you must choose your operation wisely.\n");
    printf("Choose A for addition, S for subtraction, M for multiplication, or D for division.\n");

    scanf("%c", &choice);

    switch(choice) {
        case 'A':
            operation = 1;
            break;
        case 'S':
            operation = 2;
            break;
        case 'M':
            operation = 3;
            break;
        case 'D':
            operation = 4;
            break;
        default:
            printf("Invalid choice. Program terminated.\n");
            return 0;
    }

    switch(operation) {
        case 1:
            result = num1 + num2;
            printf("The result is %d + %d = %d.\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("The result is %d - %d = %d.\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("The result is %d * %d = %d.\n", num1, num2, result);
            break;
        case 4:
            if(num2 == 0) {
                printf("Error: Division by zero is not allowed in this world.\n");
            } else {
                result = num1 / num2;
                printf("The result is %d / %d = %d.\n", num1, num2, result);
            }
            break;
    }

    return 0;
}