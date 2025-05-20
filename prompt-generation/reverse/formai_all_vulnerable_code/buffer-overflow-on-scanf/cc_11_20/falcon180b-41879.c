//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0, computer_score = 0;
    char player_choice, computer_choice;
    int flag = 0;

    printf("Welcome to Rock Paper Scissors!\n");
    printf("You will be playing against the computer.\n");
    printf("Type 'r' for Rock, 'p' for Paper, and's' for Scissors.\n");

    while(flag == 0) {
        printf("Enter your choice: ");
        scanf("%c", &player_choice);

        if(player_choice == 'r' || player_choice == 'p' || player_choice =='s') {
            flag = 1;
        } else {
            printf("Invalid input. Please enter again.\n");
        }
    }

    srand(time(NULL));
    int computer_int = rand() % 3;

    if(computer_int == 0) {
        computer_choice = 'r';
    } else if(computer_int == 1) {
        computer_choice = 'p';
    } else {
        computer_choice ='s';
    }

    printf("\nComputer's choice: %c\n", computer_choice);

    if(player_choice == computer_choice) {
        printf("It's a tie!\n");
    } else if((player_choice == 'r' && computer_choice == 'p') ||
               (player_choice == 'p' && computer_choice =='s') ||
               (player_choice =='s' && computer_choice == 'r')) {
        printf("You win!\n");
        player_score++;
    } else {
        printf("You lose!\n");
        computer_score++;
    }

    printf("Score: You - %d, Computer - %d\n", player_score, computer_score);

    return 0;
}