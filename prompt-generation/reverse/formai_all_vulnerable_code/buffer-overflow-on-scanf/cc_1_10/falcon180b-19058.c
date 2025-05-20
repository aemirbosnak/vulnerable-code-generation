//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 100
#define MAX_FORTUNE_LENGTH 100

// Function to generate a random number between min and max (inclusive)
int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random fortune cookie message
char* generate_fortune(void) {
    static char fortunes[NUM_FORTUNES][MAX_FORTUNE_LENGTH] = {
        "You will soon receive a pleasant surprise.",
        "A new opportunity will come your way.",
        "Your hard work will pay off in the end.",
        "You will find happiness in unexpected places.",
        "Success is just around the corner for you.",
        "Your future is bright and full of possibilities.",
        "You will have a lucky day today.",
        "Your dreams will come true if you believe in them.",
        "You will overcome any obstacles in your path.",
        "A friend will offer you valuable advice soon."
    };
    return fortunes[random_int(0, NUM_FORTUNES - 1)];
}

int main(void) {
    srand(time(NULL)); // Seed the random number generator with the current time

    int choice;
    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Please choose an option:\n");
        printf("1. Get a fortune\n2. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Your fortune is: %s\n", generate_fortune());
            break;
        case 2:
            printf("Thank you for using the Automated Fortune Teller!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice!= 2);

    return 0;
}