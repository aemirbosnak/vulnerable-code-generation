//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, key, light;
    int isDark = 1; // initialize as the house is dark
    int isLocked = 1; // initialize as the house is locked
    srand(time(NULL)); // for generating random number
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are standing in front of a spooky, old house.\n");
    
    while (isLocked) { // loop until the player finds the key
        printf("The house is locked. What do you want to do?\n");
        printf("1. Knock on the door.\n");
        printf("2. Look for a key.\n");
        printf("Choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("You knock on the door, but nobody answers.\n");
        } else if (choice == 2) {
            printf("You start looking for a key...\n");
            if (rand() % 2 == 0) { // randomly generate if the player finds the key
                printf("You found the key!\n");
                isLocked = 0; // unlock the house
            } else {
                printf("You searched everywhere, but couldn't find the key.\n");
            }
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
    
    while (isDark) { // loop until the player turns on the light
        printf("You unlock the door and step inside.\n");
        printf("The house is dark. What do you want to do?\n");
        printf("1. Look for a light switch.\n");
        printf("2. Use a flashlight.\n");
        printf("Choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("You search around and find a light switch.\n");
            printf("Do you want to turn on the light? (1 = Yes, 0 = No): ");
            scanf("%d", &light);
            if (light) { // if the player chooses to turn on the light
                printf("You turn on the light and the house doesn't look as spooky anymore.\n");
                isDark = 0;
            } else {
                printf("You decide to keep the house dark.\n");
            }
        } else if (choice == 2) {
            printf("You turn on your flashlight and start exploring the house.\n");
            isDark = 0; // assume the flashlight is enough and the player doesn't need the light switch
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
    
    printf("You start walking around the house...\n");
    printf("Suddenly, you hear a noise coming from upstairs!\n");
    printf("Do you want to investigate? (1 = Yes, 0 = No): ");
    scanf("%d", &choice);
    if (choice) {
        printf("You go upstairs and see a ghost!\n");
        printf("The ghost asks you to guess a number between 1 and 10.\n");
        key = rand() % 10 + 1; // randomly generate the key the player needs to guess
        printf("Guess the number: ");
        scanf("%d", &choice);
        if (choice == key) { // if the player guesses right
            printf("You guessed right! The ghost disappears and leaves behind the key.\n");
            printf("You pick up the key and started walking towards the door...\n");
        } else { // if the player guesses wrong
            printf("Sorry, you guessed wrong. The ghost disappears and you are stuck in the house forever...\n");
            exit(0); // end the program
        }
    } else {
        printf("You decide not to investigate and started walking towards the door...\n");
    }
    
    printf("You use the key to unlock the door and escape the haunted house. Congratulations!\n");
    
    return 0;
}