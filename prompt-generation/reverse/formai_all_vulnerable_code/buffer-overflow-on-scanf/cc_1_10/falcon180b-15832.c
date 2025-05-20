//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print a string with a delay
void print_delayed(const char *str) {
    for (int i = 0; str[i]!= '\0'; i++) {
        printf("%c", str[i]);
        fflush(stdout);
        usleep(100000); // 100ms delay
    }
}

// Function to generate a random number between min and max
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to display the current room description
void look(char *room_name) {
    printf("You are in %s.\n", room_name);
}

// Function to handle user input
void process_input(char *input) {
    char *token = strtok(input, " ");
    if (token == NULL)
        return;

    if (strcmp(token, "look") == 0) {
        token = strtok(NULL, " ");
        look(token);
    } else {
        printf("I'm sorry, I don't understand that command.\n");
    }
}

// Main game loop
int main() {
    srand(time(NULL));

    // Initialize game state
    char player_name[20];
    printf("What is your name? ");
    scanf("%s", player_name);
    printf("Welcome to the game, %s!\n\n", player_name);

    int health = 100;
    int score = 0;
    char current_room[50] = "You wake up in a dark, cold dungeon. The air is damp and musty. There are no windows or doors, only solid stone walls. A single torch flickers on the wall, casting eerie shadows around the room.";

    while (health > 0) {
        system("clear"); // Clear the console
        look(current_room);

        printf("\n> ");
        fflush(stdout);
        char input[100];
        fgets(input, sizeof(input), stdin);
        process_input(input);
    }

    return 0;
}