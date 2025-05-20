//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int length;
};

void loadWords(struct word *words, int count) {
    FILE *file = fopen("words.txt", "r");
    if (!file) {
        printf("Error loading words.\n");
        exit(1);
    }

    int i = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= count) {
            break;
        }
        words[i].word[0] = tolower(word[0]);
        strcpy(&words[i].word[1], word);
        words[i].length = strlen(word);
        i++;
    }

    fclose(file);
}

int main() {
    struct word words[MAX_WORDS];
    int count;

    printf("How many words do you want to type? ");
    scanf("%d", &count);

    loadWords(words, count);

    int correctWords = 0;
    int incorrectWords = 0;
    int totalWords = 0;
    int totalChars = 0;

    time_t startTime, endTime;
    time(&startTime);

    for (int i = 0; i < count; i++) {
        printf("\nWord #%d:\n", i + 1);
        printf("%s\n", words[i].word);
        printf("Enter the word: ");
        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, words[i].word) == 0) {
            correctWords++;
        } else {
            incorrectWords++;
        }

        totalWords++;
        totalChars += strlen(input);
    }

    time(&endTime);
    double elapsedTime = difftime(endTime, startTime);

    printf("\nResults:\n");
    printf("Total words: %d\n", totalWords);
    printf("Correct words: %d\n", correctWords);
    printf("Incorrect words: %d\n", incorrectWords);
    printf("Total characters: %d\n", totalChars);
    printf("Elapsed time: %.2f seconds\n", elapsedTime);

    return 0;
}