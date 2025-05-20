//FormAI DATASET v1.0 Category: Math exercise ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayMenu();
void generateQuestion(char *operation, int *num1, int *num2);
void validateAnswer(char operation, int num1, int num2, int answer);

int main()
{
    int choice, num1, num2, ans;
    char operation;

    do {
        displayMenu(); // display menu to user
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateQuestion("+", &num1, &num2); // generate addition question
                ans = num1 + num2;
                validateAnswer('+', num1, num2, ans);
                break;
            case 2:
                generateQuestion("-", &num1, &num2); // generate subtraction question
                ans = num1 - num2;
                validateAnswer('-', num1, num2, ans);
                break;
            case 3:
                generateQuestion("*", &num1, &num2); // generate multiplication question
                ans = num1 * num2;
                validateAnswer('*', num1, num2, ans);
                break;
            case 4:
                printf("Thank you for playing!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}

void displayMenu()
{
    printf("\n********** MATH GAME **********\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Exit\n");
    printf("Please enter your choice: ");
}

// generates a random question based on operation passed in
void generateQuestion(char *operation, int *num1, int *num2)
{
    srand(time(NULL)); // set random seed
    *num1 = rand() % 20; // generate random number between 0 and 19
    *num2 = rand() % 10; // generate random number between 0 and 9

    printf("\nWhat is %d %s %d?\n", *num1, operation, *num2);
    printf("Please enter your answer: ");
}

// validates user answer and displays result
void validateAnswer(char operation, int num1, int num2, int answer)
{
    int userAnswer;
    scanf("%d", &userAnswer);

    if (userAnswer == answer) {
        printf("Correct! %d %c %d = %d\n", num1, operation, num2, answer);
    } else {
        printf("Incorrect. %d %c %d = %d (not %d)\n", num1, operation, num2, answer, userAnswer);
    }
}