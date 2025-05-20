//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_NUM_WORDS 100

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency *words;
    int numWords;
} Resume;

Resume *createResume() {
    Resume *resume = malloc(sizeof(Resume));
    resume->words = NULL;
    resume->numWords = 0;
    return resume;
}

void destroyResume(Resume *resume) {
    if (resume!= NULL) {
        for (int i = 0; i < resume->numWords; i++) {
            free(resume->words[i].word);
        }
        free(resume->words);
        free(resume);
    }
}

void addWord(Resume *resume, char *word) {
    WordFrequency *newWords = realloc(resume->words, sizeof(WordFrequency) * (resume->numWords + 1));
    if (newWords!= NULL) {
        resume->words = newWords;
        resume->numWords++;
        resume->words[resume->numWords - 1].word = strdup(word);
        resume->words[resume->numWords - 1].frequency = 1;
    }
}

void printResume(Resume *resume) {
    for (int i = 0; i < resume->numWords; i++) {
        printf("%s: %d\n", resume->words[i].word, resume->words[i].frequency);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    Resume *resume = createResume();

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            char *word = strtok(token, "-");
            while (word!= NULL) {
                if (strlen(word) <= MAX_WORD_LENGTH) {
                    addWord(resume, word);
                }
                word = strtok(NULL, "-");
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    printResume(resume);
    destroyResume(resume);

    return 0;
}