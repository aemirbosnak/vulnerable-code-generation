//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void start_game();
void play_game();
void end_game();

int main() {
    printf("=====================\n");
    printf("Welcome to Adventure!\n");
    printf("=====================\n\n");
    
    start_game();
    
    return 0;
}

void start_game() {
    char name[20];
    printf("What is your name? ");
    scanf("%s", name);
    printf("Greetings, %s! Let's begin.\n\n", name);
    
    play_game();
}

void play_game() {
    printf("You find yourself in a dark room.\n");
    printf("There are two doors in front of you.\n");
    printf("One is red and one is blue.\n");
    
    int choice;
    printf("Which door do you choose?\n");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You chose the red door.\n");
        printf("You enter a room filled with gold.\n");
        printf("Congratulations, you win!\n");
        
        end_game();
    }
    else if (choice == 2) {
        printf("You chose the blue door.\n");
        printf("You enter a dark room with a monster.\n");
        printf("Uh oh, the monster eats you.\n");
        
        end_game();
    }
    else {
        printf("Invalid choice.\n");
        play_game();
    }
}

void end_game() {
    printf("Would you like to play again? (y/n)\n");
    
    char choice;
    scanf(" %c", &choice);
    
    if (choice == 'y' || choice == 'Y') {
        printf("\n");
        play_game();
    }
    else if (choice == 'n' || choice == 'N') {
        printf("Thanks for playing!\n");
        exit(0);
    }
    else {
        printf("Invalid choice.\n");
        end_game();
    }
}