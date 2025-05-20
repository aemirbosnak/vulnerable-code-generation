//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 5

char *words[MAX_WORDS];
int num_words = 0;

void load_words(char *filename) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *word = strtok(line, " \t\n\r\f");
        while (word!= NULL) {
            words[i++] = word;
            if (i >= MAX_WORDS) {
                printf("Error: Too many words in file\n");
                exit(1);
            }
            word = strtok(NULL, " \t\n\r\f");
        }
    }

    num_words = i;
    fclose(fp);
}

void shuffle_words() {
    int i, j, k;
    char *temp;

    for (i = 0; i < num_words; i++) {
        j = rand() % num_words;
        temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

int main() {
    char *filename;
    int i, correct = 0, incorrect = 0;
    double accuracy;
    struct timespec start, end;

    printf("Enter the filename containing words: ");
    scanf("%s", filename);

    load_words(filename);
    shuffle_words();

    clock_gettime(CLOCK_REALTIME, &start);
    for (i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
        fflush(stdout);
        usleep(500000); // Pause for 0.5 seconds
    }
    clock_gettime(CLOCK_REALTIME, &end);

    printf("\n");
    printf("Your typing speed is %.2f words per minute\n", (double)num_words / ((end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0) * 60);

    return 0;
}