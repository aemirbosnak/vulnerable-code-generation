//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 100
#define MAX_KEYWORD_LENGTH 100

typedef struct {
    char *name;
    int length;
    int found;
} Keyword;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    Keyword keywords[MAX_KEYWORDS];
    int num_keywords = 0;

    printf("Enter the keywords to detect (enter 'done' when finished):\n");
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (strcmp(line, "done") == 0) {
            break;
        }
        int length = strlen(line);
        if (length > MAX_KEYWORD_LENGTH) {
            printf("Error: Keyword is too long.\n");
            continue;
        }
        keywords[num_keywords].name = malloc(length + 1);
        strcpy(keywords[num_keywords].name, line);
        keywords[num_keywords].length = length;
        num_keywords++;
    }

    char *buffer = malloc(MAX_LINE_LENGTH);
    int buffer_length = 0;
    int in_keyword = 0;
    int keyword_index = 0;

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        int line_length = strlen(line);
        for (int i = 0; i < line_length; i++) {
            char c = tolower(line[i]);
            if (isalpha(c)) {
                if (in_keyword) {
                    if (buffer_length >= keywords[keyword_index].length) {
                        if (strncmp(buffer, keywords[keyword_index].name, keywords[keyword_index].length) == 0) {
                            fprintf(output_file, "Keyword found: %s\n", keywords[keyword_index].name);
                            keywords[keyword_index].found = 1;
                        }
                        in_keyword = 0;
                    }
                } else {
                    if (buffer_length == 0) {
                        strcpy(buffer, &line[i]);
                        buffer_length = 1;
                    } else {
                        strcat(buffer, &line[i]);
                        buffer_length++;
                    }
                }
            } else {
                if (in_keyword) {
                    in_keyword = 0;
                }
            }
        }
        if (in_keyword) {
            strcat(buffer, "\n");
            fprintf(output_file, "Keyword found: %s\n", buffer);
            keywords[keyword_index].found = 1;
        }
        in_keyword = 0;
        buffer_length = 0;
        keyword_index++;
        if (keyword_index >= num_keywords) {
            keyword_index = 0;
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}