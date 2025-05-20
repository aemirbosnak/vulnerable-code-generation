//Falcon-180B DATASET v1.0 Category: Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define NUM_CATEGORIES 5

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
    int category;
} Word;

char categories[][20] = {"Animals", "Fruits", "Countries", "Cities", "Colors"};

void generateWords(Word words[], int numWords) {
    FILE *file;
    char line[100];
    int i = 0;

    file = fopen("words.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (i >= numWords) {
            break;
        }

        char *word = strtok(line, " \t\n\r\f\v");
        int category = rand() % NUM_CATEGORIES;

        strcpy(words[i].word, word);
        words[i].length = strlen(words[i].word);
        words[i].category = category;

        i++;
    }

    fclose(file);
}

int compareWords(const void *a, const void *b) {
    Word word1 = *((Word *) a);
    Word word2 = *((Word *) b);

    if (word1.length > word2.length) {
        return -1;
    } else if (word1.length < word2.length) {
        return 1;
    } else {
        return 0;
    }
}

void printWords(Word words[], int numWords) {
    qsort(words, numWords, sizeof(Word), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s (%d letters) - Category: %s\n", words[i].word, words[i].length, categories[words[i].category]);
    }
}

int main() {
    srand(time(NULL));

    int numWords;
    printf("Enter the number of words to generate: ");
    scanf("%d", &numWords);

    Word words[MAX_WORDS];
    generateWords(words, numWords);

    printf("Generated words:\n");
    printWords(words, numWords);

    return 0;
}