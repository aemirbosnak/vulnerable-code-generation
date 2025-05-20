//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int length;
};

int main() {
    struct word words[MAX_WORDS];
    int num_words, i, j, correct = 0, incorrect = 0, total = 0;
    char input[MAX_WORD_LENGTH];
    FILE *file;
    time_t start_time, end_time;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Please enter the number of words you want to type: ");
    scanf("%d", &num_words);

    srand(time(NULL));
    for (i = 0; i < num_words; i++) {
        words[i].length = rand() % 5 + 5;
        words[i].word[words[i].length - 1] = '\0';
        for (j = 0; j < words[i].length; j++) {
            words[i].word[j] = rand() % 26 + 'a';
        }
    }

    printf("Please wait while the words are loaded...\n");

    start_time = time(NULL);
    file = fopen("words.txt", "w");
    if (file == NULL) {
        printf("Error: Could not create file.\n");
        return 1;
    }

    for (i = 0; i < num_words; i++) {
        fprintf(file, "%s\n", words[i].word);
    }

    fclose(file);
    printf("Words loaded successfully!\n");

    printf("Please type the words as accurately and quickly as possible.\n");
    printf("Press Enter after each word.\n");

    for (i = 0; i < num_words; i++) {
        printf("Word %d: ", i + 1);
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, words[i].word) == 0) {
            correct++;
        } else {
            incorrect++;
        }

        total++;
    }

    end_time = time(NULL);

    printf("Test complete!\n");
    printf("Correct words typed: %d\n", correct);
    printf("Incorrect words typed: %d\n", incorrect);
    printf("Total words typed: %d\n", total);
    printf("Accuracy: %.2f%%\n", (float)correct / total * 100);
    printf("Speed: %.2f words per minute\n", (float)total / (end_time - start_time) * 60);

    return 0;
}