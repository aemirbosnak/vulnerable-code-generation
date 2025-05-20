//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS];
int numWords = 0;

void addWord(char* word) {
    if (numWords >= MAX_WORDS) {
        printf("Error: Too many words!\n");
        exit(1);
    }
    strcpy(words[numWords].word, word);
    words[numWords].length = strlen(word);
    numWords++;
}

void generateRandomWords(int numWords) {
    srand(time(NULL));
    for (int i = 0; i < numWords; i++) {
        char word[MAX_WORD_LENGTH];
        int length = rand() % MAX_WORD_LENGTH + 5;
        for (int j = 0; j < length; j++) {
            word[j] = rand() % 26 + 'a';
        }
        word[length] = '\0';
        addWord(word);
    }
}

int main() {
    int numWords;
    printf("Enter the number of words: ");
    scanf("%d", &numWords);
    generateRandomWords(numWords);

    char input[MAX_WORD_LENGTH];
    int correct = 0, incorrect = 0, total = 0;

    printf("Press Enter to start the test...\n");
    getchar();

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    while (1) {
        Word word = words[rand() % numWords];
        char* wordToType = word.word;
        int wordLength = word.length;

        printf("\nType the following word: ");
        for (int i = 0; i < wordLength; i++) {
            printf("*");
        }
        printf("\n");

        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, wordToType) == 0) {
            correct++;
        } else {
            incorrect++;
        }

        total++;

        if (total >= numWords * 2) {
            break;
        }
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nResults:\n");
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);
    printf("Total: %d\n", total);
    printf("Time taken: %.2f seconds\n", cpu_time_used);

    return 0;
}