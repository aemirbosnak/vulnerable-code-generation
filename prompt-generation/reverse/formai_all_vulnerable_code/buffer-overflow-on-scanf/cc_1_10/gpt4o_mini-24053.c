//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 10
#define MAX_INPUT 256

// Function to get the user's name
void getUserName(char *name) {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    fgets(name, MAX_INPUT, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character
}

// Function to display a random fortune
void displayFortune(char *name, char *fortunes[], int numFortunes) {
    srand(time(NULL)); // Seed random number generator
    int index = rand() % numFortunes; // Get random index
    printf("\nHello, %s!\n", name);
    printf("Your fortune is: %s\n", fortunes[index]);
}

// Function to provide a selection of fortunes
void generateFortunes(char *fortunes[]) {
    fortunes[0] = "You will find great wealth!";
    fortunes[1] = "A surprise is waiting for you.";
    fortunes[2] = "Love is around the corner.";
    fortunes[3] = "Success is on its way.";
    fortunes[4] = "An old friend will contact you.";
    fortunes[5] = "You will embark on a new adventure.";
    fortunes[6] = "Good news will come to you soon.";
    fortunes[7] = "You will gain the respect of your peers.";
    fortunes[8] = "A brilliant idea will lead to success.";
    fortunes[9] = "You will discover something amazing about yourself.";
}

int main() {
    char name[MAX_INPUT];
    char *fortunes[MAX_FORTUNES];

    // Generate fortunes
    generateFortunes(fortunes);

    // Get the user's name
    getUserName(name);

    // Display the fortune
    displayFortune(name, fortunes, MAX_FORTUNES);

    // Asking if the user wants another fortune
    char another;
    printf("Do you want to hear another fortune? (y/n): ");
    scanf(" %c", &another); // Space before %c to consume any newline
    while (another == 'y' || another == 'Y') {
        displayFortune(name, fortunes, MAX_FORTUNES);
        printf("Do you want to hear another fortune? (y/n): ");
        scanf(" %c", &another);
    }

    printf("Thank you for visiting the Automated Fortune Teller, %s!\n", name);
    printf("May your future be bright!\n");

    return 0;
}