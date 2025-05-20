//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node* head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

int main() {
    Node* head = NULL;
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    time_t t = time(NULL);
    srand(t);

    int guessNumber = rand() % MAX_SIZE + 1;

    printf("I have a secret number between 1 and %d. Can you guess what it is?\n", MAX_SIZE);

    int guess;

    while (guess != guessNumber) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess < guessNumber) {
            printf("Your guess is too low.\n");
        } else if (guess > guessNumber) {
            printf("Your guess is too high.\n");
        }
    }

    printf("Congratulations! You guessed the number!\n");

    return 0;
}