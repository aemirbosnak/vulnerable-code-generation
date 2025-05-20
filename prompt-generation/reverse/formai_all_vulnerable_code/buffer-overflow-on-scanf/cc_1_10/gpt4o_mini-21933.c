//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

const char *fortunes[NUM_FORTUNES] = {
    "You will find great success in your endeavors.",
    "A surprise encounter will bring you joy.",
    "Patience will lead you to a fruitful outcome.",
    "Beware of those who hide their true intentions.",
    "A challenge will present an opportunity for growth.",
    "You will travel to a place you've never been before.",
    "An old friend will reach out with good news.",
    "Something unexpected will turn out to be a blessing.",
    "Your hard work will start to pay off.",
    "A chance meeting will change your perspective on life."
};

void displayMenu() {
    printf("====================================\n");
    printf("        Automated Fortune Teller     \n");
    printf("====================================\n");
    printf("1. Read my fortune\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int getRandomFortuneIndex() {
    return rand() % NUM_FORTUNES;
}

void readFortune() {
    int index = getRandomFortuneIndex();
    printf("Your fortune: %s\n", fortunes[index]);
}

void runFortuneTeller() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        if (choice == 1) {
            readFortune();
        } else if (choice == 2) {
            printf("Thank you for using the Automated Fortune Teller!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    runFortuneTeller();
    return 0;
}