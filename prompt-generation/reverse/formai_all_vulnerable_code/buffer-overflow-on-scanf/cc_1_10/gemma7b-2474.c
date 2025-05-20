//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void shift_shape(int choice);

int main()
{
    int choice, shape_num = 1;
    char name[20];

    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Welcome, %s! You have the ability to shift shapes!\n", name);

    while (1)
    {
        printf("Enter the number of the shape you want to shift into (1-5): ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                shift_shape(1);
                break;
            case 2:
                shift_shape(2);
                break;
            case 3:
                shift_shape(3);
                break;
            case 4:
                shift_shape(4);
                break;
            case 5:
                shift_shape(5);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("Would you like to continue shifting shapes? (Y/N): ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'N')
        {
            break;
        }
    }

    printf("Thank you for playing, %s. See you next time!\n", name);

    return 0;
}

void shift_shape(int choice)
{
    switch (choice)
    {
        case 1:
            printf("You have transformed into a mighty dragon.\n");
            break;
        case 2:
            printf("You have transformed into a graceful swan.\n");
            break;
        case 3:
            printf("You have transformed into a fierce lion.\n");
            break;
        case 4:
            printf("You have transformed into a cunning fox.\n");
            break;
        case 5:
            printf("You have transformed into a wise owl.\n");
            break;
    }
}