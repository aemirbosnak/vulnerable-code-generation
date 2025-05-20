//Falcon2-11B DATASET v1.0 Category: Automated Fortune Teller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, roll;
    char name[20];
    srand(time(NULL));

    printf("Welcome to the Fortune Teller!\n");
    printf("Please enter your name:\n");
    scanf("%s", name);

    while (1) {
        printf("What would you like to know? (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Your future is full of love and happiness!\n");
                break;
            case 2:
                printf("You will find great success in your career!\n");
                break;
            case 3:
                printf("You will travel to exotic places and have many adventures!\n");
                break;
            case 4:
                printf("You will find true friendship and love!\n");
                break;
            case 5:
                printf("Your future is full of mystery and excitement!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("Would you like to roll the dice? (y/n): ");
        scanf(" %c", &roll);

        if (roll == 'n')
            break;

        printf("You rolled a %d!\n", rand() % 10 + 1);
    }

    printf("Thank you for using the Fortune Teller! Goodbye!\n");

    return 0;
}