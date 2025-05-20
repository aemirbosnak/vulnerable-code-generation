//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_TURNS 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void play_game(Node* head) {
    int current_turn = 0;
    int guess_number;
    time_t start_time, end_time;

    start_time = time(NULL);

    while (current_turn < MAX_NUM_TURNS) {
        printf("Enter your guess: ");
        scanf("%d", &guess_number);

        if (guess_number == head->data) {
            printf("Congratulations! You won!\n");
            end_time = time(NULL);
            printf("Time taken: %.2f seconds\n", (double)(end_time - start_time));
            break;
        } else if (guess_number < head->data) {
            printf("Your guess is too low.\n");
        } else {
            printf("Your guess is too high.\n");
        }

        current_turn++;
    }

    if (current_turn == MAX_NUM_TURNS) {
        printf("Sorry, you lost. The answer was: %d\n", head->data);
    }
}

int main() {
    Node* head = malloc(sizeof(Node));
    head->data = 42;
    head->next = NULL;

    play_game(head);

    return 0;
}