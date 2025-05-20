//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000

typedef struct {
    char line[MAX_LINE_LENGTH];
    int line_number;
} log_line;

int main() {
    FILE *log_file;
    log_line log[MAX_LINES];
    int num_lines = 0;
    int line_number = 0;
    char keyword[MAX_LINE_LENGTH];
    int keyword_found = 0;
    int keyword_line_number = 0;
    int keyword_count = 0;

    log_file = fopen("example.log", "r");

    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    while (!feof(log_file)) {
        if (num_lines >= MAX_LINES) {
            printf("Error: Log file is too large.\n");
            exit(1);
        }

        if (fgets(log[num_lines].line, MAX_LINE_LENGTH, log_file) == NULL) {
            printf("Error: Could not read line from log file.\n");
            exit(1);
        }

        num_lines++;
        line_number++;
    }

    printf("Enter keyword to search for: ");
    scanf("%s", keyword);

    for (int i = 0; i < num_lines; i++) {
        if (strstr(log[i].line, keyword)!= NULL) {
            keyword_found = 1;
            keyword_line_number = line_number - num_lines + i + 1;
            keyword_count++;
        }
    }

    if (keyword_found) {
        printf("Keyword '%s' found in log file.\n", keyword);
        printf("Keyword appears on line(s): ");
        for (int i = 0; i < keyword_count; i++) {
            printf("%d ", keyword_line_number);
        }
        printf("\n");
    } else {
        printf("Keyword '%s' not found in log file.\n", keyword);
    }

    fclose(log_file);

    return 0;
}