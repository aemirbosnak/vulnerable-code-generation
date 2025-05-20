//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void display_intro();
void forest_path();
void choose_action();
void magical_creature();
void solve_puzzle();
int random_event();

int main() {
    srand(time(NULL)); // Seed for random number generation

    display_intro(); // Display introduction
    
    // Start the adventure
    forest_path();

    printf("\nThank you for playing Mystic Forest Enigma! Until next time!\n");
    return 0;
}

void display_intro() {
    printf("=====================================\n");
    printf("       Welcome to Mystic Forest      \n");
    printf("         A Journey of Adventure      \n");
    printf("=====================================\n");
    printf("In this magical forest, you will encounter various creatures,\n");
    printf("solve challenging puzzles, and make choices that will affect\n");
    printf("the outcome of your adventure. Choose wisely and enjoy!\n");
    printf("=====================================\n\n");
}

void forest_path() {
    int choice;
    
    while (1) {
        printf("You find yourself in a beautiful forest. Do you:\n");
        printf("1. Follow the light\n");
        printf("2. Listen to the sounds of the forest\n");
        printf("3. Search for hidden paths\n");
        printf("4. Exit the game\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou follow the light and come across a wise old turtle!\n");
                magical_creature();
                break;
            case 2:
                printf("\nYou discover enchanting melodies guiding you deeper into the forest.\n");
                solve_puzzle();
                break;
            case 3:
                printf("\nYou stumble upon a hidden treasure!\n");
                if (random_event() == 1) {
                    printf("You've found 100 gold coins!\n");
                } else {
                    printf("Alas! It's just a pile of rocks.\n");
                }
                break;
            case 4:
                printf("\nYou have chosen to exit the game. Farewell, brave adventurer!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select a valid option.\n");
                break;
        }
        
        printf("\n------------------------------------------\n\n");
    }
}

void magical_creature() {
    int choice;

    printf("The wise old turtle offers you two choices:\n");
    printf("1. Ask for guidance\n");
    printf("2. Challenge him to a riddle\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nThe turtle shares ancient wisdom to navigate the forest. You feel enlightened!\n");
    } 
    else if (choice == 2) {
        printf("\nTurtle: 'I have a riddle for you: What has keys but can't open locks?'\n");
        char answer[20];
        printf("Your answer: ");
        scanf("%s", answer);
        if (strcmp(answer, "piano") == 0) {
            printf("Correct! The turtle rewards you with a magical amulet!\n");
        } else {
            printf("Incorrect... The turtle chuckles and disappears.\n");
        }
    } 
    else {
        printf("\nInvalid choice! The turtle vanishes into thin air.\n");
    }
}

void solve_puzzle() {
    printf("You encounter a mystical barrier that requires a spell to pass.\n");
    printf("Charm the barrier with the correct spell: 'Abracadabra' or 'Hocuspocus'\n");
    char spell[20];
    printf("Your spell: ");
    scanf("%s", spell);
    if (strcmp(spell, "Abracadabra") == 0) {
        printf("The barrier shimmers and dissolves! You move forward triumphantly!\n");
    } else {
        printf("The barrier remains, and you have to turn back in disappointment.\n");
    }
}

int random_event() {
    return rand() % 2; // Returns either 0 or 1
}