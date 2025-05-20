//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000

int main() {
    int num1, num2, result;
    char choice;

    srand(time(NULL));
    num1 = rand() % MAX_NUM + 1;
    num2 = rand() % MAX_NUM + 1;

    printf("Welcome to the Medieval Public-Key Algorithm!\n");
    printf("Two knights, Sir Addition and Sir Multiplication,\n");
    printf("have embarked on a quest to find the Holy Grail of Mathematics.\n");
    printf("They must use their unique skills to unlock the secrets of the grail.\n");

    do {
        printf("\nSir Addition:\n");
        printf("I can add two numbers together.\n");
        printf("Would you like me to add %d and %d? (y/n): ", num1, num2);
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            result = num1 + num2;
            printf("\nThe sum of %d and %d is: %d\n", num1, num2, result);
        } else {
            printf("\nVery well, I shall not add these numbers.\n");
        }

        printf("\nSir Multiplication:\n");
        printf("I can multiply two numbers together.\n");
        printf("Would you like me to multiply %d and %d? (y/n): ", num1, num2);
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            result = num1 * num2;
            printf("\nThe product of %d and %d is: %d\n", num1, num2, result);
        } else {
            printf("\nVery well, I shall not multiply these numbers.\n");
        }

        printf("\nWould you like to continue the quest? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}