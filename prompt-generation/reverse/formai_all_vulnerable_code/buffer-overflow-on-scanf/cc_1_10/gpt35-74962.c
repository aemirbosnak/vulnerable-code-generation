//FormAI DATASET v1.0 Category: Dice Roller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int generateRandomNumber(int min, int max) {
    int randomNumber = 0;
    srand(time(NULL));
    randomNumber = (rand() % (max - min + 1)) + min;
    return randomNumber;
}

// Main function
int main() {
    int minNumber = 1, maxNumber = 6;
    int userInput, count = 0;
    char answer;

    printf("Welcome to the Dice Roller Program\n\n");
    printf("Press Enter to Roll the Dice!\n");
    scanf("%c", &answer);
    
    // Check if the user wants to roll the dice
    while (answer == '\n') {
        userInput = generateRandomNumber(minNumber, maxNumber);
        printf("Result of Roll %d: ", count + 1);
        
        // Print the corresponding output for the dice roll
        switch(userInput) {
            case 1:
                printf("One\n");
                break;
            case 2:
                printf("Two\n");
                break;
            case 3:
                printf("Three\n");
                break;
            case 4:
                printf("Four\n");
                break;
            case 5:
                printf("Five\n");
                break;
            case 6:
                printf("Six\n");
                break;
        }
        
        count++;
        printf("Roll Again? (Press Enter): ");
        scanf("%c", &answer);
    }

    printf("\nThanks for playing the Dice Roller Program!\n");
    return 0;
}