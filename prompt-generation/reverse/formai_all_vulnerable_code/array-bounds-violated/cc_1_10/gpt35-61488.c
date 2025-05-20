//FormAI DATASET v1.0 Category: Spam Detection System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 200

// Function prototypes
int count_words(char *line);
int count_special_chars(char *line);
int detect_spam(char *line);

int main() {
    // Arrays to store the lines of text
    char lines[MAX_LINES][MAX_LENGTH];
    char line[MAX_LENGTH];

    // Read lines of text from user
    printf("Enter message:\n");
    int line_count = 0;
    while (fgets(line, MAX_LENGTH, stdin) != NULL) {
        // check if maximum lines have been reached
        if (line_count >= MAX_LINES) {
            printf("Maximum lines reached. Spam detection in progress...\n");
            break;
        }
        // remove newline character from line
        line[strlen(line)-1] = '\0';
        strcpy(lines[line_count], line);
        line_count++;
    }

    // Check each line for spam
    printf("Spam detection results:\n");
    for (int i = 0; i < line_count; i++) {
        int is_spam = detect_spam(lines[i]);
        if (is_spam) {
            printf("Line %d: Spam detected!\n", i+1);
        } else {
            printf("Line %d: Not spam.\n", i+1);
        }
    }

    return 0;
}

// Counts the number of words in a given line
int count_words(char *line) {
    int count = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Counts the number of special characters in a given line
int count_special_chars(char *line) {
    int count = 0;
    for (int i = 0; i < strlen(line); i++) {
        if ((line[i] < '0' || line[i] > '9') &&
            (line[i] < 'A' || line[i] > 'Z') &&
            (line[i] < 'a' || line[i] > 'z') &&
            (line[i] != ' ')) {
            count++;
        }
    }
    return count;
}

// Detects whether a given line is spam
int detect_spam(char *line) {
    int word_count = count_words(line);
    int special_count = count_special_chars(line);
    if (word_count > 10 || special_count > 5) {
        return 1;
    } else {
        return 0;
    }
}