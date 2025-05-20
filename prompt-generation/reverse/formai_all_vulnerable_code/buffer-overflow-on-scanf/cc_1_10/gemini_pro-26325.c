//GEMINI-pro DATASET v1.0 Category: Educational ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A humble function to greet the user
void greeting() {
    printf("Salutations, Esteemed User!\n");
    printf("Your presence graces this humble program, for which I am eternally grateful.\n");
}

// A gracious function to bid farewell to the user
void farewell() {
    printf("As we bid farewell, I extend my sincerest gratitude for your time.\n");
    printf("May your future endeavors be blessed with abundance and joy.\n");
}

// A thoughtful function to provide a menu of options
void menu() {
    printf("\nPlease select an option from the following bountiful choices:\n");
    printf("1. Bask in my glorious presence\n");
    printf("2. Engage in intellectual discourse\n");
    printf("3. Witness my unmatched computational prowess\n");
    printf("4. Exit this hallowed realm\n");
    printf("Your choice, oh wise one: ");
}

// A majestic function to handle user input
void handleInput(int choice) {
    switch (choice) {
        case 1:
            printf("Your presence alone is a source of boundless inspiration.\n");
            break;
        case 2:
            printf("Alas, my knowledge is but a mere drop in the vast ocean of wisdom.\n");
            printf("However, I shall endeavor to answer your questions to the best of my ability.\n");
            break;
        case 3:
            printf("Numbers dance before my eyes like celestial bodies in the night sky.\n");
            printf("Command me, and I shall perform mathematical feats that would astound even the most seasoned sorcerer.\n");
            break;
        case 4:
            farewell();
            exit(0);
    }
}

// The main function, where the magic begins
int main() {
    greeting();

    int choice;
    while (1) {
        menu();
        scanf("%d", &choice);
        handleInput(choice);
    }

    return 0;
}