//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: relaxed
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
int num_words;
int total_chars;

void load_words(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    int word_count = 0;
    while (fscanf(file, "%s", words[word_count].word)!= EOF) {
        words[word_count].length = strlen(words[word_count].word);
        word_count++;
    }

    num_words = word_count;
    total_chars = 0;
    for (int i = 0; i < num_words; i++) {
        total_chars += words[i].length;
    }

    fclose(file);
}

void start_test(int duration) {
    time_t start_time, end_time;
    time(&start_time);

    int correct_words = 0;
    int incorrect_words = 0;

    printf("Type the words as they appear on the screen.\n");
    printf("Test will end in %d seconds.\n", duration);

    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i].word);
        fflush(stdout);

        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);

        if (strcmp(input, words[i].word) == 0) {
            correct_words++;
        } else {
            incorrect_words++;
        }
    }

    time(&end_time);
    double duration_sec = difftime(end_time, start_time);

    int wpm = (int) (total_chars / (5 * duration_sec));

    printf("\nTest complete.\n");
    printf("You typed %d words correctly and %d words incorrectly.\n", correct_words, incorrect_words);
    printf("Your typing speed is %d words per minute.\n", wpm);
}

int main() {
    char filename[100];
    printf("Enter the name of the file containing the words: ");
    scanf("%s", filename);

    load_words(filename);

    int duration;
    printf("Enter the duration of the test in seconds: ");
    scanf("%d", &duration);

    start_test(duration);

    return 0;
}