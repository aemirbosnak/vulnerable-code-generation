//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_WORD_LENGTH 50

typedef struct WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
    struct WordCount* next;
} WordCount;

void addWord(WordCount** head, char* word) {
    WordCount* tmp = *head;

    while (tmp != NULL) {
        if (strcmp(tmp->word, word) == 0) {
            tmp->count++;
            return;
        }
        tmp = tmp->next;
    }

    WordCount* newWord = (WordCount*) malloc(sizeof(WordCount));
    strncpy(newWord->word, word, MAX_WORD_LENGTH);
    newWord->count = 1;
    newWord->next = *head;
    *head = newWord;
}

void printWordCounts(WordCount* head) {
    while (head != NULL) {
        printf("%s: %d\n", head->word, head->count);
        head = head->next;
    }
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char line[1024];
    printf("-- Cyberpunk Word Count Tool --\n");
    printf("Enter filename: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strlen(filename) - 1] = '\0';

    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file. Please check the filename and try again.\n");
        return 1;
    }

    WordCount* wordCounts = NULL;
    while (fgets(line, 1024, file)) {
        char* token = strtok(line, " !@#$%^&*()_-+={[}]|\\:;\"'<,>.?/~`\n");
        while (token != NULL) {
            for (int i = 0; i < strlen(token); i++) {
                token[i] = tolower(token[i]);
            }
            addWord(&wordCounts, token);
            token = strtok(NULL, " !@#$%^&*()_-+={[}]|\\:;\"'<,>.?/~`\n");
        }
    }

    printWordCounts(wordCounts);

    fclose(file);
    return 0;
}