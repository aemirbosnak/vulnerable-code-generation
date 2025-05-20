//FormAI DATASET v1.0 Category: Table Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_rounds, user_score = 0, comp_score = 0, round_num = 1;
    char user_choice, comp_choice;
    srand(time(NULL)); // seeding the random number generator with current time

    printf("***Welcome to the C Table Game***\n\n");
    printf("How many rounds do you want to play? ");
    scanf("%d", &num_rounds);

    while (round_num <= num_rounds) {
        printf("\nRound %d:\n", round_num);

        // getting user's choice
        printf("Enter your choice ('R' for rock, 'P' for paper, 'S' for scissors): ");
        scanf(" %c", &user_choice);

        // generating computer's choice
        int rand_num = rand() % 3; // generates a random number between 0 and 2
        if (rand_num == 0) {
            comp_choice = 'R';
        } else if (rand_num == 1) {
            comp_choice = 'P';
        } else {
            comp_choice = 'S';
        }

        // printing the choices
        printf("You chose %c, and the computer chose %c.\n", user_choice, comp_choice);

        // calculating the round result
        if (user_choice == comp_choice) {
            printf("It's a tie!\n");
        } else if ((user_choice == 'R' && comp_choice == 'S') ||
                   (user_choice == 'P' && comp_choice == 'R') ||
                   (user_choice == 'S' && comp_choice == 'P')) {
            printf("You win this round!\n");
            user_score++;
        } else {
            printf("The computer wins this round!\n");
            comp_score++;
        }

        round_num++;
    }

    // printing the final result
    printf("\n***Game Over***\n");
    printf("You scored %d points, and the computer scored %d points.\n", user_score, comp_score);
    if (user_score > comp_score) {
        printf("Congratulations, you win the game!\n");
    } else if (user_score < comp_score) {
        printf("Sorry, the computer wins the game!\n");
    } else {
        printf("It's a tie game!\n");
    }

    return 0;
}