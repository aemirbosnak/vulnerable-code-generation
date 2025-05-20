//FormAI DATASET v1.0 Category: Math exercise ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Program to generate math problems with a twist!

int main() {
    srand(time(NULL));  // Initialize random seed

    int num1, num2, solution, choice, user_ans, correct_ans = 0, incorrect_ans = 0;
    float percentage;

    printf("Welcome to the visionary math exercise program!\n");

    do {
        choice = rand() % 5;  // Generate random problem type

        // Addition problem
        if (choice == 0) {
            num1 = rand() % 100 + 1;
            num2 = rand() % 100 + 1;
            solution = num1 + num2;

            printf("What is the sum of %d and %d?\n", num1, num2);
            printf("Your answer: ");
            scanf("%d", &user_ans);

            if (user_ans == solution) {
                printf("Correct!\n");
                correct_ans++;
            } else {
                printf("Incorrect. The correct answer is %d\n", solution);
                incorrect_ans++;
            }
        }

        // Subtraction problem
        else if (choice == 1) {
            num1 = rand() % 100 + 1;
            num2 = rand() % 100 + 1;

            // Ensure num1 is greater than num2
            if (num1 < num2) {
                int temp = num1;
                num1 = num2;
                num2 = temp;
            }

            solution = num1 - num2;

            printf("What is %d minus %d?\n", num1, num2);
            printf("Your answer: ");
            scanf("%d", &user_ans);

            if (user_ans == solution) {
                printf("Correct!\n");
                correct_ans++;
            } else {
                printf("Incorrect. The correct answer is %d\n", solution);
                incorrect_ans++;
            }
        }

        // Multiplication problem
        else if (choice == 2) {
            num1 = rand() % 10 + 1;
            num2 = rand() % 10 + 1;
            solution = num1 * num2;

            printf("What is %d times %d?\n", num1, num2);
            printf("Your answer: ");
            scanf("%d", &user_ans);

            if (user_ans == solution) {
                printf("Correct!\n");
                correct_ans++;
            } else {
                printf("Incorrect. The correct answer is %d\n", solution);
                incorrect_ans++;
            }
        }

        // Division problem
        else if (choice == 3) {
            num1 = rand() % 100 + 1;
            num2 = rand() % 10 + 1;
            solution = num1 / num2;

            // Ensure that the division is valid, i.e, no remainder
            while (num1 % num2 != 0) {
                num1 = rand() % 100 + 1;
                num2 = rand() % 10 + 1;
                solution = num1 / num2;
            }

            printf("What is %d divided by %d?\n", num1, num2);
            printf("Your answer: ");
            scanf("%d", &user_ans);

            if (user_ans == solution) {
                printf("Correct!\n");
                correct_ans++;
            } else {
                printf("Incorrect. The correct answer is %d\n", solution);
                incorrect_ans++;
            }
        }

        // Random problem
        else {
            num1 = rand() % 100 + 1;
            num2 = rand() % 10 + 1;
            solution = num1 % num2;

            printf("What is %d mod %d?\n", num1, num2);
            printf("Your answer: ");
            scanf("%d", &user_ans);

            if (user_ans == solution) {
                printf("Correct!\n");
                correct_ans++;
            } else {
                printf("Incorrect. The correct answer is %d\n", solution);
                incorrect_ans++;
            }
        }

        // Display score so far
        printf("Score so far: %d correct, %d incorrect\n", correct_ans, incorrect_ans);

        // Check if user wants to continue
        printf("Do you want to continue? (y/n) ");
        char response;
        scanf(" %c", &response);

        if (response == 'n') {
            break;
        }

    } while (1);

    // Calculate percentage of questions answered correctly
    percentage = ((float)correct_ans / (correct_ans + incorrect_ans)) * 100;

    printf("Your final score is %d/%d, which is %.2f%%\n", correct_ans, correct_ans + incorrect_ans, percentage);

    return 0;
}