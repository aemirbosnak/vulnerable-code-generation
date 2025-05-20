//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randNum, choice;
    char input[100];

    // Initialize random number generator
    srand(time(NULL));

    // Generate a random number between 1 and 100
    randNum = rand() % 100 + 1;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I will predict your future based on your choices.\n\n");

    while (1) {
        printf("What do you want to know about your future?\n");
        printf("1. Career\n");
        printf("2. Love\n");
        printf("3. Wealth\n");
        printf("4. Health\n");
        printf("5. Quit\n");
        printf("Enter your choice (1-5): ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                printf("Your career will be filled with challenges, but you will overcome them all.\n");
                printf("You will achieve great success in your chosen field.\n");
                break;
            case 2:
                printf("You will find true love in the most unexpected place.\n");
                printf("Your relationship will be filled with passion and happiness.\n");
                break;
            case 3:
                printf("You will become wealthy beyond your wildest dreams.\n");
                printf("You will have everything you could ever want or need.\n");
                break;
            case 4:
                printf("You will live a long and healthy life.\n");
                printf("You will be surrounded by loved ones who care about you.\n");
                break;
            case 5:
                printf("Thank you for using the Automated Fortune Teller!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }

        printf("\nDo you want to know more about your future? (y/n): ");
        scanf(" %s", input);

        if (input[0] == 'y' || input[0] == 'Y') {
            continue;
        } else {
            break;
        }
    }

    return 0;
}