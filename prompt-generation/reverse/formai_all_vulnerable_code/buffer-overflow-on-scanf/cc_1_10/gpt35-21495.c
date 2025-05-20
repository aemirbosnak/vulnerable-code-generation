//FormAI DATASET v1.0 Category: Math exercise ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int a = rand() % 10 + 1;
    int b = rand() % 10 + 1;
    float c = (float) a / b;

    printf("Welcome to the Math Exercise Program!\n");
    printf("You will be given two random numbers from 1 to 10\n");
    printf("Please solve the following expression:\n\n");
    printf("%d / %d = ?\n\n", a, b);

    float ans;
    printf("Your answer: ");
    scanf("%f", &ans);

    if(ans == c) {
        printf("\nCongratulations! Your answer is correct!\n");
    } else {
        printf("\nSorry, your answer is incorrect.\n");
        printf("The correct answer is %.2f\n", c);
    }

    printf("\nWould you like to play again? (y/n)\n");

    char choice;
    scanf(" %c", &choice);

    while(choice == 'y') {

        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        c = (float) a / b;

        printf("\nPlease solve the following expression:\n\n");
        printf("%d / %d = ?\n\n", a, b);

        printf("Your answer: ");
        scanf("%f", &ans);

        if(ans == c) {
            printf("\nCongratulations! Your answer is correct!\n");
        } else {
            printf("\nSorry, your answer is incorrect.\n");
            printf("The correct answer is %.2f\n", c);
        }

        printf("\nWould you like to play again? (y/n)\n");
        scanf(" %c", &choice);
    }

    printf("\nThank you for playing the Math Exercise Program!\n");

    return 0;
}