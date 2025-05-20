//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generate_words(Word words[], int num_words) {
    FILE *fp = fopen("words.txt", "r");
    int i = 0;
    while (i < num_words && fscanf(fp, "%s", words[i].word)!= EOF) {
        words[i].length = strlen(words[i].word);
        i++;
    }
    fclose(fp);
}

int main() {
    srand(time(NULL));

    int num_words = rand() % MAX_WORDS + 1;
    Word words[MAX_WORDS];
    generate_words(words, num_words);

    int total_chars = 0;
    int num_correct = 0;
    int num_incorrect = 0;

    for (int i = 0; i < num_words; i++) {
        printf("Word %d: ", i+1);
        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, words[i].word) == 0) {
            num_correct++;
        } else {
            num_incorrect++;
        }

        total_chars += strlen(input);
    }

    int wpm = (total_chars / 5) * 60;
    double accuracy = ((double)num_correct / num_words) * 100;

    printf("Total characters: %d\n", total_chars);
    printf("Words per minute: %d\n", wpm);
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}