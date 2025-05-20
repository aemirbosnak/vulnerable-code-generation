//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 500
#define MAX_WORD_LENGTH 50
#define TEST_DURATION 60

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

int main() {
    FILE *fp;
    Word words[MAX_WORDS];
    int num_words = 0, i, j;
    char ch;
    int correct_words = 0, incorrect_words = 0;
    int total_words = 0;
    int start_time, end_time, elapsed_time;
    double speed, accuracy;

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open words.txt file.\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            words[num_words].word[words[num_words].length] = tolower(ch);
            words[num_words].length++;
        } else if (words[num_words].length > 0) {
            num_words++;
            words[num_words].word[0] = '\0';
            words[num_words].length = 0;
        }
    }

    fclose(fp);

    srand(time(NULL));

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].length > 0) {
            total_words++;
        }
    }

    printf("Starting typing test...\n");

    start_time = time(NULL);

    for (i = 0; i < TEST_DURATION; i++) {
        j = rand() % total_words;
        printf("%s", words[j].word);
        fflush(stdout);
        usleep(1000000 / (double)TEST_DURATION);
    }

    end_time = time(NULL);

    elapsed_time = end_time - start_time;
    speed = (double)total_words / (elapsed_time / 60.0);
    accuracy = (double)correct_words / total_words;

    printf("\nTest complete.\n");
    printf("Correct words: %d\n", correct_words);
    printf("Incorrect words: %d\n", incorrect_words);
    printf("Total words: %d\n", total_words);
    printf("Words per minute: %.2f\n", speed);
    printf("Accuracy: %.2f%%\n", accuracy * 100);

    return 0;
}