//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 10
#define MAX_KEYWORD_LENGTH 20

typedef struct {
    char keyword[MAX_KEYWORD_LENGTH];
    int count;
} Keyword;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    Keyword keywords[MAX_KEYWORDS];
    int num_keywords = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int keyword_index = -1;
        for (int i = 0; i < num_keywords; i++) {
            if (strstr(line, keywords[i].keyword)!= NULL) {
                keyword_index = i;
                break;
            }
        }
        if (keyword_index == -1) {
            if (num_keywords >= MAX_KEYWORDS) {
                printf("Too many keywords found\n");
                fclose(file);
                return 1;
            }
            keyword_index = num_keywords;
            strcpy(keywords[num_keywords].keyword, line);
            num_keywords++;
        }
        keywords[keyword_index].count++;
    }

    fclose(file);

    printf("Keyword Counts:\n");
    for (int i = 0; i < num_keywords; i++) {
        printf("%s: %d\n", keywords[i].keyword, keywords[i].count);
    }

    return 0;
}