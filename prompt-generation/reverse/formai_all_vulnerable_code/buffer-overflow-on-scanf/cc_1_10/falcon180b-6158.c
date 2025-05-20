//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_NUM_KEYWORDS 10

typedef struct {
    char *name;
    int line_num;
} Keyword;

void extract_keywords(char *filename, int num_keywords, Keyword *keywords) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int line_num = 1;
    int keyword_count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int i;
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                line[i] = tolower(line[i]);
            } else {
                line[i] = '\0';
            }
        }

        if (strlen(line) > 0) {
            if (keyword_count >= num_keywords) {
                break;
            }

            keywords[keyword_count].name = (char *)malloc(strlen(line) + 1);
            strcpy(keywords[keyword_count].name, line);
            keywords[keyword_count].line_num = line_num;
            keyword_count++;
        }

        line_num++;
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    int num_keywords;
    char filename[MAX_LINE_LENGTH];
    Keyword keywords[MAX_NUM_KEYWORDS];

    printf("Enter the name of the file to extract keywords from: ");
    scanf("%s", filename);

    printf("Enter the number of keywords to extract: ");
    scanf("%d", &num_keywords);

    extract_keywords(filename, num_keywords, keywords);

    printf("Keywords:\n");
    for (int i = 0; i < num_keywords; i++) {
        printf("%s (%d)\n", keywords[i].name, keywords[i].line_num);
    }

    return 0;
}