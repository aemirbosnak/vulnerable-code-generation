//FormAI DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, result, answer, score = 0, total = 0, choice;
    char operator;
    srand(time(NULL));

    do {
        printf("Choose an option:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Thank you for playing! Your final score is %d out of %d.\n", score, total);
            break;
        }

        printf("Enter number of questions: ");
        scanf("%d", &num1);

        for (int i = 0; i < num1; i++) {
            num2 = rand() % 50 + 1;
            switch (choice) {
                case 1:
                    operator = '+';
                    result = rand() % 100 + 1;
                    answer = result - num2;
                    break;
                case 2:
                    operator = '-';
                    result = rand() % 100 + num2;
                    answer = result - num2;
                    break;
                case 3:
                    operator = '*';
                    result = rand() % 10 + 1;
                    answer = result * num2;
                    break;
                case 4:
                    operator = '/';
                    result = rand() % 100 + 1;
                    while (num2 == 0 || result % num2 != 0) {
                        num2 = rand() % 50 + 1;
                    }
                    answer = result / num2;
                    break;
                default:
                    printf("Invalid option!\n");
                    break;
            }

            printf("%d %c %d = ", result, operator, num2);
            scanf("%d", &result);

            if (result == answer) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect! The correct answer is %d.\n", answer);
            }

            total++;

            if (i == num1 - 1) {
                printf("You have completed %d questions. Your score is %d out of %d.\n", num1, score, total);
            }
        }
    } while (choice != 5);

    return 0;
}