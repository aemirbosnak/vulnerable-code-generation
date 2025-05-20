//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_KEYWORDS 10
#define MAX_KEYWORD_LENGTH 20

typedef struct {
    char keyword[MAX_KEYWORD_LENGTH];
    int count;
} Keyword;

void process_line(char *line, Keyword *keywords) {
    char *token;
    int i;

    token = strtok(line, " ");
    while (token!= NULL) {
        for (i = 0; i < MAX_NUM_KEYWORDS; i++) {
            if (strcmp(token, keywords[i].keyword) == 0) {
                keywords[i].count++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    Keyword keywords[MAX_NUM_KEYWORDS];
    int num_keywords = 0;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        process_line(line, keywords);
    }

    fclose(fp);

    printf("Keyword Counts:\n");
    for (int i = 0; i < num_keywords; i++) {
        printf("%s: %d\n", keywords[i].keyword, keywords[i].count);
    }

    return 0;
}