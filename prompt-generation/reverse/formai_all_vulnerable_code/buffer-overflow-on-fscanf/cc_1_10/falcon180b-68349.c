//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

typedef struct {
    char *subject;
    char *verb;
    char *object;
    int length;
} Sentence;

char *words[MAX_WORDS];
int wordCount = 0;

void loadWords() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words\n");
        exit(1);
    }
    while (fscanf(file, "%s", words[wordCount])!= EOF) {
        wordCount++;
        if (wordCount >= MAX_WORDS) {
            break;
        }
    }
    fclose(file);
}

void generateSentence() {
    Sentence sentence;
    int subjectIndex = rand() % wordCount;
    int verbIndex = rand() % wordCount;
    int objectIndex = rand() % wordCount;
    int length = rand() % MAX_SENTENCE_LENGTH + 1;

    strcpy(sentence.subject, words[subjectIndex]);
    strcpy(sentence.verb, words[verbIndex]);
    strcpy(sentence.object, words[objectIndex]);
    sentence.length = length;

    printf("%s %s %s\n", sentence.subject, sentence.verb, sentence.object);
}

int main() {
    srand(time(NULL));
    loadWords();
    int choice;

    do {
        printf("1. Generate sentence\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateSentence();
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (true);

    return 0;
}