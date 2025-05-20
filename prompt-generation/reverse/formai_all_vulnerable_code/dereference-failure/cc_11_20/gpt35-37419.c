//FormAI DATASET v1.0 Category: Log analysis ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000   // Max length of each line of log file
#define MAX_KEYWORD_LENGTH 50  // Max length of each keyword
#define MAX_KEYWORDS 10        // Max number of keywords to search for

int main(int argc, char *argv[]) {
    if(argc != (MAX_KEYWORDS + 2)) {
        fprintf(stderr, "Usage: %s filename keyword1 keyword2 ... keyword%d\n", argv[0], MAX_KEYWORDS);
        exit(1);
    }

    char *filename = argv[1];
    char *keywords[MAX_KEYWORDS];
    int i, j, k;

    // Copy keywords from command line arguments
    for(i = 0; i < MAX_KEYWORDS; i++) {
        if(argv[i+2] == NULL) {
            break;
        }
        keywords[i] = strdup(argv[i+2]);
    }

    // Open log file for reading
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        fprintf(stderr, "Cannot open file %s\n", filename);
        exit(1);
    }

    // Search for keywords and count occurrences
    char line[MAX_LINE_LENGTH];
    int keyword_counts[MAX_KEYWORDS];
    for(i = 0; i < MAX_KEYWORDS; i++) {
        keyword_counts[i] = 0;
    }

    while(fgets(line, MAX_LINE_LENGTH, fp)) {
        for(i = 0; i < MAX_KEYWORDS; i++) {
            if(keywords[i] == NULL) {
                break;
            }
            char* loc = strstr(line, keywords[i]);
            if(loc != NULL) {
                keyword_counts[i]++;
            }
        }
    }

    // Print results
    printf("Results for log file: %s\n\n", filename);
    for(i = 0; i < MAX_KEYWORDS; i++) {
        if(keywords[i] == NULL) {
            break;
        }
        printf("Keyword '%s' occurred %d times.\n", keywords[i], keyword_counts[i]);
    }

    // Cleanup
    for(i = 0; i < MAX_KEYWORDS; i++) {
        free(keywords[i]);
    }

    fclose(fp);
    return 0;
}