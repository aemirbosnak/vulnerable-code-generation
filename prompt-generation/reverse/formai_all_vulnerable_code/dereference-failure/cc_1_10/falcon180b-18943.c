//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000000
#define MAX_NUM_KEYWORDS 10000

typedef struct {
    char *keyword;
    int count;
} Keyword;

Keyword *keywords = NULL;
int num_keywords = 0;

void add_keyword(char *keyword) {
    if (num_keywords >= MAX_NUM_KEYWORDS) {
        printf("Error: Too many keywords.\n");
        exit(1);
    }

    Keyword *new_keyword = malloc(sizeof(Keyword));
    new_keyword->keyword = strdup(keyword);
    new_keyword->count = 0;

    keywords = realloc(keywords, sizeof(Keyword) * ++num_keywords);
    keywords[num_keywords - 1] = *new_keyword;
}

void process_line(char *line) {
    char *word = strtok(line, " ");
    while (word!= NULL) {
        int i;
        for (i = 0; i < num_keywords; i++) {
            if (strcmp(word, keywords[i].keyword) == 0) {
                keywords[i].count++;
                break;
            }
        }
        if (i == num_keywords) {
            add_keyword(word);
        }
        word = strtok(NULL, " ");
    }
}

void print_results() {
    printf("Keyword\tCount\n");
    for (int i = 0; i < num_keywords; i++) {
        printf("%s\t%d\n", keywords[i].keyword, keywords[i].count);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        process_line(line);
    }

    print_results();

    for (int i = 0; i < num_keywords; i++) {
        free(keywords[i].keyword);
    }
    free(keywords);

    return 0;
}