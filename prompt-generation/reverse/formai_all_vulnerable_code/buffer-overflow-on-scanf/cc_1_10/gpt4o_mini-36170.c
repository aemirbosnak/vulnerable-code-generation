//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printIntroduction() {
    printf("\nWelcome to the Love Quest!\n");
    printf("In this game, you will make choices that determine the outcome of your romantic adventure.\n");
    printf("Each decision will take you closer or further away from winning the heart of your beloved.\n");
    printf("Let's begin!\n\n");
}

int chooseOption(int min, int max) {
    int choice;
    while (1) {
        printf("Make your choice (%d - %d): ", min, max);
        scanf("%d", &choice);
        if (choice >= min && choice <= max) {
            return choice;
        }
        printf("Invalid choice. Please try again.\n");
    }
}

void firstEncounter() {
    printf("You are at a beautiful park where your beloved often comes to read.\n");
    printf("You see them sitting under a big oak tree, lost in a book.\n");
    printf("What will you do?\n");
    printf("1. Approach them and say hello.\n");
    printf("2. Throw a flower gently in their direction.\n");
    printf("3. Sit quietly on a nearby bench and wait for them to notice you.\n");

    int choice = chooseOption(1, 3);
    switch (choice) {
        case 1:
            printf("You approach them, and with a bright smile, you say, 'Hello! What are you reading?' They look up and smile back!\n");
            printf("Your heart races as you share a delightful conversation...\n");
            break;
        case 2:
            printf("The flower gently lands near them. They look up in surprise, and a smile spreads across their face.\n");
            printf("They wave you over and say, 'What a lovely gesture!'\n");
            break;
        case 3:
            printf("You sit quietly, your heart pounding. After a few moments, they glance your way and your eyes meet.\n");
            printf("They smile at you, creating a spark of connection...\n");
            break;
    }
}

void romanticDinner() {
    printf("You have planned a romantic dinner at a cozy restaurant.\n");
    printf("As you arrive, you see your beloved looking stunning.\n");
    printf("What will you do?\n");
    printf("1. Compliment their appearance.\n");
    printf("2. Offer them a heartfelt gift.\n");
    printf("3. Suggest a wine to make the evening special.\n");

    int choice = chooseOption(1, 3);
    switch (choice) {
        case 1:
            printf("You say, 'You look absolutely beautiful tonight.' They blush and thank you, making the night magical.\n");
            break;
        case 2:
            printf("You hand them a carefully chosen gift. Their eyes light up, and they appreciate your thoughtfulness.\n");
            break;
        case 3:
            printf("You suggest a wine and together, you toast to love and adventure. The chemistry is undeniable!\n");
            break;
    }
}

void theChoice() {
    printf("Now it's time for the ultimate decision.\n");
    printf("You have two paths ahead of you:\n");
    printf("1. Propose your feelings and ask them to be yours forever.\n");
    printf("2. Create a beautiful memory and suggest a trip together.\n");

    int choice = chooseOption(1, 2);
    switch (choice) {
        case 1:
            printf("You gather your courage and say, 'I cannot imagine my life without you. Will you be my partner for life?'\n");
            printf("Their eyes widen, and they smile wide, 'Yes, a thousand times yes!'\n");
            printf("You both embrace, overwhelmed with joy.\n");
            break;
        case 2:
            printf("You say, 'How about we go on an adventure together? Just you and me.'\n");
            printf("Their face lights up with excitement, 'I would love that!' You plan an unforgettable trip!\n");
            break;
    }
}

int main() {
    srand(time(NULL));
    printIntroduction();

    firstEncounter();
    romanticDinner();
    theChoice();

    printf("\nThank you for playing Love Quest! May your heart always be bold and adventurous.\n");
    return 0;
}