//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_intro() {
    printf("Welcome to the Enchanted Forest!\n");
    printf("In this magical land, you'll embark on a journey filled with wonder, danger, and choices.\n");
    printf("Can you decipher the mysteries and find the hidden treasure?\n\n");
}

void print_choices() {
    printf("You find yourself at a crossroad.\n");
    printf("To your left, a dark path leads into the shadows of the trees.\n");
    printf("To your right, a gleaming light beckons you towards a mysterious hut.\n");
    printf("What will you do?\n");
    printf("1. Take the dark path\n");
    printf("2. Approach the mysterious hut\n");
    printf("Enter your choice (1 or 2): ");
}

int dark_path() {
    printf("\nYou venture down the dark path, and the trees loom ominously above you.\n");
    printf("Suddenly, a wild beast appears!\n");
    printf("You can either:\n");
    printf("1. Run back to the crossroad\n");
    printf("2. Attempt to tame the beast\n");
    printf("Enter your choice (1 or 2): ");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nYou sprint back to safety at the crossroad.\n\n");
        return 0; // Back to choices
    } else {
        printf("\nYou bravely approach the beast, and to your surprise, it calms down.\n");
        printf("You have tamed the beast! It leads you to a hidden treasure chest.\n");
        printf("Congratulations, you have found the treasure!\n");
        return 1; // End the game
    }
}

int mysterious_hut() {
    printf("\nYou walk towards the mysterious hut, and an old sage greets you.\n");
    printf("He offers you a choice:\n");
    printf("1. Ask for wisdom\n");
    printf("2. Steal a potion from the table\n");
    printf("Enter your choice (1 or 2): ");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nYou ask the sage for wisdom. He shares valuable knowledge that will aid you on your journey.\n");
        printf("As a gift, he gives you a magic mirror that reveals the path you should take next.\n");
        printf("You can now venture deeper into the forest with courage!\n");
        return 1; // End the game
    } else {
        printf("\nYou greedily grab a potion, but the sage is not pleased.\n");
        printf("He casts a spell on you, and you become a frog!\n");
        printf("Game over!\n");
        return 1; // End the game
    }
}

int main() {
    print_intro();
    int game_on = 1; // Game state variable

    while(game_on) {
        print_choices();
        
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            game_on = dark_path();
        } else if (choice == 2) {
            game_on = mysterious_hut();
        } else {
            printf("\nInvalid choice! Please choose again.\n");
        }
    }

    printf("Thank you for playing!\n");
    return 0;
}