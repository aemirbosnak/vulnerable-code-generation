//FormAI DATASET v1.0 Category: Table Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user_choice, computer_choice, total_score = 0, computer_score = 0;
    srand(time(NULL));

    printf("Welcome to the C Table Game!\n");

    while(1) {

        printf("\nEnter your choice:\n1) Rock\n2) Paper\n3) Scissors\n4) Quit\n");
        scanf("%d", &user_choice);

        if(user_choice == 4) {
            printf("Thank you for playing! Your total score is %d and the computer's total score is %d.\n", total_score, computer_score);
            break;
        }

        if(user_choice < 1 || user_choice > 3) {
            printf("Invalid input! Please try again.\n");
            continue;
        }

        computer_choice = rand() % 3 + 1;

        switch(user_choice) {
            case 1:
                printf("You chose Rock!\n");
                switch(computer_choice) {
                    case 1:
                        printf("Computer chose Rock too!\n");
                        printf("It's a tie. No points awarded!\n");
                        break;
                    case 2:
                        printf("Computer chose Paper!\n");
                        printf("Computer wins this round!\n");
                        computer_score++;
                        break;
                    case 3:
                        printf("Computer chose Scissors!\n");
                        printf("You win this round!\n");
                        total_score++;
                        break;
                }
                break;
            case 2:
                printf("You chose Paper!\n");
                switch(computer_choice) {
                    case 1:
                        printf("Computer chose Rock!\n");
                        printf("You win this round!\n");
                        total_score++;
                        break;
                    case 2:
                        printf("Computer chose Paper too!\n");
                        printf("It's a tie. No points awarded!\n");
                        break;
                    case 3:
                        printf("Computer chose Scissors!\n");
                        printf("Computer wins this round!\n");
                        computer_score++;
                        break;
                }
                break;
            case 3:
                printf("You chose Scissors!\n");
                switch(computer_choice) {
                    case 1:
                        printf("Computer chose Rock!\n");
                        printf("Computer wins this round!\n");
                        computer_score++;
                        break;
                    case 2:
                        printf("Computer chose Paper!\n");
                        printf("You win this round!\n");
                        total_score++;
                        break;
                    case 3:
                        printf("Computer chose Scissors too!\n");
                        printf("It's a tie. No points awarded!\n");
                        break;
                }
                break;
        }

    }

    return 0;
}