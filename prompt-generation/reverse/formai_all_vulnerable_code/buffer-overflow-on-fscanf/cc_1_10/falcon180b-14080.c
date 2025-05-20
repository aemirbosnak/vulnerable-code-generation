//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORD_COUNT 1000
#define MIN_WPM 20

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int length;
} Word;

void generate_words(Word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words file.\n");
        exit(1);
    }

    int count = 0;
    while (count < MAX_WORD_COUNT && fscanf(file, "%s", words[count].word)!= EOF) {
        words[count].length = strlen(words[count].word);
        count++;
    }

    fclose(file);
}

int main() {
    Word words[MAX_WORD_COUNT];
    generate_words(words);

    int total_chars = 0;
    int total_words = 0;
    int total_errors = 0;
    int wpm = 0;

    printf("Words:\n");
    for (int i = 0; i < MAX_WORD_COUNT; i++) {
        printf("%d. ", i + 1);
        for (int j = 0; j < words[i].length; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("Press enter to begin...\n");
    getchar();

    clock_t start = clock();
    while (1) {
        char input[MAX_WORD_LENGTH + 1];
        fgets(input, MAX_WORD_LENGTH + 1, stdin);
        input[strcspn(input, "\n")] = '\0';

        int chars_typed = strlen(input);
        total_chars += chars_typed;

        if (strcasecmp(input, words[total_words].word) == 0) {
            total_words++;
            total_errors += (chars_typed - words[total_words - 1].length);
        } else {
            total_errors += chars_typed;
        }

        if (total_words == MAX_WORD_COUNT) {
            break;
        }
    }

    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    wpm = (int)((total_chars / 5) / elapsed_time);

    printf("\nTotal words: %d\n", total_words);
    printf("Total errors: %d\n", total_errors);
    printf("Words per minute: %d\n", wpm);

    return 0;
}