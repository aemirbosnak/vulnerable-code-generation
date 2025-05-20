//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // sets the seed for random number generation
    
    char name[20];
    printf("Welcome to the Text-Based Adventure Game! Enter your name: ");
    scanf("%s", name);
    
    printf("\nWelcome, %s! You are now in a dark, mysterious forest.\n", name);
    printf("Your objective is to find the treasure chest and escape the forest.\n\n");
    
    // room numbers and objects
    int room1_obj = rand() % 4; // random number between 0 and 3
    int room2_obj = rand() % 4;
    int room3_obj = rand() % 4;
    int room4_obj = rand() % 4;
    int room5_obj = rand() % 4;
    
    printf("You are currently in Room 1. Which direction would you like to go? (North/South/East/West)");
    
    int current_room = 1;
    char direction[6];
    scanf("%s", direction);
    
    while (current_room != 6) {
        if (current_room == 1) {
            if (strcmp(direction, "North") == 0) {
                printf("\nYou are now in Room 2.");
                current_room = 2;
            }
            else if (strcmp(direction, "East") == 0) {
                printf("\nYou are now in Room 3.");
                current_room = 3;
            }
            else if (strcmp(direction, "South") == 0) {
                printf("\nYou are now in Room 4.");
                current_room = 4;
            }
            else if (strcmp(direction, "West") == 0) {
                printf("\nYou are now in Room 5.");
                current_room = 5;
            }
            else {
                printf("\nInvalid direction. Please enter a valid direction: ");
            }
        }
        else if (current_room == 2) {
            printf("\nYou are currently in Room 2. Which direction would you like to go? (South)");
            scanf("%s", direction);
            
            if (strcmp(direction, "South") == 0) {
                printf("\nYou are now in Room 1.");
                current_room = 1;
            }
            else {
                printf("\nInvalid direction. Please enter a valid direction: ");
            }
        }
        else if (current_room == 3) {
            printf("\nYou are currently in Room 3. Which direction would you like to go? (West)");
            scanf("%s", direction);
            
            if (strcmp(direction, "West") == 0) {
                printf("\nYou are now in Room 1.");
                current_room = 1;
            }
            else {
                printf("\nInvalid direction. Please enter a valid direction: ");
            }
        }
        else if (current_room == 4) {
            printf("\nYou are currently in Room 4. Which direction would you like to go? (East)");
            scanf("%s", direction);
            
            if (strcmp(direction, "East") == 0) {
                printf("\nYou are now in Room 1.");
                current_room = 1;
            }
            else {
                printf("\nInvalid direction. Please enter a valid direction: ");
            }
        }
        else if (current_room == 5) {
            printf("\nYou are currently in Room 5. Which direction would you like to go? (North)");
            scanf("%s", direction);
            
            if (strcmp(direction, "North") == 0) {
                printf("\nYou are now in Room 1.");
                current_room = 1;
            }
            else {
                printf("\nInvalid direction. Please enter a valid direction: ");
            }
        }
        
        if (current_room != 6) {
            printf("\nYou are currently in Room %d. Which direction would you like to go? (North/South/East/West)", current_room);
            scanf("%s", direction);
        }
    }
    
    printf("\nCongratulations, %s! You have found the treasure chest and escaped the forest.\n", name);
    
    return 0;
}