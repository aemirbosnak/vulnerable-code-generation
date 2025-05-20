//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 256

void get_summary(char lines[MAX_LINES][MAX_LINE_LENGTH], int num_lines, char *summary) {
    int summary_index = 0;
    int word_count = 0;

    for (int i = 0; i < num_lines; i++) {
        char *token = strtok(lines[i], " ");
        while (token != NULL) {
            word_count++;
            if (word_count % 5 == 0) { // Capture every 5th word for summary
                if (summary_index + strlen(token) + 1 < MAX_LINE_LENGTH) {
                    if (summary_index > 0) {
                        summary[summary_index++] = ' '; // Add space before next word
                    }
                    strcpy(&summary[summary_index], token);
                    summary_index += strlen(token);
                }
            }
            token = strtok(NULL, " ");
        }
    }
    summary[summary_index] = '\0'; // Null-terminate the summary string
}

void read_lines(char lines[MAX_LINES][MAX_LINE_LENGTH], int *num_lines) {
    printf("Enter the number of lines to summarize (max %d): ", MAX_LINES);
    scanf("%d", num_lines);
    getchar(); // Consume newline character after the number input

    if (*num_lines > MAX_LINES) {
        *num_lines = MAX_LINES;
    }
    printf("Enter the text, line by line (Ctrl+D to end input):\n");

    for (int i = 0; i < *num_lines; i++) {
        if (fgets(lines[i], MAX_LINE_LENGTH, stdin) == NULL) {
            break; // Stop if there's an input error
        }
        lines[i][strcspn(lines[i], "\n")] = 0; // Remove newline character
    }
}

void display_summary(const char *summary) {
    printf("\n--- Summary ---\n%s\n", summary);
}

int main() {
    char lines[MAX_LINES][MAX_LINE_LENGTH];
    char summary[MAX_LINE_LENGTH];
    int num_lines;

    printf("Welcome to the Sherlock Holmes Text Summarizer!\n");
    read_lines(lines, &num_lines);
    
    get_summary(lines, num_lines, summary);
    display_summary(summary);
    
    return 0;
}