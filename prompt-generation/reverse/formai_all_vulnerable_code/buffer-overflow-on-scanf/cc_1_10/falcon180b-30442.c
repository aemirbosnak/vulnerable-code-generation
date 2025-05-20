//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} word_t;

word_t words[MAX_WORDS];
int num_words;

void load_words(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading file: %s\n", filename);
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        int i = 0;
        while (isspace(line[i])) i++;
        int j = 0;
        while (line[i]!= '\n' && j < MAX_WORD_LENGTH - 1) {
            if (isalpha(line[i])) {
                words[num_words].word[j++] = tolower(line[i]);
                words[num_words].length = j;
            }
            i++;
        }
        num_words++;
    }

    fclose(file);
}

void shuffle_words() {
    for (int i = 0; i < num_words; i++) {
        int j = rand() % num_words;
        word_t temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

void print_word(int index) {
    for (int i = 0; i < words[index].length; i++) {
        printf("%c", words[index].word[i]);
    }
    printf(" ");
}

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    load_words(filename);
    shuffle_words();

    int correct = 0;
    int incorrect = 0;
    int total = 0;
    int start_time = time(NULL);

    printf("Press enter to start\n");
    getchar();

    for (int i = 0; i < num_words; i++) {
        printf("%s", words[i].word);
        for (int j = words[i].length; j < MAX_WORD_LENGTH; j++) {
            printf("_");
        }
        printf(" ");
        fflush(stdout);

        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, words[i].word) == 0) {
            correct++;
        } else {
            incorrect++;
        }

        total++;
    }

    int end_time = time(NULL);
    int duration = end_time - start_time;

    printf("\nResults:\n");
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);
    printf("Total: %d\n", total);
    printf("Duration: %d seconds\n", duration);
    printf("WPM: %d\n", (total - incorrect) / (duration / 60));

    return 0;
}