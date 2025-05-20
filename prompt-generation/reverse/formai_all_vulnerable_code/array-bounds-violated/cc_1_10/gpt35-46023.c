//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: curious
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct word_counter {
    char* word;
    int count;
} WORD_COUNTER;

void lowercase(char* s) {
    for (int i = 0; s[i]; i++) {
        s[i] = tolower(s[i]);
    }
}

int compare_word_counters(const void* a, const void* b) {
    return ((WORD_COUNTER*)b)->count - ((WORD_COUNTER*)a)->count;
}

void print_results(WORD_COUNTER* counters, int n) {
    printf("\nWord frequency count:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - %d\n", i+1, counters[i].word, counters[i].count);
    }
}

int main() {
    char text[10000];
    printf("Enter text (max 10,000 characters):\n");
    fgets(text, 10000, stdin);

    int len = strlen(text);
    if (text[len-1] == '\n') {
        text[len-1] = '\0';
    }

    char* token = strtok(text, " ,.-;:\"!?()\n\r\t");
    int num_counters = 0;
    WORD_COUNTER counters[5000];

    while (token != NULL) {
        lowercase(token);
        int found = 0;
        for (int i = 0; i < num_counters; i++) {
            if (strcmp(counters[i].word, token) == 0) {
                counters[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            counters[num_counters].word = strdup(token);
            counters[num_counters].count = 1;
            num_counters++;
        }
        token = strtok(NULL, " ,.-;:\"!?()\n\r\t");
    }

    qsort(counters, num_counters, sizeof(WORD_COUNTER), compare_word_counters);
    print_results(counters, num_counters);
    return 0;
}