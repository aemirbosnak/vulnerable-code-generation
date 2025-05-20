//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to print a message with a delay
void print_message(const char* message, int delay) {
    for (int i = 0; i < strlen(message); i++) {
        printf("%c", message[i]);
        fflush(stdout);
        usleep(delay * 1000);
    }
}

// Function to prompt the user for a choice
int get_choice(const char* message) {
    int choice;
    printf("%s ", message);
    scanf("%d", &choice);
    return choice;
}

// Function to generate a random number between min and max
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to determine the outcome of a battle
bool battle(int player_strength, int enemy_strength) {
    if (player_strength > enemy_strength) {
        printf("You won the battle!\n");
        return true;
    } else if (player_strength < enemy_strength) {
        printf("You lost the battle.\n");
        return false;
    } else {
        printf("It was a tie.\n");
        return true;
    }
}

// Function to generate a random event
void generate_event() {
    int event_type = rand_int(1, 3);

    switch (event_type) {
        case 1:
            printf("You found a treasure!\n");
            break;
        case 2:
            printf("You encountered an enemy.\n");
            int enemy_strength = rand_int(1, 10);
            int player_strength = rand_int(1, 10);
            battle(player_strength, enemy_strength);
            break;
        case 3:
            printf("Nothing happened.\n");
            break;
    }
}

// Main function
int main() {
    srand(time(NULL));

    printf("Welcome to the Text-Based Adventure Game!\n");

    // Game loop
    while (true) {
        generate_event();

        int choice;
        do {
            choice = get_choice("What do you want to do? (1) Continue, (2) Quit");
        } while (choice!= 1 && choice!= 2);

        if (choice == 2) {
            break;
        }
    }

    return 0;
}