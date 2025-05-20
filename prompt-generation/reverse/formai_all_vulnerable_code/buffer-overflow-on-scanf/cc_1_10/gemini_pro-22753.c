//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

typedef struct {
    int value;
    int is_revealed;
} Card;

Card deck[SIZE * SIZE];
int num_revealed = 0;
int attempts = 0;

void shuffle() {
    srand(time(NULL));

    for (int i = 0; i < SIZE * SIZE; i++) {
        deck[i].value = i / 2;
        deck[i].is_revealed = 0;
    }

    for (int i = 0; i < SIZE * SIZE; i++) {
        int j = rand() % (SIZE * SIZE);

        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_board() {
    printf("   ");
    for (int i = 0; i < SIZE; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%2d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (deck[i * SIZE + j].is_revealed) {
                printf("%2d ", deck[i * SIZE + j].value);
            } else {
                printf("░░ ");
            }
        }
        printf("\n");
    }
}

int main() {
    shuffle();

    while (num_revealed < SIZE * SIZE) {
        print_board();

        int x, y;
        printf("Enter the coordinates of the first card (x, y): ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
            printf("Invalid coordinates!\n");
            continue;
        }

        int first_card = deck[x * SIZE + y].value;
        deck[x * SIZE + y].is_revealed = 1;
        num_revealed++;

        printf("Enter the coordinates of the second card (x, y): ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
            printf("Invalid coordinates!\n");
            continue;
        }

        int second_card = deck[x * SIZE + y].value;
        deck[x * SIZE + y].is_revealed = 1;
        num_revealed++;

        attempts++;

        if (first_card == second_card) {
            printf("Correct!\n");
        } else {
            printf("Wrong!\n");

            deck[x * SIZE + y].is_revealed = 0;
            deck[x * SIZE + y].is_revealed = 0;
        }
    }

    print_board();
    printf("Congratulations! You won in %d attempts!\n", attempts);

    return 0;
}