//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_KEYWORDS 10

typedef struct {
    char keyword[MAX_WORD_LENGTH];
    int count;
} Keyword;

int main() {
    char filename[MAX_WORD_LENGTH];
    FILE *fp;
    char line[MAX_WORD_LENGTH];
    char *token;
    Keyword keywords[MAX_KEYWORDS];
    int num_keywords = 0;
    int i;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Read in file and count keywords
    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        token = strtok(line, " \t\n\r\f\v");
        while (token!= NULL) {
            for (i = 0; i < num_keywords; i++) {
                if (strcmp(token, keywords[i].keyword) == 0) {
                    keywords[i].count++;
                    break;
                }
            }
            if (i == num_keywords) {
                if (num_keywords == MAX_KEYWORDS) {
                    printf("Error: too many keywords.\n");
                    exit(1);
                }
                strcpy(keywords[num_keywords].keyword, token);
                keywords[num_keywords].count = 1;
                num_keywords++;
            }
            token = strtok(NULL, " \t\n\r\f\v");
        }
    }

    // Print keyword counts
    printf("Keyword counts:\n");
    for (i = 0; i < num_keywords; i++) {
        printf("%s: %d\n", keywords[i].keyword, keywords[i].count);
    }

    // Close file
    fclose(fp);

    return 0;
}