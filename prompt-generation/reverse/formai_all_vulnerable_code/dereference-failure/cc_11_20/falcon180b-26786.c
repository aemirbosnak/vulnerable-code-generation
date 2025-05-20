//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_cards = 8, matches = 0, attempts = 0;
    int **deck;
    int choice, value;
    char play_again;

    srand(time(NULL));

    deck = (int **)malloc(num_cards * sizeof(int *));
    for (int i = 0; i < num_cards; i++) {
        deck[i] = (int *)malloc(2 * sizeof(int));
        deck[i][0] = i + 1;
        deck[i][1] = rand() % 100;
    }

    do {
        printf("Welcome to the Memory Game!\n");
        printf("There are %d cards in total.\n", num_cards);

        for (int i = 0; i < num_cards; i++) {
            printf("%d ", deck[i][0]);
        }
        printf("\n");

        for (int i = 0; i < num_cards; i++) {
            deck[i][0] = 0;
            deck[i][1] = rand() % 100;
        }

        attempts = 0;
        while (matches < num_cards) {
            printf("Turn %d\n", ++attempts);

            for (int i = 0; i < num_cards; i++) {
                printf("%d ", deck[i][0]);
            }
            printf("\n");

            printf("Enter your choice: ");
            scanf("%d", &choice);

            if (choice >= 1 && choice <= num_cards) {
                if (deck[choice - 1][0] == 0) {
                    printf("You have already chosen this card.\n");
                } else {
                    printf("You have chosen card %d.\n", deck[choice - 1][0]);
                    if (deck[choice - 1][1] == deck[(choice - 1) / 2][1]) {
                        matches++;
                        printf("Congratulations, you have made a match!\n");
                    } else {
                        printf("Sorry, try again.\n");
                    }
                }
            } else {
                printf("Invalid choice.\n");
            }
        }

        printf("You have made %d matches out of %d turns.\n", matches, attempts);
        printf("Do you want to play again? (y/n) ");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');

    for (int i = 0; i < num_cards; i++) {
        free(deck[i]);
    }
    free(deck);

    return 0;
}