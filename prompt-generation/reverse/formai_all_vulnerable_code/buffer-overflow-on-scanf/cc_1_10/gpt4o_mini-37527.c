//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

// Function prototypes
void show_intro();
void explore();
void choose_path();
void encounter(char *path);
void check_alive(int *health);
void end_game(int ending);
void print_health(int health);

int main() {
    srand(time(NULL));
    show_intro();
    explore();
    return 0;
}

void show_intro() {
    printf("===================================\n");
    printf("     The Shadows of Gloom\n");
    printf("===================================\n");
    printf("You awaken in a dark forest...\n");
    printf("The trees are towering above you, twisted and sinister.\n");
    printf("You feel an unsettling presence, as if something is watching...\n");
    printf("What will you do?\n");
    printf("===================================\n");
}

void explore() {
    int health = 100;
    
    printf("You must find a way to escape this dreadful place.\n");
    printf("Do you dare to enter the Forbidden Path or the Haunted Grove?\n");

    while (health > 0) {
        choose_path();
        health -= rand() % 20;  // Random damage for choosing a path
        check_alive(&health);
    }

    printf("You collapsed from your injuries. Darkness engulfs you.\n");
    end_game(0);
}

void choose_path() {
    char path[MAX_LENGTH];
    
    printf("Enter 'forbidden' for the Forbidden Path or 'haunted' for the Haunted Grove: ");
    scanf("%s", path);

    if (strcmp(path, "forbidden") == 0) {
        encounter("Forbidden Path");
    } else if (strcmp(path, "haunted") == 0) {
        encounter("Haunted Grove");
    } else {
        printf("That path doesn't exist in this realm. Try again...\n");
    }
}

void encounter(char *path) {
    printf("You venture into the %s...\n", path);
    
    if (strcmp(path, "Forbidden Path") == 0) {
        printf("The air grows thick with despair. An ominous figure appears!\n");
        printf("It's a Gloom Wraith! You must face it!\n");
    } else if (strcmp(path, "Haunted Grove") == 0) {
        printf("Whispers echo around you. Ghostly apparitions dance in the shadows!\n");
        printf("You feel their chill creeping into your bones...\n");
    }
    
    int event = rand() % 3; // Random event (fight, flee, find treasure)
    
    switch (event) {
        case 0:
            printf("You decided to battle!\n");
            break;
        case 1:
            printf("You chose to flee!\n");
            break;
        case 2:
            printf("You found an ancient treasure!\n");
            break;
    }
}

void check_alive(int *health) {
    if (*health <= 0) {
        printf("You have no strength left to proceed!\n");
    } else {
        print_health(*health);
    }
}

void print_health(int health) {
    printf("Current Health: %d\n", health);
    // Could add more health-related mechanics or items here
}

void end_game(int ending) {
    printf("===================================\n");
    
    if (ending == 1) {
        printf("You escaped the shadows! You are safe for now.\n");
    } else {
        printf("You succumbed to the darkness. The forest has consumed you.\n");
    }
    
    printf("Game Over\n");
    printf("===================================\n");
    exit(0);
}