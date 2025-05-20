//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int length;
} Word;

Word words[MAX_WORDS];
int numWords = 0;
int maxWords = 0;

void readWords(FILE *file) {
    char line[80];
    fgets(line, sizeof(line), file);
    char *word = strtok(line, ",.?!;:");
    while (word!= NULL) {
        int len = strlen(word);
        if (len > MAX_WORD_LEN) {
            len = MAX_WORD_LEN;
        }
        strncpy(words[numWords].word, word, len);
        words[numWords].length = len;
        numWords++;
        word = strtok(NULL, ",.?!;:");
        if (numWords >= maxWords) {
            break;
        }
    }
    rewind(file);
}

void shuffleWords() {
    for (int i = 0; i < numWords; i++) {
        int j = rand() % numWords;
        Word temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

int main() {
    FILE *file;
    char filename[80];
    printf("Enter filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    readWords(file);
    fclose(file);
    shuffleWords();
    printf("Press enter to start typing test.\n");
    getchar();
    int correct = 0;
    int incorrect = 0;
    int total = 0;
    for (int i = 0; i < numWords; i++) {
        printf("%s ", words[i].word);
        char input[MAX_WORD_LEN];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, words[i].word) == 0) {
            correct++;
        } else {
            incorrect++;
        }
        total++;
        printf("Correct: %d, Incorrect: %d\n", correct, incorrect);
        fflush(stdout);
    }
    printf("Total: %d\n", total);
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);
    printf("Accuracy: %.2f%%\n", (float)correct / total * 100);
    return 0;
}