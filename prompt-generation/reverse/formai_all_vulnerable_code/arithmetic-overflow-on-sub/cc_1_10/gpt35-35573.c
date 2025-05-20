//FormAI DATASET v1.0 Category: Table Game ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    printf("\n\n");
    printf("******************************************\n");
    printf("           Love Table Game\n");
    printf("******************************************\n\n\n");

    printf("Rules of the game:\n");
    printf("1. Each player will choose a number from 1 to 10.\n");
    printf("2. The player with the higher number wins.\n\n");

    srand(time(NULL)); //to generate random numbers for computer's choice

    int player1_choice, player2_choice, computer_choice;
    char player1_name[20], player2_name[20];

    printf("Enter Player 1 name: ");
    scanf("%s", player1_name);

    printf("Enter Player 2 name: ");
    scanf("%s", player2_name);

    printf("\n%s, please choose a number from 1 to 10: ", player1_name);
    scanf("%d", &player1_choice);

    printf("%s, please choose a number from 1 to 10: ", player2_name);
    scanf("%d", &player2_choice);

    printf("\n%s chose %d\n", player1_name, player1_choice);
    printf("%s chose %d\n\n", player2_name, player2_choice);

    computer_choice = rand() % 10 + 1; //random number between 1 and 10
    printf("Computer chose %d\n\n", computer_choice);

    if(player1_choice > player2_choice) {
        printf("%s wins! Congratulations, you have won my heart!\n", player1_name);
    }
    else if(player2_choice > player1_choice) {
        printf("%s wins! Congratulations, you have won my heart!\n", player2_name);
    }
    else {
        printf("It's a tie! Looks like my heart belongs to the computer...\n");
    }

    if(abs(computer_choice - player1_choice) < abs(computer_choice - player2_choice)) {
        printf("Sorry %s, looks like the computer has won my heart...\n", player2_name);
    }
    else if(abs(computer_choice - player2_choice) < abs(computer_choice - player1_choice)) {
        printf("Sorry %s, looks like the computer has won my heart...\n", player1_name);
    }
    else {
        printf("It's a tie! The computer loves us both equally...\n");
    }

    return 0;
}