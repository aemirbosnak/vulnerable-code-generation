//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_score = 0, computer_score = 0;
    char choice;

    while (1) {
        system("clear");
        printf("\n\n\n");
        printf("Player Score: %d\n", player_score);
        printf("Computer Score: %d\n", computer_score);
        printf("\n");

        printf("Choose an option:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("4. Quit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("You chose Rock\n");
                int computer_choice = rand() % 3;
                if (computer_choice == 0) {
                    printf("Computer chose Rock\n");
                    computer_score++;
                } else if (computer_choice == 1) {
                    printf("Computer chose Paper\n");
                    player_score++;
                } else {
                    printf("Computer chose Scissors\n");
                }
                break;
            case '2':
                printf("You chose Paper\n");
                computer_choice = rand() % 3;
                if (computer_choice == 0) {
                    printf("Computer chose Rock\n");
                    player_score++;
                } else if (computer_choice == 1) {
                    printf("Computer chose Paper\n");
                } else {
                    printf("Computer chose Scissors\n");
                    computer_score++;
                }
                break;
            case '3':
                printf("You chose Scissors\n");
                computer_choice = rand() % 3;
                if (computer_choice == 0) {
                    printf("Computer chose Rock\n");
                    computer_score++;
                } else if (computer_choice == 1) {
                    printf("Computer chose Paper\n");
                    player_score++;
                } else {
                    printf("Computer chose Scissors\n");
                }
                break;
            case '4':
                printf("Thanks for playing!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}