//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LENGTH 10
#define MAX_WORDS 100

struct word {
    char word[MAX_WORD_LENGTH];
    int length;
};

void generate_words(struct word words[], int num_words) {
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand(time(NULL));

    for (int i = 0; i < num_words; i++) {
        int length = rand() % (MAX_WORD_LENGTH - 1) + 1;
        words[i].length = length;

        for (int j = 0; j < length; j++) {
            words[i].word[j] = charset[rand() % strlen(charset)];
        }
        words[i].word[length] = '\0';
    }
}

int main() {
    int num_words;
    printf("Enter the number of words to type: ");
    scanf("%d", &num_words);

    struct word words[MAX_WORDS];
    generate_words(words, num_words);

    printf("\nStart typing!\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i].word);
    }

    int correct_words = 0;
    for (int i = 0; i < num_words; i++) {
        char input[MAX_WORD_LENGTH];
        printf("\nType word #%d: ", i+1);
        scanf("%s", input);

        if (strcmp(input, words[i].word) == 0) {
            correct_words++;
        }
    }

    double accuracy = (double)correct_words / num_words * 100;
    printf("\nYou typed %d out of %d words correctly (%.2f%% accuracy)\n", correct_words, num_words, accuracy);

    return 0;
}