//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Player {
    char name[50];
    int score;
};

void display_welcome() {
    printf("\nWelcome to the Sherlock Holmes Table Game! \n\n");
}

void display_intro() {
    printf("The game is simple. \n\n");
    printf("You are in a room with a table and a chair. \n\n");
    printf("On the table are three cards, each with a number written on it. \n\n");
    printf("Your task is to pick up the card with the highest number and win the game. \n\n");
    printf("Good luck, detective!\n\n");
}

void display_instructions() {
    printf("Instructions: \n\n");
    printf("- Pick up the card with the highest number. \n\n");
    printf("- If you pick up the wrong card, the game ends and you lose. \n\n");
    printf("- To quit the game, type 'quit' at any time. \n\n");
    printf("- If you are stuck, type 'hint' to get a clue. \n\n");
}

void display_results(int score) {
    printf("Your score: %d \n", score);
}

void display_game_over() {
    printf("\nGame over! \n\n");
}

void play_game() {
    srand(time(NULL));
    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;
    int num3 = rand() % 10 + 1;

    struct Player player = {"Sherlock Holmes", 0};

    display_welcome();
    display_intro();
    display_instructions();

    while(1) {
        printf("\nWhat is your next move? (pickup/hint/quit): ");
        char cmd[50];
        fgets(cmd, 50, stdin);
        cmd[strlen(cmd) - 1] = '\0';

        if(strcmp(cmd, "quit") == 0) {
            break;
        } else if(strcmp(cmd, "hint") == 0) {
            if(player.score == 0) {
                printf("\nYou can't ask for hints yet!\n");
            } else if(player.score == 1) {
                printf("\nYou have already picked up the card with the highest number.\n");
            } else if(player.score == 2) {
                printf("\nYou have already picked up the card with the second highest number.\n");
            } else if(player.score == 3) {
                printf("\nYou have already picked up the card with the third highest number.\n");
            } else {
                printf("\nThe card with the highest number is the one with a number greater than the number you have already picked up.\n");
            }
        } else if(strcmp(cmd, "pickup") == 0) {
            if(player.score == 0) {
                printf("\nYou haven't picked up any cards yet!\n");
            } else if(player.score == 1) {
                printf("\nYou have already picked up the card with the highest number.\n");
            } else if(player.score == 2) {
                printf("\nYou have already picked up the card with the second highest number.\n");
            } else if(player.score == 3) {
                printf("\nYou have already picked up the card with the third highest number.\n");
            } else {
                printf("\nThe card with the highest number is the one with a number greater than the number you have already picked up.\n");
            }
        } else if(strcmp(cmd, "pickup")!= 0 && strcmp(cmd, "hint")!= 0 && strcmp(cmd, "quit")!= 0) {
            printf("\nInvalid command. \n");
        } else {
            printf("\nInvalid command. \n");
        }
    }

    display_game_over();
    display_results(player.score);
}

int main() {
    play_game();
    return 0;
}