//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Get ready to receive some amazing predictions!\n\n");

    // Seed the random number generator
    srand(time(0));

    // Loop for multiple fortune telling
    while (1) {
        // Get a random number between 1 and 5
        int fortune_no = rand() % 5 + 1;

        // Display the fortune based on the random number
        switch (fortune_no) {
            case 1:
                printf("You will receive some good news in the near future.\n");
                break;
            case 2:
                printf("A new opportunity will arise that will bring you success.\n");
                break;
            case 3:
                printf("A special someone will enter your life and bring you happiness.\n");
                break;
            case 4:
                printf("You will face some challenges, but you will overcome them with ease.\n");
                break;
            case 5:
                printf("A big change is coming your way - embrace it!\n");
                break;
            default:
                printf("Error: Invalid fortune number.\n");
                break;
        }

        // Ask the user if they want another fortune telling
        printf("\nDo you want another prediction? (y/n) ");
        char response;
        scanf(" %c", &response);

        // If the user doesn't want another fortune telling, exit the loop
        if (response == 'n' || response == 'N') {
            break;
        }

        printf("\n");
    }

    // Goodbye message
    printf("\nThank you for using the Automated Fortune Teller!\n");
    printf("May luck be on your side!\n");

    return 0;
}