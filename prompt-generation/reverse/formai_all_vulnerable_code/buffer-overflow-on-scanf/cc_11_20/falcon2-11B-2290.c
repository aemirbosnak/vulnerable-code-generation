//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initialize variables
    char name[50];
    char age[5];
    char gender[5];
    char favorite_color[15];
    char favorite_food[15];
    char scariest_memory[50];
    
    // Prompt user for information
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Please enter your name:\n");
    scanf("%s", name);
    
    printf("How old are you?\n");
    scanf("%s", age);
    
    printf("What is your gender? (M/F)\n");
    scanf(" %s", gender);
    
    printf("What is your favorite color?\n");
    scanf("%s", favorite_color);
    
    printf("What is your favorite food?\n");
    scanf("%s", favorite_food);
    
    printf("What is your scariest memory?\n");
    scanf("%s", scariest_memory);
    
    // Create Haunted House Simulator
    int house_size = 10;
    int start_room = 1;
    int current_room = 1;
    int path[house_size][house_size];
    
    // Populate Haunted House Simulator with rooms
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself standing in front of a large, old house.\n");
    printf("There are %d rooms in this house, numbered from 1 to %d.\n", house_size, house_size);
    
    // Initialize current_room to 1
    current_room = 1;
    
    // Display instructions
    printf("Type 'n' to move north,'s' to move south, 'e' to move east, 'w' to move west, 'q' to quit.\n");
    
    // Main game loop
    while (1) {
        // Display current room
        printf("You are in room %d.\n", current_room);
        
        // Display path
        printf("Your path so far is: ");
        for (int i = 0; i < house_size; i++) {
            for (int j = 0; j < house_size; j++) {
                if (path[i][j] == 1) {
                    printf("%d ", i + 1);
                }
            }
            printf("\n");
        }
        printf("\n");
        
        // Get user input
        char direction;
        printf("Enter your next move: ");
        scanf(" %c", &direction);
        
        // Handle user input
        if (direction == 'n') {
            // Move north
            printf("You move north into room %d.\n", current_room + 1);
            path[current_room][current_room + 1] = 1;
        } else if (direction =='s') {
            // Move south
            printf("You move south into room %d.\n", current_room - 1);
            path[current_room][current_room - 1] = 1;
        } else if (direction == 'e') {
            // Move east
            printf("You move east into room %d.\n", current_room + house_size);
            path[current_room][current_room + house_size] = 1;
        } else if (direction == 'w') {
            // Move west
            printf("You move west into room %d.\n", current_room - house_size);
            path[current_room][current_room - house_size] = 1;
        } else if (direction == 'q') {
            // Quit the game
            break;
        } else {
            // Invalid input
            printf("Invalid input. Please try again.\n");
        }
        
        // Check if the user has exited the Haunted House Simulator
        if (current_room == house_size) {
            printf("You have escaped the Haunted House Simulator!\n");
            break;
        }
    }
    
    // Clean up
    printf("Thank you for playing the Haunted House Simulator!\n");
    printf("Have a nice day!\n");
    
    return 0;
}