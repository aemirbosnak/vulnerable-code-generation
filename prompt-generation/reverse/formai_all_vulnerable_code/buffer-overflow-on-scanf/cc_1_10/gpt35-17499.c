//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to welcome the player to the game
void welcome()
{
    printf("Welcome to The Procedural Space Adventure!\n\n");
    printf("In this game, you will navigate through different planets, encounter aliens, and collect resources.\n\n");
    printf("Are you ready to begin your adventure?\n");
}

// Function to display the menu
void menu()
{
    printf("\n\nMENU\n\n");
    printf("1. Travel to a new planet\n");
    printf("2. Encounter an alien\n");
    printf("3. Collect resources\n");
    printf("4. Quit the game\n");
}

// Function to travel to a new planet
void travel()
{
    printf("\n\nTRAVEL\n\n");
    printf("Here are the different planets you can visit:\n\n");
    printf("1. Planet Zorgo\n");
    printf("2. Planet Xandar\n");
    printf("3. Planet Ceti Alpha\n");
    
    // Get user's choice of planet
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("\nYou have traveled to Planet Zorgo!\n");
            break;
        case 2:
            printf("\nYou have traveled to Planet Xandar!\n");
            break;
        case 3:
            printf("\nYou have traveled to Planet Ceti Alpha!\n");
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
    }
}

// Function to encounter an alien
void alien()
{
    printf("\n\nALIEN\n\n");
    printf("You have encountered an alien!\n\n");
    printf("1. Try to communicate with the alien\n");
    printf("2. Fight the alien\n");
    
    // Get user's choice
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("\nYou try to communicate with the alien, but it does not understand you.");
            break;
        case 2:
            printf("\nYou engage in a fierce battle with the alien, but you manage to defeat it.");
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
    }
}

// Function to collect resources
void collect()
{
    printf("\n\nCOLLECT\n\n");
    printf("Here are the resources you can collect:\n\n");
    printf("1. Gold\n");
    printf("2. Silver\n");
    printf("3. Platinum\n");
    
    // Get user's choice of resource
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("\nYou have collected gold!");
            break;
        case 2:
            printf("\nYou have collected silver!");
            break;
        case 3:
            printf("\nYou have collected platinum!");
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
    }
}

int main()
{
    int choice;
    welcome();
    
    while (1) {
        menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                travel();
                break;
            case 2:
                alien();
                break;
            case 3:
                collect();
                break;
            case 4:
                printf("\nGoodbye! Thanks for playing The Procedural Space Adventure!\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }
    
    return 0;
}