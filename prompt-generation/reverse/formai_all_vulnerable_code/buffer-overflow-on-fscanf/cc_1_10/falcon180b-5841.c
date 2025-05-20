//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;
int word_lengths[MAX_WORDS];

void read_words(char filename[]) {
    FILE *fp;
    char word[MAX_WORD_LENGTH];
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    while (fscanf(fp, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: too many words in file %s\n", filename);
            exit(1);
        }
        strcpy(words[i], word);
        word_lengths[i] = strlen(word);
        i++;
    }

    fclose(fp);
    num_words = i;
}

void shuffle_words() {
    int i, j;
    char temp[MAX_WORD_LENGTH];

    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (word_lengths[j] < word_lengths[i]) {
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);

                int temp_length = word_lengths[i];
                word_lengths[i] = word_lengths[j];
                word_lengths[j] = temp_length;
            }
        }
    }
}

int main() {
    char filename[100];
    int i, j, k, correct = 0, incorrect = 0;
    int total_chars = 0, correct_chars = 0;
    int wpm, accuracy;
    clock_t start_time, end_time;

    printf("Enter the name of the file containing the words:\n");
    scanf("%s", filename);

    read_words(filename);
    shuffle_words();

    printf("Press any key to begin the test...\n");
    getchar();

    start_time = clock();

    for (i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
        for (j = 0; j < word_lengths[i]; j++) {
            printf("*");
        }
        printf("\n");

        for (k = 0; k < word_lengths[i]; k++) {
            char ch = getchar();

            if (ch == words[i][k]) {
                correct++;
                correct_chars++;
            } else {
                incorrect++;
            }

            total_chars++;
        }

        if (i == num_words - 1) {
            end_time = clock();
        }
    }

    wpm = (double)total_chars / (double)(end_time - start_time) * 60;
    accuracy = (double)correct_chars / (double)total_chars * 100;

    printf("\nResults:\n");
    printf("Words per minute: %.2f\n", wpm);
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}