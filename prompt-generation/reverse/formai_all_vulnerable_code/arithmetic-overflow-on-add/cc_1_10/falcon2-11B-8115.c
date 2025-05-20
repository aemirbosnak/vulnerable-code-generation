//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024
#define MAX_WORD_SIZE 100

void analyze_log(char *log_file) {
    FILE *fp = fopen(log_file, "r");
    if (fp == NULL) {
        printf("Error opening log file: %s\n", log_file);
        return;
    }

    char log[MAX_LOG_SIZE];
    char word[MAX_WORD_SIZE];
    int word_count[MAX_WORD_SIZE];
    int word_index = 0;
    int log_index = 0;

    while (fgets(log, MAX_LOG_SIZE, fp)!= NULL) {
        log_index++;
        char *p;
        char *q;
        p = strtok(log, " ");
        while (p!= NULL) {
            q = strtok(NULL, " ");
            if (q!= NULL) {
                strcpy(word, p);
                word_count[word_index]++;
                word_index++;
            }
            p = strtok(NULL, " ");
        }
    }

    fclose(fp);

    char *word_list[word_index];
    int i;
    for (i = 0; i < word_index; i++) {
        word_list[i] = malloc(MAX_WORD_SIZE);
        strcpy(word_list[i], word[i]);
    }

    int max_word_count = 0;
    int max_word_index = 0;
    int j;
    for (j = 0; j < word_index; j++) {
        if (word_count[j] > max_word_count) {
            max_word_count = word_count[j];
            max_word_index = j;
        }
    }

    printf("Total words in log: %d\n", log_index);
    printf("Most common word: %s\n", word_list[max_word_index]);
    printf("Number of times it appears: %d\n", max_word_count);

    for (i = 0; i < word_index; i++) {
        if (word_count[i] == max_word_count) {
            printf("%s: %d\n", word_list[i], word_count[i]);
        }
    }

    free(word_list[0]);
    for (i = 1; i < word_index; i++) {
        free(word_list[i]);
    }
}

int main() {
    analyze_log("my_log.log");
    return 0;
}