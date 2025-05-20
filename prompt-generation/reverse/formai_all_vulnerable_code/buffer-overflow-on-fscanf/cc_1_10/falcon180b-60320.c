//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

char words[MAX_WORDS][MAX_WORD_LEN];
int num_words;

void load_words(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[num_words], word);
        num_words++;
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    load_words("words.txt");

    printf("Welcome to the Futuristic Typing Speed Test!\n");
    printf("You will be typing %d words.\n", num_words);

    int correct_words = 0;
    int total_words = 0;
    int total_chars = 0;
    int correct_chars = 0;

    int start_time = time(NULL);

    for (int i = 0; i < num_words; i++) {
        printf("\nWord %d: ", i+1);
        char input[MAX_WORD_LEN];
        fgets(input, MAX_WORD_LEN, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, words[i]) == 0) {
            correct_words++;
            correct_chars += strlen(input);
        }

        total_chars += strlen(input);
        total_words++;
    }

    int end_time = time(NULL);

    double elapsed_time = difftime(end_time, start_time);

    double wpm = (double)correct_words / (elapsed_time / 60);
    double cpm = (double)correct_chars / (elapsed_time / 60);

    printf("\nResults:\n");
    printf("Correct words: %d\n", correct_words);
    printf("Total words: %d\n", total_words);
    printf("Correct characters: %d\n", correct_chars);
    printf("Total characters: %d\n", total_chars);
    printf("Words per minute: %.2f\n", wpm);
    printf("Characters per minute: %.2f\n", cpm);

    return 0;
}