//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define WORDS_PER_LINE 20

typedef struct WordNode {
    char word[20];
    struct WordNode* next;
} WordNode;

WordNode* insertWord(WordNode* head, char* word) {
    WordNode* newNode = malloc(sizeof(WordNode));
    strcpy(newNode->word, word);
    newNode->next = head;
    return newNode;
}

void printWords(WordNode* head) {
    WordNode* current = head;
    while (current) {
        printf("%s ", current->word);
        current = current->next;
    }
    printf("\n");
}

int main() {
    WordNode* head = NULL;
    char word[20];

    clock_t start, end;
    double timeTaken;

    // Insert words into the linked list
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("Enter a word: ");
        scanf("%s", word);
        insertWord(head, word);
    }

    // Print the inserted words
    printWords(head);

    // Start the timer
    start = clock();

    // Type the words as fast as you can
    printf("Type the words below as quickly as possible:\n");
    printWords(head);

    // Stop the timer
    end = clock();

    // Calculate the time taken
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the time taken
    printf("Time taken: %.2lf seconds\n", timeTaken);

    return 0;
}