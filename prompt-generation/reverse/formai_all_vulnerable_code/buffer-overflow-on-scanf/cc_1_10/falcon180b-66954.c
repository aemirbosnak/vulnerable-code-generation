//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 10

typedef struct {
    char word[MAX_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS];
int numWords = 0;

void loadWords(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading words from file.\n");
        exit(1);
    }

    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, file)!= NULL) {
        int len = strlen(line);
        if (len > MAX_LENGTH) {
            printf("Error: word \"%s\" is too long.\n", line);
            exit(1);
        }

        strcpy(words[numWords].word, line);
        words[numWords].length = len;
        numWords++;
    }

    fclose(file);
}

void shuffleWords() {
    srand(time(NULL));
    for (int i = 0; i < numWords; i++) {
        int j = rand() % numWords;
        Word temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

int main() {
    char filename[MAX_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    loadWords(filename);
    shuffleWords();

    printf("Enter a word: ");
    char guess[MAX_LENGTH];
    scanf("%s", guess);

    int score = 0;
    int maxScore = numWords * MAX_LENGTH;

    while (score < maxScore) {
        printf("\nScore: %d/%d\n", score, maxScore);

        for (int i = 0; i < numWords; i++) {
            int len = strlen(guess);
            if (len == words[i].length) {
                int j;
                for (j = 0; j < words[i].length; j++) {
                    if (tolower(guess[j])!= tolower(words[i].word[j])) {
                        break;
                    }
                }
                if (j == words[i].length) {
                    printf("Correct!\n");
                    score += words[i].length;
                } else {
                    printf("Incorrect.\n");
                }
            } else if (len > words[i].length) {
                printf("Too long.\n");
            } else {
                printf("Too short.\n");
            }
        }

        printf("\nEnter a word: ");
        scanf("%s", guess);
    }

    printf("\nCongratulations! You scored %d points!\n", score);

    return 0;
}