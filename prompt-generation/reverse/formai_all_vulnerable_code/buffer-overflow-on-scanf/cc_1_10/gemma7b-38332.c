//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY 10

typedef struct MemoryCell {
    char data;
    struct MemoryCell* next;
} MemoryCell;

void createMemory(MemoryCell** head) {
    *head = malloc(sizeof(MemoryCell));
    (*head)->data = '\0';
    (*head)->next = NULL;
}

void insertMemory(MemoryCell** head, char data) {
    MemoryCell* newCell = malloc(sizeof(MemoryCell));
    newCell->data = data;
    newCell->next = NULL;

    if (*head == NULL) {
        *head = newCell;
    } else {
        ((*head)->next = newCell);
        *head = newCell;
    }
}

void playMemoryGame(MemoryCell* head) {
    char guessWord[MAX_MEMORY];
    int guessWordIndex = 0;

    printf("Enter the secret word: ");
    scanf("%s", guessWord);

    for (int i = 0; guessWord[i] != '\0'; i++) {
        guessWordIndex++;

        if (head->data == guessWord[i]) {
            printf("Memory cell %d matches the secret word.\n", guessWordIndex);
        } else {
            printf("Memory cell %d does not match the secret word.\n", guessWordIndex);
        }

        head = head->next;
    }
}

int main() {
    MemoryCell* head = NULL;
    createMemory(&head);
    insertMemory(&head, 'a');
    insertMemory(&head, 'b');
    insertMemory(&head, 'c');
    insertMemory(&head, 'd');
    insertMemory(&head, 'e');

    playMemoryGame(head);

    return 0;
}