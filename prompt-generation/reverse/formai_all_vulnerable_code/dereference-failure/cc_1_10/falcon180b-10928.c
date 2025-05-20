//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WPM 200
#define MAX_CPM (MAX_WPM * 5)
#define MAX_ACCURACY 100.0
#define MAX_WORDS 20
#define MIN_WORD_LENGTH 4
#define MAX_WORD_LENGTH 10

typedef struct {
    char *word;
    int length;
} Word;

int main() {
    int num_words;
    char input_buffer[100];
    Word words[MAX_WORDS];
    int i, j, k, num_correct;
    int total_chars, correct_chars;
    int wpm, cpm;
    double accuracy;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Please enter the number of words you want to type: ");
    scanf("%d", &num_words);

    for (i = 0; i < num_words; i++) {
        printf("Enter word #%d: ", i + 1);
        scanf("%s", input_buffer);
        words[i].word = strdup(input_buffer);
        words[i].length = strlen(words[i].word);
    }

    printf("Please type the words as accurately and quickly as possible.\n");
    printf("You have %d seconds.\n", MAX_WPM * num_words);
    printf("Press ENTER to start.\n");
    getchar();
    time_t start_time = time(NULL);

    total_chars = 0;
    correct_chars = 0;
    for (i = 0; i < num_words; i++) {
        printf("%s", words[i].word);
        total_chars += words[i].length;

        char input_buffer[100];
        scanf("%s", input_buffer);

        if (strcmp(input_buffer, words[i].word) == 0) {
            correct_chars += words[i].length;
        }
    }

    time_t end_time = time(NULL);
    double elapsed_time = difftime(end_time, start_time);
    wpm = (int) (MAX_WPM * total_chars / elapsed_time);
    cpm = (int) (MAX_CPM * correct_chars / elapsed_time);
    accuracy = (double) correct_chars / total_chars * 100.0;

    printf("\nTest complete!\n");
    printf("Words per minute: %d\n", wpm);
    printf("Characters per minute: %d\n", cpm);
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}