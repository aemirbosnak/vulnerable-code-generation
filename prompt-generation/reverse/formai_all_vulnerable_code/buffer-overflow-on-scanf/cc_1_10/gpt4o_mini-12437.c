//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10

const char *fortunes[MAX_FORTUNES] = {
    "You will find unexpected wealth today.",
    "A journey of a thousand miles begins with a single step.",
    "Your hard work will soon pay off, stay focused.",
    "An exciting opportunity is heading your way.",
    "Someone will soon share good news with you.",
    "A fresh start will bring you joy, embrace it.",
    "Do not fear change; it is the path to growth.",
    "Love is around the corner, keep your eyes open.",
    "You will gain the respect of many through your actions.",
    "A beautiful soul will cross your path today."
};

void displayHeader() {
    printf("====================================\n");
    printf("        C Automated Fortune Teller   \n");
    printf("====================================\n");
}

void displayFortune() {
    int index = rand() % MAX_FORTUNES;
    printf("Your fortune: %s\n", fortunes[index]);
}

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Get a fortune\n");
    printf("2. Exit\n");
}

int main() {
    srand(time(0)); // Initialize random number generator
    int choice = 0;

    displayHeader();

    while (choice != 2) {
        printMenu();
        printf("Enter your choice (1-2): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFortune();
                break;
            case 2:
                printf("Thank you for visiting the C Automated Fortune Teller. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}