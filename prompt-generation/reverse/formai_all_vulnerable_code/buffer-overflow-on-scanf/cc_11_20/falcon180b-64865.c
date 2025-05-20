//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 0
#define P 1
#define S 2

int main() {
    int choice, result;
    int player_score = 0;
    int computer_score = 0;

    srand(time(NULL));

    printf("Welcome to Rock-Paper-Scissors!\n");
    printf("You will play against the computer.\n");
    printf("Rock beats scissors, scissors beats paper, paper beats rock.\n");
    printf("Let's begin!\n");

    while(1) {
        printf("Choose your move: ");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        scanf("%d", &choice);

        if(choice < 1 || choice > 3) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        result = rand() % 3;

        if(result == R && choice == S) {
            printf("You win! Scissors cuts paper.\n");
            player_score++;
        }
        else if(result == P && choice == R) {
            printf("You win! Paper covers rock.\n");
            player_score++;
        }
        else if(result == S && choice == P) {
            printf("You win! Rock crushes scissors.\n");
            player_score++;
        }
        else if(result == R && choice == P) {
            printf("You lose! Paper covers rock.\n");
            computer_score++;
        }
        else if(result == P && choice == S) {
            printf("You lose! Scissors cuts paper.\n");
            computer_score++;
        }
        else if(result == S && choice == R) {
            printf("You lose! Rock crushes scissors.\n");
            computer_score++;
        }
        else {
            printf("It's a draw!\n");
        }

        if(player_score == 5) {
            printf("You win the game!\n");
            break;
        }
        else if(computer_score == 5) {
            printf("You lose the game.\n");
            break;
        }
    }

    return 0;
}