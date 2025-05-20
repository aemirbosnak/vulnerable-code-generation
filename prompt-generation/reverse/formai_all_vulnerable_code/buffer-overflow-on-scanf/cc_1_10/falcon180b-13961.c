//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 10

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;
int current_word;

void load_words(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error loading words file\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(words[num_words], word);
        num_words++;
    }

    fclose(fp);
}

void generate_random_word() {
    current_word = rand() % num_words;
}

void display_word() {
    printf("%s", words[current_word]);
}

int main() {
    srand(time(NULL));

    char words_filename[100];
    printf("Enter words filename: ");
    scanf("%s", words_filename);

    load_words(words_filename);

    printf("Press any key to start...\n");
    getchar();

    int correct = 0;
    int incorrect = 0;

    clock_t start_time = clock();

    while (1) {
        generate_random_word();
        display_word();

        char input[MAX_WORD_LENGTH];
        scanf("%s", input);

        if (strcmp(input, words[current_word]) == 0) {
            correct++;
        } else {
            incorrect++;
        }

        if (getchar() == '\n') {
            break;
        }
    }

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);
    printf("Words per minute: %.2f\n", (double)correct / elapsed_time * 60);

    return 0;
}