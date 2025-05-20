//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to add two numbers with a funny message
void add(int a, int b) {
    printf("\033[1;31m%d is having a party at his place!%s\n", a, " But suddenly, ");
    printf("another number, %d, crashes the party!%s\n", b);
    printf("They decide to add their weights (numbers) to check the total capacity of the venue:%s\n", " So, the total is:");
    printf("\033[1;34m%d + %d = %d\033[1;m\n", a, b, a + b);
}

// Function to subtract two numbers with a funny message
void subtract(int a, int b) {
    printf("\033[1;31m%d is feeling sad because he has only %d cookies left.%s\n", a, a, " Suddenly, his friend shows up with ");
    printf("%d cookies.%s\n", b, " Now, %d has:");
    printf("\033[1;34m%d - %d = %d\033[1;m\n", a, b, a - b);
}

// Function to multiply two numbers with a funny message
void multiply(int a, int b) {
    printf("\033[1;31m%d is a very lonely number,%s\n", a, " He wants a friend so badly that he decides to multiply himself by ");
    printf("%d.%s\n", b, " Now, %d has a lot of friends!", a * b);
}

// Function to divide two numbers with a funny message
void divide(int a, int b) {
    printf("\033[1;31m%d is a very generous number,%s\n", a, " He decides to share himself with %d.%s\n", b, " Now, each one gets:");
    printf("\033[1;34m%d / %d = %d\033[1;m\n", a, b, a / b);
}

int main() {
    srand(time(NULL));

    int num1, num2;

    printf("Welcome to the Fun Math Adventure!%s\n", "\nLet's explore the wonderful world of numbers and their magical operations!");

    num1 = rand_num(1, 100);
    num2 = rand_num(1, num1 / 2); // Make sure the second number is smaller than the first one

    int choice;

    do {
        printf("\033[1;33mChoose an operation: add(1), subtract(2), multiply(3), or divide(4)?\033[1;m");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add(num1, num2);
                break;
            case 2:
                subtract(num1, num2);
                break;
            case 3:
                multiply(num1, num2);
                break;
            case 4:
                divide(num1, num2);
                break;
            default:
                printf("\033[1;31mInvalid choice! Try again!\033[1;m\n");
        }

        printf("Do you want to try another operation? (1 for yes, 0 for no)\n");
        scanf("%d", &choice);

    } while (choice == 1);

    printf("\033[1;31mThank you for joining the Fun Math Adventure!%s\n", " See you next time!\n");

    return 0;
}