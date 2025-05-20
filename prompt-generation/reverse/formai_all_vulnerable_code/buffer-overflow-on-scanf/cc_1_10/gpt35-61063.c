//FormAI DATASET v1.0 Category: Math exercise ; Style: modular
/*
 * Sample math exercise program in a modular style
 * Generates random math questions for the user to answer
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ADD 1
#define SUBTRACT 2
#define MULTIPLY 3
#define DIVIDE 4

void generateQuestion(int *a, int *b, int *operator);
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
void displayResult(int result, int answer);

int main()
{
    srand(time(NULL)); // Seed the random number generator

    int a, b, operator, answer, result;
    char choice;

    do {
        generateQuestion(&a, &b, &operator); // Generate a math question
        switch (operator) {
            case ADD:
                result = add(a, b);
                break;
            case SUBTRACT:
                result = subtract(a, b);
                break;
            case MULTIPLY:
                result = multiply(a, b);
                break;
            case DIVIDE:
                result = divide(a, b);
                break;
            default:
                printf("Invalid operator!");
                return 1;
        }

        printf("What is %d ", a);
        switch (operator) {
            case ADD:
                printf("+ ");
                break;
            case SUBTRACT:
                printf("- ");
                break;
            case MULTIPLY:
                printf("* ");
                break;
            case DIVIDE:
                printf("/ ");
                break;
        }
        printf("%d? ", b);
        scanf("%d", &answer);

        displayResult(result, answer); // Display the result

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for playing!");

    return 0;
}

void generateQuestion(int *a, int *b, int *operator)
{
    // Select two random numbers between 1 and 100
    *a = rand() % 100 + 1;
    *b = rand() % 100 + 1;

    // Select a random operator
    *operator = rand() % 4 + 1;
}

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

void displayResult(int result, int answer)
{
    if (result == answer) {
        printf("Correct!\n");
    } else {
        printf("Incorrect! The answer is %d.\n", result);
    }
}