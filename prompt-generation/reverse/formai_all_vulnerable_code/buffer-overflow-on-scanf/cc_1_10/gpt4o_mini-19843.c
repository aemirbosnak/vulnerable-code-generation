//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printFortune(char *fortune) {
    printf("\nYour fortune unfolds:\n");
    printf("\"%s\"\n", fortune);
}

void loveFortune() {
    char *fortunes[] = {
        "Your love shall bloom like the roses of Verona.",
        "Though shadows may fall, love's light shall guide you.",
        "Romeo shall call thy name upon the stars.",
        "Fate entwines your hearts; no distance will sever.",
        "A sweet kiss awaits under the moonlit sky.",
        "Beware the dagger's edge, for love is a double-edged sword."
    };
    int index = rand() % 6;
    printFortune(fortunes[index]);
}

void fateFortune() {
    char *fortunes[] = {
        "The stars conspire to weave thy destiny; trust in their course.",
        "A choice must be made, for fortune favors the brave.",
        "The capulet and montague bloodlines shall intertwine.",
        "You are called to play thy part in this tragic tale.",
        "Destiny whispers of clandestine meetings.",
        "Though the night may be dark, dawn shall break upon thee."
    };
    int index = rand() % 6;
    printFortune(fortunes[index]);
}

void destinyFortune() {
    char *fortunes[] = {
        "The heart knows what the mind fears; embrace your true path.",
        "All the world’s a stage, and you are but a player.",
        "Shared dreams upon sweet whispers shall be your fate.",
        "Carry love in your heart; it shall be your guiding light.",
        "In a world apart, love shall find a way.",
        "Listen close, for the universe holds secrets just for thee."
    };
    int index = rand() % 6;
    printFortune(fortunes[index]);
}

void showMenu() {
    printf("\nWelcome to the Automated Fortune Teller!\n");
    printf("Under the shadows of Romeo and Juliet, the fates await thy choice:\n");
    printf("1. Love\n");
    printf("2. Fate\n");
    printf("3. Destiny\n");
    printf("4. Exit\n");
    printf("Choose thy path (1-4): ");
}

int main() {
    int choice;
    srand(time(NULL));  // Seed for randomness

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                loveFortune();
                break;
            case 2:
                fateFortune();
                break;
            case 3:
                destinyFortune();
                break;
            case 4:
                printf("Parting is such sweet sorrow, till we meet again!\n");
                return 0;
            default:
                printf("Pray, choose a valid path!\n");
        }
    }

    return 0;
}