//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_KEYWORDS 10
#define MAX_KEYWORD_LENGTH 32

typedef struct {
    char *keyword;
    int line_num;
} KeywordEntry;

void print_keyword_entries(KeywordEntry *entries, int num_entries) {
    printf("Keyword Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %d\n", entries[i].keyword, entries[i].line_num);
    }
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *keywords[MAX_NUM_KEYWORDS];
    int num_keywords = 0;
    KeywordEntry entries[MAX_NUM_KEYWORDS];
    int num_entries = 0;
    int line_num = 0;

    printf("Enter the name of the file to extract metadata from: ");
    scanf("%s", line);

    fp = fopen(line, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    printf("Enter the keywords to search for (up to %d):\n", MAX_NUM_KEYWORDS);
    for (int i = 0; i < MAX_NUM_KEYWORDS; i++) {
        scanf("%s", keywords[i]);
        num_keywords++;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        line_num++;
        for (int i = 0; i < num_keywords; i++) {
            char *pos = strstr(line, keywords[i]);
            if (pos!= NULL) {
                entries[num_entries].keyword = keywords[i];
                entries[num_entries].line_num = line_num;
                num_entries++;
            }
        }
    }

    fclose(fp);

    if (num_entries == 0) {
        printf("No keyword matches found.\n");
    } else {
        print_keyword_entries(entries, num_entries);
    }

    return 0;
}