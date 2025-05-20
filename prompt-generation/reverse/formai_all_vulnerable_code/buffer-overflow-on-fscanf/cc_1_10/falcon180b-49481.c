//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_SIZE 1000
#define MAX_WORD_SIZE 50
#define MAX_WORD_COUNT 100

struct word_count {
    char word[MAX_WORD_SIZE];
    int count;
};

void read_log_file(FILE* log_file, struct word_count* word_counts, int count) {
    char line[MAX_LOG_SIZE];
    char word[MAX_WORD_SIZE];
    int i = 0;

    while (fgets(line, MAX_LOG_SIZE, log_file)!= NULL) {
        for (int j = 0; j < strlen(line); j++) {
            if (isalpha(line[j])) {
                strncat(word, &line[j], 1);
            } else {
                word[i] = '\0';
                i++;
                j--;
            }
        }
        for (int k = 0; k < count; k++) {
            if (strcmp(word_counts[k].word, word) == 0) {
                word_counts[k].count++;
                break;
            }
        }
    }
}

void print_word_counts(struct word_count* word_counts, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE* log_file = fopen("log.txt", "r");
    struct word_count word_counts[MAX_WORD_COUNT];
    int count = 0;

    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    while (fscanf(log_file, "%s", word_counts[count].word)!= EOF) {
        count++;
    }

    read_log_file(log_file, word_counts, count);
    print_word_counts(word_counts, count);

    return 0;
}