//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_cards, cards_drawn, choice, fate;
    char name[20];

    printf("Welcome, traveler. Please enter your name: ");
    scanf("%s", name);

    printf("Would you like to draw a card (1/2)? ");
    scanf("%d", &choice);

    if (choice == 1) {
        num_cards = rand() % 3 + 1;
        cards_drawn = num_cards;
    } else if (choice == 2) {
        num_cards = rand() % 2 + 1;
        cards_drawn = num_cards;
    } else {
        printf("Invalid input. Please try again.");
        return 1;
    }

    fate = rand() % 10 + 1;

    switch (fate) {
        case 1:
            printf("Your fate is sealed. Prepare for misfortune.");
            break;
        case 2:
            printf("The stars are aligned in your favor. Expect good fortune.");
            break;
        case 3:
            printf("Beware of the dark forces. They are watching you.");
            break;
        case 4:
            printf("Love and prosperity await you. Prepare for joy.");
            break;
        case 5:
            printf("You will face challenges, but ultimately triumph. Don't give up.");
            break;
    }

    printf("\nThe cards drawn were: ");
    for (int i = 0; i < cards_drawn; i++) {
        printf("Card %d: ", i + 1);
        switch (rand() % 4) {
            case 0:
                printf("Ace\n");
                break;
            case 1:
                printf("Two\n");
                break;
            case 2:
                printf("Three\n");
                break;
            case 3:
                printf("Four\n");
                break;
        }
    }

    printf("\nThank you for visiting the Oracle, %s. May your future be bright.", name);

    return 0;
}