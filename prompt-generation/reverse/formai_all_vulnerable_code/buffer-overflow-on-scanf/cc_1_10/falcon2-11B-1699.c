//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display the header of the program
void display_header() {
    printf("Welcome to the Medieval Haunted House Simulator\n");
    printf("--------------------------------------------\n");
    printf("In this simulator, you will enter a medieval haunted house\n");
    printf("and face terrifying creatures and obstacles.\n");
    printf("--------------------------------------------\n");
}

// Function to display the room description
void display_room_description(char* room_name) {
    printf("You enter the %s room. The room is dimly lit and dusty.\n", room_name);
    printf("You hear faint whispers and the sound of footsteps.\n");
    printf("There is a chest in the corner of the room. Do you open it? (y/n)\n");
}

// Function to display the chest content
void display_chest_content() {
    printf("You open the chest and find a rusty key.\n");
    printf("There is a strange symbol etched into the key.\n");
    printf("Do you take the key? (y/n)\n");
}

// Function to display the game over message
void display_game_over() {
    printf("Game over.\n");
    printf("--------------------------------------------\n");
    printf("You were not able to escape the haunted house.\n");
    printf("--------------------------------------------\n");
}

// Main function
int main() {
    display_header();
    char room_name[100];
    strcpy(room_name, "Dungeon");
    display_room_description(room_name);
    display_chest_content();
    char choice[10];
    printf("Enter your choice (y/n): ");
    scanf("%s", choice);
    if (strcmp(choice, "y") == 0) {
        display_chest_content();
    } else if (strcmp(choice, "n") == 0) {
        display_game_over();
    } else {
        printf("Invalid input. Please try again.\n");
        display_room_description(room_name);
        display_chest_content();
    }
    return 0;
}