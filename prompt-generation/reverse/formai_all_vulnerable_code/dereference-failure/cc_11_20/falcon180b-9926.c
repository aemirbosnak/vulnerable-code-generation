//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 10
#define MAX_KEYWORD_LENGTH 32

typedef struct {
    char *keyword;
    int line_number;
} Keyword;

int main(int argc, char *argv[]) {
    FILE *input_file = NULL;
    char *input_filename = argv[1];
    char *line = NULL;
    size_t line_length = 0;
    ssize_t read_bytes;
    int line_number = 1;
    int num_keywords = 0;
    Keyword keywords[MAX_KEYWORDS];

    // Open input file
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: Could not open file %s\n", input_filename);
        return 1;
    }

    // Read first line to check for metadata keywords
    read_bytes = getline(&line, &line_length, input_file);
    if (read_bytes <= 0) {
        printf("Error: Empty file\n");
        return 1;
    }

    // Check for metadata keywords
    for (int i = 0; i < num_keywords; i++) {
        if (strstr(line, keywords[i].keyword)!= NULL) {
            printf("Line %d contains metadata keyword '%s'\n", line_number, keywords[i].keyword);
        }
    }

    // Read rest of file and check for metadata keywords
    while ((read_bytes = getline(&line, &line_length, input_file))!= -1) {
        line_number++;

        // Check for metadata keywords
        for (int i = 0; i < num_keywords; i++) {
            if (strstr(line, keywords[i].keyword)!= NULL) {
                printf("Line %d contains metadata keyword '%s'\n", line_number, keywords[i].keyword);
            }
        }

        // Add new keywords to list
        if (num_keywords < MAX_KEYWORDS) {
            char *keyword = strtok(line, " ");
            while (keyword!= NULL) {
                if (strlen(keyword) <= MAX_KEYWORD_LENGTH) {
                    Keyword new_keyword;
                    strncpy(new_keyword.keyword, keyword, MAX_KEYWORD_LENGTH);
                    new_keyword.line_number = line_number;
                    keywords[num_keywords++] = new_keyword;
                }
                keyword = strtok(NULL, " ");
            }
        }
    }

    // Close input file
    fclose(input_file);

    return 0;
}