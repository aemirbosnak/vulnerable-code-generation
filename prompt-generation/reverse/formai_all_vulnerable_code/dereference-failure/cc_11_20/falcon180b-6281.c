//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEYWORDS 10
#define KEYWORD_SIZE 32

typedef struct {
    char* keyword;
    int count;
} Keyword;

int main(int argc, char** argv) {
    FILE* file;
    char line[MAX_LINE_SIZE];
    int lineNumber = 1;
    int keywordCount = 0;
    Keyword keywords[MAX_KEYWORDS];
    char keyword[KEYWORD_SIZE];
    int i;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                keyword[i] = line[i];
            } else {
                keyword[i] = '\0';
                break;
            }
        }

        for (i = 0; i < keywordCount; i++) {
            if (strcmp(keywords[i].keyword, keyword) == 0) {
                keywords[i].count++;
                break;
            }
        }

        if (i == keywordCount) {
            if (keywordCount >= MAX_KEYWORDS) {
                printf("Error: maximum number of keywords reached.\n");
                break;
            }

            strcpy(keywords[keywordCount].keyword, keyword);
            keywords[keywordCount].count = 1;
            keywordCount++;
        }

        lineNumber++;
    }

    fclose(file);

    printf("Line Number\tKeyword\tCount\n");
    for (i = 0; i < keywordCount; i++) {
        printf("%d\t%s\t%d\n", lineNumber, keywords[i].keyword, keywords[i].count);
    }

    return 0;
}