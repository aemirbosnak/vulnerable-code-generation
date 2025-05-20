//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: imaginative
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 1000

typedef struct Word {
    char word[MAX_WORDS];
    struct Word* next;
} Word;

Word* createWord(char* word) {
    Word* newWord = malloc(sizeof(Word));
    strcpy(newWord->word, word);
    newWord->next = NULL;
    return newWord;
}

void insertWord(Word* head, char* word) {
    Word* newWord = createWord(word);
    if (head == NULL) {
        head = newWord;
    } else {
        head->next = newWord;
    }
}

int main() {
    Word* head = NULL;
    clock_t start, end;
    double timeTaken;
    char word[MAX_WORDS];

    printf("Enter a word: ");
    scanf("%s", word);

    insertWord(head, word);

    start = clock();
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("%s\n", head->word);
        head = head->next;
    }
    end = clock();

    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken: %.2lf seconds\n", timeTaken);

    return 0;
}