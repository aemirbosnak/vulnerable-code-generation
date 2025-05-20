//Code Llama-13B DATASET v1.0 Category: Table Game ; Style: multivariable
#include <stdio.h>

int main() {
    int player1, player2, player3, dealer;
    char choice;
    int sum;

    printf("Welcome to the table game!\n");
    printf("Player 1, choose a number: ");
    scanf("%d", &player1);
    printf("Player 2, choose a number: ");
    scanf("%d", &player2);
    printf("Player 3, choose a number: ");
    scanf("%d", &player3);

    dealer = player1 + player2 + player3;
    sum = player1 + player2 + player3;

    printf("Dealer's number: %d\n", dealer);
    printf("Do you want to 'H'it, 'S'tay, or 'D'ouble down? ");
    scanf(" %c", &choice);

    if (choice == 'H' || choice == 'h') {
        player1 = player1 + 1;
        player2 = player2 + 1;
        player3 = player3 + 1;
        sum = player1 + player2 + player3;
        printf("New sum: %d\n", sum);
    } else if (choice == 'S' || choice == 's') {
        printf("Sum: %d\n", sum);
    } else if (choice == 'D' || choice == 'd') {
        player1 = player1 + 2;
        player2 = player2 + 2;
        player3 = player3 + 2;
        sum = player1 + player2 + player3;
        printf("New sum: %d\n", sum);
    } else {
        printf("Invalid input\n");
    }

    if (sum <= 21) {
        printf("Do you want to 'H'it, 'S'tay, or 'D'ouble down? ");
        scanf(" %c", &choice);

        if (choice == 'H' || choice == 'h') {
            player1 = player1 + 1;
            player2 = player2 + 1;
            player3 = player3 + 1;
            sum = player1 + player2 + player3;
            printf("New sum: %d\n", sum);
        } else if (choice == 'S' || choice == 's') {
            printf("Sum: %d\n", sum);
        } else if (choice == 'D' || choice == 'd') {
            player1 = player1 + 2;
            player2 = player2 + 2;
            player3 = player3 + 2;
            sum = player1 + player2 + player3;
            printf("New sum: %d\n", sum);
        } else {
            printf("Invalid input\n");
        }
    }

    if (sum > 21) {
        printf("Bust!\n");
    } else if (sum == dealer) {
        printf("Push!\n");
    } else if (sum > dealer) {
        printf("You win!\n");
    } else {
        printf("Dealer wins!\n");
    }

    return 0;
}