//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 10
#define MAX_KEYWORD_LENGTH 20

typedef struct {
    char *keyword;
    int count;
} Keyword;

void init_keyword(Keyword *k, char *keyword) {
    k->keyword = strdup(keyword);
    k->count = 0;
}

void process_line(char *line, Keyword *keywords, int num_keywords) {
    char *token;
    int i;

    token = strtok(line, " ");
    while (token!= NULL) {
        for (i = 0; i < num_keywords; i++) {
            if (strcmp(token, keywords[i].keyword) == 0) {
                keywords[i].count++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
}

void print_keyword_counts(Keyword *keywords, int num_keywords) {
    int i;

    for (i = 0; i < num_keywords; i++) {
        printf("%s: %d\n", keywords[i].keyword, keywords[i].count);
    }
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *filename = "logfile.txt";
    char **keywords = malloc(MAX_KEYWORDS * sizeof(char *));
    int num_keywords = 0;
    Keyword *k;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    while (num_keywords < MAX_KEYWORDS && fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (num_keywords >= MAX_KEYWORDS) {
                printf("Error: Too many keywords\n");
                exit(1);
            }
            k = &keywords[num_keywords];
            init_keyword(k, token);
            num_keywords++;
            token = strtok(NULL, " ");
        }
    }

    fclose(fp);

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        process_line(line, keywords, num_keywords);
    }

    print_keyword_counts(keywords, num_keywords);

    free(keywords);
    free(filename);

    return 0;
}