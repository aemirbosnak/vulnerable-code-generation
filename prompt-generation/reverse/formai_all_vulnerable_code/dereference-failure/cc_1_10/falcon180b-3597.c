//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_KEYWORDS 10
#define MAX_KEYWORD_LENGTH 32

typedef struct {
    char keyword[MAX_KEYWORD_LENGTH];
    int count;
} KeywordCount;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char delim[] = " \t\n\r\f\v";
    KeywordCount keywords[MAX_NUM_KEYWORDS];
    int num_keywords = 0;
    int i;

    // Open the log file
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening log file: %s\n", argv[1]);
        return 1;
    }

    // Read the keywords from the command line
    for (i = 2; i < argc; i++) {
        if (num_keywords >= MAX_NUM_KEYWORDS) {
            printf("Too many keywords specified.\n");
            fclose(fp);
            return 1;
        }
        strcpy(keywords[num_keywords].keyword, argv[i]);
        keywords[num_keywords].count = 0;
        num_keywords++;
    }

    // Read the log file and count the occurrences of the keywords
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *token;
        char *saveptr;
        int j;

        token = strtok_r(line, delim, &saveptr);
        while (token!= NULL) {
            for (j = 0; j < num_keywords; j++) {
                if (strcmp(token, keywords[j].keyword) == 0) {
                    keywords[j].count++;
                    break;
                }
            }
            token = strtok_r(NULL, delim, &saveptr);
        }
    }

    // Print the results
    printf("Keyword Counts:\n");
    for (i = 0; i < num_keywords; i++) {
        printf("%s: %d\n", keywords[i].keyword, keywords[i].count);
    }

    fclose(fp);
    return 0;
}