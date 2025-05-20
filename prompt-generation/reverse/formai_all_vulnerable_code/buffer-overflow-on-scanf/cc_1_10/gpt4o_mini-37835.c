//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void enter_room(int room_number);
void ghost_event();
void puzzle_event();
void treasure_event();
int get_random_event();

int main() {
    srand(time(0)); // Seed the random number generator
    int choice = 0;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are about to enter a spooky mansion filled with surprises.\n\n");

    while (choice != 3) {
        printf("Choose a room to enter (1-3) or exit (3):\n");
        printf("1. Room of Ghouls\n");
        printf("2. Room of Puzzles\n");
        printf("3. Exit the Haunted House\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 3) {
            printf("Invalid choice! Please choose a room between 1 and 3.\n");
            continue;
        }

        if (choice == 3) {
            printf("You have chosen to leave the Haunted House. Goodbye!\n");
            break;
        }

        enter_room(choice);
    }

    return 0;
}

void enter_room(int room_number) {
    printf("\nEntering room %d...\n", room_number);
    int event_id = get_random_event();

    switch (event_id) {
        case 0:
            ghost_event();
            break;
        case 1:
            puzzle_event();
            break;
        case 2:
            treasure_event();
            break;
        default:
            printf("An unknown event occurred! Better be cautious.\n");
            break;
    }
    printf("Exiting room %d...\n\n", room_number);
}

void ghost_event() {
    printf("A ghost appears before you! It moans:\n");
    printf("\"I am the spirit of the house! Solve my riddle to pass!\"\n");
    
    char answer[50];
    printf("Riddle: I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I? ");
    scanf("%s", answer);
    
    if (strcmp(answer, "echo") == 0) {
        printf("The ghost smiles and lets you pass. Well done!\n");
    } else {
        printf("The ghost wails in despair. You have failed the riddle!\n");
    }
}

void puzzle_event() {
    printf("You discover a puzzle box on the table. Solve the puzzle to reveal its secrets!\n");
    
    int guess;
    printf("Enter a number between 1 and 10 (the right number is between 1 and 10): ");
    scanf("%d", &guess);

    if (guess == 7) {
        printf("The box unlocks, revealing a treasure within! You win a sparkling gem!\n");
    } else {
        printf("The box remains closed. You answered incorrectly. Better luck next time!\n");
    }
}

void treasure_event() {
    printf("You stumble upon an old treasure chest! It is covered in dust and cobwebs.\n");
    printf("You carefully open it and find...\n");
    
    int treasure = rand() % 3; // Random treasure

    switch (treasure) {
        case 0:
            printf("a pile of gold coins!\n");
            break;
        case 1:
            printf("an old, mysterious map!\n");
            break;
        case 2:
            printf("a cursed artifact!\n");
            break;
        default:
            printf("nothing but an empty chest.\n");
            break;
    }
    printf("You decide to take your find and leave the haunted room!\n");
}

int get_random_event() {
    return rand() % 3; // Returns a random event type
}