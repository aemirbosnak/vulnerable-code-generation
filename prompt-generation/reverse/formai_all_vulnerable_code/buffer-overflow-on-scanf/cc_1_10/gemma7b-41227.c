//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
    char *word;
    struct Word *next;
} Word;

Word *insertWord(Word *head, char *word) {
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->next = NULL;

    if (head == NULL) {
        head = newWord;
    } else {
        Word *currWord = head;
        while (currWord->next) {
            currWord = currWord->next;
        }
        currWord->next = newWord;
    }

    return head;
}

int countWords(Word *head) {
    int count = 0;
    Word *currWord = head;
    while (currWord) {
        count++;
        currWord = currWord->next;
    }

    return count;
}

int main() {
    Word *head = NULL;
    char *word;

    printf("Enter a word: ");
    scanf("%s", &word);
    insertWord(head, word);

    printf("Enter another word: ");
    scanf("%s", &word);
    insertWord(head, word);

    printf("Total number of words: %d", countWords(head));

    return 0;
}