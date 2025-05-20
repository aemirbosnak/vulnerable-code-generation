//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 100
#define MAX_CONSPIRACY_WORDS 20
#define CONSPIRACY_WORD_LIST_FILE "conspiracy_words.txt"

typedef struct {
    char *word;
    int length;
} ConspiracyWord;

ConspiracyWord conspiracyWords[MAX_CONSPIRACY_WORDS];
int numConspiracyWords;

void loadConspiracyWords() {
    FILE *file;
    char line[MAX_CONSPIRACY_LENGTH];
    ConspiracyWord word;

    file = fopen(CONSPIRACY_WORD_LIST_FILE, "r");
    if (file == NULL) {
        printf("Error loading conspiracy word list file.\n");
        exit(1);
    }

    numConspiracyWords = 0;
    while (fgets(line, MAX_CONSPIRACY_LENGTH, file)!= NULL) {
        word.word = malloc(strlen(line) + 1);
        strcpy(word.word, line);
        word.length = strlen(line);
        conspiracyWords[numConspiracyWords++] = word;
    }

    fclose(file);
}

char *generateRandomConspiracyTheory(int maxLength) {
    int i, j, k, l;
    char theory[MAX_CONSPIRACY_LENGTH];
    theory[0] = '\0';

    srand(time(NULL));
    i = rand() % numConspiracyWords;

    strcat(theory, conspiracyWords[i].word);
    k = conspiracyWords[i].length;

    for (j = 1; j < maxLength && k < MAX_CONSPIRACY_LENGTH - 1; j++) {
        i = rand() % numConspiracyWords;
        while (i == j - 1)
            i = rand() % numConspiracyWords;

        l = rand() % conspiracyWords[i].length + 1;
        strncat(theory, conspiracyWords[i].word + l, MAX_CONSPIRACY_LENGTH - k - 1);
        k += l;
    }

    theory[k] = '\0';
    return theory;
}

int main() {
    int maxLength;

    printf("Enter the maximum length of the conspiracy theory: ");
    scanf("%d", &maxLength);

    loadConspiracyWords();

    char *theory = generateRandomConspiracyTheory(maxLength);
    printf("Your random conspiracy theory: %s\n", theory);

    return 0;
}