//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the entered code is correct or not
int check_code(char *entered_code, char *correct_code) {
    if (strcmp(entered_code, correct_code) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char correct_code[] = "BOSHACKS2021"; // The correct code that needs to be entered
    char entered_code[20]; // The code entered by the user
    
    // Clear the terminal screen
    system("clear");
    
    // Display a welcome message
    printf("Welcome to Paranoid Game! You need to enter the correct code to proceed.\n\n");

    // Loop until the correct code is entered
    while (1) {
        // Get the user input for the code
        printf("Enter the code: ");
        scanf("%s", entered_code);

        // Check if the code entered is correct
        if (check_code(entered_code, correct_code)) {
            break;
        } else {
            // Display a warning message
            printf("\nIncorrect code! Try again.\n");
        }
    }

    // If the code is correct, display the main game screen
    printf("\n===============================");
    printf("\n========Paranoid Game==========");
    printf("\n===============================\n\n");
    printf("Welcome to Paranoid Game! You are in a room and all the doors are locked.\n");
    printf("You have to find the key to unlock the doors and escape from this room.\n");
    printf("You have only 10 minutes to escape before the room explodes!\n\n");

    // Randomly select the key's location
    int key_location = rand() % 3 + 1;
    int option;

    // Print the three doors for the user to select
    printf("There are 3 doors in the room. Which door do you want to choose?\n");
    printf("1. Door 1\n");
    printf("2. Door 2\n");
    printf("3. Door 3\n");

    // Get the user input for the door selection
    scanf("%d", &option);

    // Check if the selected door has the key or not
    if (option == key_location) {
        printf("\nYou found the key! You have unlocked the doors and escaped from the room.\n");
        printf("Congratulations! You have won the game!\n");
    } else {
        printf("\nSorry, wrong door! The room exploded and you lost the game!\n");
    }

    return 0;
}