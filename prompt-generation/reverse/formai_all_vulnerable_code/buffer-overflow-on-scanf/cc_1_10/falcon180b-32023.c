//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS];

void loadWords(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        exit(1);
    }
    int count = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[count].word, word);
        words[count].length = strlen(word);
        count++;
    }
    fclose(file);
}

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter a filename: ");
    scanf("%s", filename);
    loadWords(filename);
    int score = 0;
    int correct = 0;
    int incorrect = 0;
    int total = 0;
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].length == 0) {
            break;
        }
        printf("%s\n", words[i].word);
        char input[MAX_WORD_LENGTH];
        scanf("%s", input);
        if (strcmp(input, words[i].word) == 0) {
            correct++;
        } else {
            incorrect++;
        }
        total++;
        score += correct;
    }
    printf("Score: %d\n", score);
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);
    printf("Total: %d\n", total);
    return 0;
}