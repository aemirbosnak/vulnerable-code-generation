//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CHOICES 3
#define MAX_ROOMS 5

void display_intro() {
    printf("========================================\n");
    printf("          Haunted House Simulator       \n");
    printf("========================================\n");
    printf("Prepare yourself for a spooky adventure!\n\n");
}

void display_choices(const char *choices[], int num_choices) {
    printf("What would you like to do?\n");
    for (int i = 0; i < num_choices; i++) {
        printf("%d. %s\n", i + 1, choices[i]);
    }
}

int random_event() {
    return rand() % 3; 
}

void room_one() {
    printf("You step into a dark room filled with cobwebs. Suddenly, you hear a scream!\n");
    int event = random_event();
    if (event == 0) {
        printf("A ghost appears! You run away scared!\n");
    } else if (event == 1) {
        printf("You find an old book. It whispers secrets...\n");
    } else {
        printf("The lights flicker and you see a shadow! You must escape quickly!\n");
    }
}

void room_two() {
    printf("You enter a long hallway with portraits that seem to follow you.\n");
    int event = random_event();
    if (event == 0) {
        printf("A portrait of a witch suddenly comes to life! You back away!\n");
    } else if (event == 1) {
        printf("You hear footsteps behind you. It’s just your imagination...\n");
    } else {
        printf("You discover a hidden door! Where does it lead?\n");
    }
}

void room_three() {
    printf("The room is full of strange artifacts. A chilling breeze passes through.\n");
    int event = random_event();
    if (event == 0) {
        printf("An ancient artifact begins to glow! Should you touch it?\n");
    } else if (event == 1) {
        printf("You stumble upon a cursed doll that suddenly opens its eyes!\n");
    } else {
        printf("You find a trapdoor! What could be below?\n");
    }
}

void room_four() {
    printf("This room smells stale, as if it hasn’t been opened in years.\n");
    int event = random_event();
    if (event == 0) {
        printf("A swarm of bats flies out! You duck just in time!\n");
    } else if (event == 1) {
        printf("The walls seem to whisper your name... it is chilling!\n");
    } else {
        printf("You notice a portrait of a man who looks just like you...\n");
    }
}

void room_five() {
    printf("Congratulations! You have found the treasure room!\n");
    printf("Gold coins, spooky trinkets, and riddles await!\n");
    int event = random_event();
    if (event == 0) {
        printf("Suddenly, the treasure turns into a ghostly figure! Help!\n");
    } else if (event == 1) {
        printf("You unlock the secrets of the treasure, becoming rich beyond your dreams!\n");
    } else {
        printf("A riddle appears! Solve it or be cursed forever!\n");
    }
}

void play_game() {
    srand(time(NULL));
    int current_room = 0;
    char *room_names[MAX_ROOMS] = {
        "Enter Room One",
        "Enter Room Two",
        "Enter Room Three",
        "Enter Room Four",
        "Find the Treasure Room"
    };
    
    while (current_room < MAX_ROOMS) {
        display_choices(room_names, MAX_ROOMS);
        printf("Choose your next room (1-5): ");
        int choice;
        scanf("%d", &choice);
        if (choice < 1 || choice > 5) {
            printf("Invalid choice! Choose a number between 1 and 5.\n");
            continue;
        }

        switch (choice) {
            case 1: room_one(); break;
            case 2: room_two(); break;
            case 3: room_three(); break;
            case 4: room_four(); break;
            case 5: room_five(); return; // end game if treasure is found
        }
        current_room++;
    }

    printf("You have escaped the haunted house... for now!\n");
}

int main() {
    display_intro();
    play_game();
    return 0;
}