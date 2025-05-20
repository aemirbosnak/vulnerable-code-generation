//FormAI DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 100

int main() {
    int num1, num2, result, answer, choice;
    srand(time(NULL));

    do {
        num1 = rand() % (MAX - MIN + 1) + MIN;
        num2 = rand() % (MAX - MIN + 1) + MIN;

        printf("Choose an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("%d + %d = ", num1, num2);
                result = num1 + num2;
                scanf("%d", &answer);
                if (answer == result) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect! The correct answer is %d\n", result);
                }
                break;
            case 2:
                printf("%d - %d = ", num1, num2);
                result = num1 - num2;
                scanf("%d", &answer);
                if (answer == result) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect! The correct answer is %d\n", result);
                }
                break;
            case 3:
                printf("%d * %d = ", num1, num2);
                result = num1 * num2;
                scanf("%d", &answer);
                if (answer == result) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect! The correct answer is %d\n", result);
                }
                break;
            case 4:
                printf("%d / %d = ", num1, num2);
                result = num1 / num2;
                scanf("%d", &answer);
                if (answer == result) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect! The correct answer is %d\n", result);
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid input, please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}