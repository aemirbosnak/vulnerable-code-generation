//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 15
#define MIN_WPM 10
#define MAX_WPM 200

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generate_words(Word words[], int num_words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words file.\n");
        exit(1);
    }

    int i = 0;
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL && i < num_words) {
        int j = 0;
        while (line[j]!= '\n' && j < MAX_WORD_LENGTH) {
            words[i].word[j] = tolower(line[j]);
            j++;
        }
        words[i].length = j;
        i++;
    }

    fclose(file);
}

int main() {
    int num_words;
    printf("How many words do you want to type? (between %d and %d): ", MIN_WPM, MAX_WPM);
    scanf("%d", &num_words);

    Word words[num_words];
    generate_words(words, num_words);

    int correct = 0;
    int incorrect = 0;
    int total = 0;

    clock_t start_time = clock();
    printf("Start typing...\n");
    while (1) {
        char input[MAX_WORD_LENGTH];
        printf("Type the following word: ");
        scanf("%s", input);

        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(words[i].word, input) == 0) {
                correct++;
                break;
            }
        }

        if (i == num_words) {
            incorrect++;
        }

        total++;

        if (total == num_words) {
            clock_t end_time = clock();
            double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            int wpm = (int)((double)correct / elapsed_time * 60);

            printf("\nYou typed %d words correctly and %d words incorrectly.\n", correct, incorrect);
            printf("Your words per minute is: %d\n", wpm);
            break;
        }
    }

    return 0;
}