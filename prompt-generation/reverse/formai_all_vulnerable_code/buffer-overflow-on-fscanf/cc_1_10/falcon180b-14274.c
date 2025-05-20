//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORD_FILE "words.txt"
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 30
#define TARGET_WPM 80
#define TARGET_ACCURACY 95
#define TARGET_TIME 60

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int length;
    int correct;
} Word;

void load_words(Word *words, int max_words) {
    FILE *file = fopen(WORD_FILE, "r");
    if (file == NULL) {
        printf("Error: could not open word file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s", words[count].word)!= EOF) {
        words[count].length = strlen(words[count].word);
        count++;
        if (count >= max_words) {
            break;
        }
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    Word words[MAX_WORDS];
    load_words(words, MAX_WORDS);

    int num_words = rand() % MAX_WORDS + 1;
    int total_correct = 0;

    for (int i = 0; i < num_words; i++) {
        int index = rand() % MAX_WORDS;
        char *word = words[index].word;
        int length = words[index].length;

        printf("%s", word);
        fflush(stdout);

        char input[MAX_WORD_LENGTH + 1];
        fgets(input, MAX_WORD_LENGTH + 1, stdin);

        if (strcmp(input, word) == 0) {
            total_correct++;
        }
    }

    int wpm = TARGET_WPM * total_correct / (num_words * words[0].length);
    int accuracy = 100 * total_correct / num_words;

    printf("\n");
    printf("Words per minute: %d\n", wpm);
    printf("Accuracy: %d%%\n", accuracy);

    return 0;
}