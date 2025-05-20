//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: grateful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

// Function to print the introduction message
void intro_message(){
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have entered a haunted house filled with horrors!\n");
    printf("The only way to get out alive is to find the hidden key to unlock the front door.\n");
    printf("But beware, for the spirits of the dead roam these halls and seek to claim your soul!\n");
    printf("\n");
}

// Function to print the room description based on input parameter
void print_room_description(int room_number){
    if(room_number == 0) {
        printf("You are in the foyer. The walls are lined with painted portraits of long-dead family members. The air is thick with the scent of cigars and brandy.\n");
    }
    else if(room_number == 1) {
        printf("You are in the dining room. The table is set for a full meal, complete with silverware and fine china. But the food is long gone, replaced by rotting flesh and maggots.\n");
    }
    else if(room_number == 2) {
        printf("You are in the living room. The furniture is covered in dust and cobwebs, but you can still feel the presence of something watching you from the shadows.\n");
    }
    else if(room_number == 3) {
        printf("You are in the kitchen. The smell of cooking food lingers in the air, but the only thing cooking is your own fear.\n");
    }
    else if(room_number == 4) {
        printf("You are in the library. The shelves are lined with dusty books, some of them centuries old. But the most terrifying book of all is the one that is missing from its shelf.\n");
    }
    else if(room_number == 5) {
        printf("You are in the basement. The air is damp and musty, and you can hear the sound of something slithering in the dark.\n");
    }
    else if(room_number == 6) {
        printf("You are in the attic. The air is cold and stale, and you can see shadows moving along the walls.\n");
    }
}

// Function to generate random number (0-6) for the room
int generate_random_room_number(){
    srand(time(0));
    return rand() % 7;
}

// Function to check if the user input is valid
int is_valid_input(char* input){
    if(strlen(input) != 1){
        return 0;
    }
    char valid_inputs[5] = {'N', 'S', 'E', 'W', 'Q'};
    for(int i = 0; i < 5; i++){
        if(*input == valid_inputs[i]){
            return 1;
        }
    }
    return 0;
}

// Function to execute user input action
int execute_action(char action, int current_room, int* has_key){
    int new_room = current_room;
    if(action == 'N') {
        if(current_room == 0) {
            printf("You cannot go that way.\n");
        }
        else {
            new_room = current_room - 1;
            printf("You move to the north room.\n");
        }
    }
    else if(action == 'S') {
        if(current_room == 6) {
            printf("You cannot go that way.\n");
        }
        else {
            new_room = current_room + 1;
            printf("You move to the south room.\n");
        }
    }
    else if(action == 'E') {
        printf("You cannot go that way.\n");
    }
    else if(action == 'W') {
        printf("You cannot go that way.\n");
    }
    else if(action == 'Q') {
        exit(0);
    }

    if(new_room == 5) {
        printf("You've found the key!\n");
        *has_key = 1;
    }
    print_room_description(new_room);
    return new_room;
}

// Main function to play the game
int main(){
    int current_room = generate_random_room_number();
    int has_key = 0;
    char input[64];

    intro_message();
    print_room_description(current_room);

    while (current_room != 0 || has_key == 0) {
        // Get user input
        printf("Enter your choice (N, S, E, W, Q): ");
        scanf("%s", input);

        // Check if input is valid
        if(!is_valid_input(input)){
            printf("Invalid input, please try again.\n");
            continue;
        }

        // Execute user input action
        current_room = execute_action(input[0], current_room, &has_key);
    }

    printf("Congratulations! You have escaped the haunted house!\n");
    return 0;
}