//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the Quirky Quiz System!\n");
    printf("Please select an option:\n");
    printf("1. Take a Quiz\n");
    printf("2. View High Scores\n");
    printf("3. Exit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            system("clear");
            printf("Here are the questions:\n");
            printf("1. What is the capital of France?\n");
            printf("a. Paris\n");
            printf("b. Rome\n");
            printf("c. Berlin\n");

            char answer;
            scanf(" %c", &answer);

            if (answer == 'a')
            {
                printf("Congratulations! You answered correctly.\n");
            }
            else
            {
                printf("Sorry, that is the wrong answer.\n");
            }
            break;

        case 2:
            system("clear");
            printf("Here are the high scores:\n");
            printf("1. John Doe - 100 points\n");
            printf("2. Jane Doe - 90 points\n");
            printf("3. Bill Smith - 80 points\n");
            break;

        case 3:
            system("clear");
            printf("Thank you for playing! Goodbye!\n");
            exit(0);

        default:
            printf("Invalid selection. Please try again.\n");
            break;
    }

    return 0;
}