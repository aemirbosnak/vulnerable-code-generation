//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 5

void displayGreeting() {
    printf("Hello there! 😊 Welcome to the Automated Fortune Teller!\n");
    printf("Let's unveil the mysteries that lie ahead for you!\n");
    printf("Please enter your name: ");
}

void displayFortunes(char fortunes[MAX_FORTUNES][100]) {
    printf("\nHere are some fortunes to choose from:\n");
    for (int i = 0; i < MAX_FORTUNES; i++) {
        printf("%d. %s\n", i + 1, fortunes[i]);
    }
}

void chooseFortune(char *name, char fortunes[MAX_FORTUNES][100]) {
    int choice;
    printf("\nChoose your fortune by entering a number (1-%d): ", MAX_FORTUNES);
    scanf("%d", &choice);
    
    // Validate the choice
    if (choice < 1 || choice > MAX_FORTUNES) {
        printf("Oops! That number is out of range. Please try again! 🎈\n");
        chooseFortune(name, fortunes); // Recursive call to ask again
    } else {
        printf("\nThank you, %s! Your fortune is:\n%s\n", name, fortunes[choice - 1]);
        printf("May this fortune brighten your day! 🌟\n");
    }
}

int main() {
    char name[50];
    char fortunes[MAX_FORTUNES][100] = {
        "You will find a delightful surprise waiting for you!",
        "Adventure awaits you in the near future.",
        "A wonderful opportunity will come knocking at your door!",
        "Your laughter will light up someone's day today!",
        "Get ready for unexpected joy that will make you smile!"
    };

    srand(time(NULL));  // Seed the random number generator

    displayGreeting();
    fgets(name, sizeof(name), stdin);
    
    // Remove newline character from the input
    name[strcspn(name, "\n")] = 0;

    // Display the fortunes
    displayFortunes(fortunes);
    
    // Let user choose a fortune
    chooseFortune(name, fortunes);

    printf("\nThank you for visiting the Automated Fortune Teller! Come back anytime! 🎉\n");
    return 0;
}