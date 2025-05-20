//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the game menu
void print_menu() {
    printf("\nGame Menu:\n");
    printf("1. Start Game\n");
    printf("2. Quit\n");
}

// Function to get user input
int get_input() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to check if user wins the game
int check_win() {
    return rand_num(1, 10) == 7;
}

// Function to play the game
void play_game() {
    int roll, win = 0;
    printf("Welcome to the game!\n");
    while (!win) {
        roll = rand_num(1, 6);
        printf("You rolled a %d.\n", roll);
        if (roll == 6) {
            printf("You won the game!\n");
            win = 1;
        } else {
            printf("Do you want to roll again? (y/n): ");
            char answer;
            scanf(" %c", &answer);
            if (answer == 'y' || answer == 'Y') {
                continue;
            } else {
                break;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int choice;
    do {
        print_menu();
        choice = get_input();
        switch (choice) {
            case 1:
                play_game();
                break;
            case 2:
                printf("Thanks for playing!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 2);
    return 0;
}