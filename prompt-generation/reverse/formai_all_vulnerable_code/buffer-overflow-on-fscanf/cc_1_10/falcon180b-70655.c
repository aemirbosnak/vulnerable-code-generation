//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define MIN_WPM 30
#define MAX_WPM 200

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} word_t;

void generate_words(word_t *words) {
    FILE *f = fopen("words.txt", "r");
    int i = 0;
    while (fscanf(f, "%s", words[i].word)!= EOF && i < MAX_WORDS) {
        words[i].length = strlen(words[i].word);
        i++;
    }
    fclose(f);
}

int main() {
    word_t words[MAX_WORDS];
    generate_words(words);
    srand(time(NULL));
    int index = rand() % MAX_WORDS;
    printf("Type the following word:\n%s\n", words[index].word);
    fflush(stdout);

    char input[MAX_WORD_LENGTH];
    fgets(input, MAX_WORD_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    int correct = 0;
    int incorrect = 0;
    int missed = 0;
    int total_chars = 0;

    for (int i = 0; i < strlen(input); i++) {
        if (i >= words[index].length) {
            missed++;
        } else if (input[i] == words[index].word[i]) {
            correct++;
        } else {
            incorrect++;
        }
        total_chars++;
    }

    int wpm = (int)(((double)correct * (MAX_WPM - MIN_WPM)) / (double)(total_chars * words[index].length) + MIN_WPM);

    printf("You typed %d correct characters, %d incorrect characters, and missed %d characters.\n", correct, incorrect, missed);
    printf("Your WPM is %d.\n", wpm);

    return 0;
}