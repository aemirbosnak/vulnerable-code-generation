//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Function to print a message
void print_message(char* msg) {
    printf("%s\n", msg);
}

// Function to get input from the user
char get_input() {
    char input;
    printf("Enter your choice: ");
    scanf("%c", &input);
    return input;
}

// Function to check if the input is a valid choice
int is_valid_choice(char choice) {
    return choice >= 'A' && choice <= 'Z';
}

// Function to move to a different room
void move_to_room(char* current_room, char* target_room) {
    print_message("You move from ");
    print_message(current_room);
    print_message(" to ");
    print_message(target_room);
    print_message(".\n");
}

// Function to examine a room
void examine_room(char* room_desc) {
    print_message("You examine the room and find:\n");
    print_message(room_desc);
}

// Function to start the game
void start_game() {
    char choice;
    print_message("Welcome to the Sherlock Holmes Text-Based Adventure Game!\n\n");
    print_message("You find yourself in a dimly lit room with a single door leading out.\n");
    print_message("What would you like to do?\n");
    print_message("A. Examine the room\n");
    print_message("B. Move to another room\n");
    choice = get_input();

    if (is_valid_choice(choice)) {
        if (choice == 'A') {
            examine_room("A dusty old book on a shelf catches your eye.");
        } else if (choice == 'B') {
            char target_room[50];
            print_message("Enter the name of the room you want to move to: ");
            scanf("%s", target_room);
            move_to_room("this room", target_room);
        } else {
            print_message("Invalid choice.\n");
        }
    } else {
        print_message("Invalid choice.\n");
    }
}

// Main function
int main() {
    start_game();
    return 0;
}