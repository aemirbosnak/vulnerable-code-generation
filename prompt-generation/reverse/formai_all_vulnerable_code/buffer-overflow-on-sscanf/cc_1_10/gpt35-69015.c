//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 50

// Function to get user input
void get_input(char *input) {
    printf("> ");
    fgets(input, MAX_LENGTH, stdin);
    // remove newline character
    input[strcspn(input, "\n")] = 0;
}

int main() {
    char name[MAX_LENGTH];
    char input[MAX_LENGTH];
    int choice = 0;
    int health = 100;
    
    printf("Welcome to the Adventure Game!\n\n");
    
    printf("Please enter your name: ");
    fgets(name, MAX_LENGTH, stdin);
    // remove newline character
    name[strcspn(name, "\n")] = 0;
    
    printf("\n%s, you find yourself in a dark room and you don't know how you got here,", name);
    printf("\nbut you see a door in front of you and a window to your left.\n");
    
    while (health > 0) {
        printf("\nWhat do you do?\n");
        printf("1. Try to open the door\n");
        printf("2. Go to the window\n");
        printf("3. Wait and see what happens\n");
        
        get_input(input);
        sscanf(input, "%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\nThe door is locked and won't budge.\n");
                break;
            case 2:
                printf("\nYou look out the window and see a vast forest in the distance.\n");
                printf("There doesn't seem to be any way to climb out though.\n");
                break;
            case 3:
                printf("\nYou wait for a while and suddenly the floor opens up beneath you.\n");
                printf("You fall into a deep pit.\n");
                health -= 50;
                break;
            default:
                printf("\nInvalid input. Try again.\n");
                break;
        }
        
        if (health == 0) {
            printf("\nGame over. You have died.\n");
            break;
        }
        
        printf("\nYour health is now %d.\n", health);
    }
    
    return 0;
}