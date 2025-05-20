//FormAI DATASET v1.0 Category: Text Summarizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_CHARS_PER_LINE 200

void summarize(char article[][MAX_CHARS_PER_LINE], int num_lines);
void print_summary(char article[][MAX_CHARS_PER_LINE], int num_lines, int summary[]);

int main() {
    char article[MAX_LINES][MAX_CHARS_PER_LINE];
    int num_lines = 0;
    int i = 0;

    printf("Enter the article (type 'end' to stop):\n");

    // Get article from user
    while (1) {
        fgets(article[num_lines], MAX_CHARS_PER_LINE, stdin);
        article[num_lines][strlen(article[num_lines]) - 1] = '\0'; // Remove trailing newline
        if (strcmp(article[num_lines], "end") == 0) {
            break;
        }
        num_lines++;
    }

    // Call summarize function to get summary indices
    int summary[num_lines];
    summarize(article, num_lines);

    // Print summary
    printf("Summary:\n");
    print_summary(article, num_lines, summary);

    return 0;
}

void summarize(char article[][MAX_CHARS_PER_LINE], int num_lines) {
    int i, j, k;
    float scores[MAX_LINES] = {0};
    int summary[MAX_LINES] = {0};

    // Calculate scores for each sentence
    for (i = 0; i < num_lines; i++) {
        for (j = 0; j < num_lines; j++) {
            if (i == j) {
                continue;
            }
            char* word = strtok(article[i], " ");
            int word_count = 0;
            int match_count = 0;
            while (word != NULL) {
                word_count++;
                char* temp = strstr(article[j], word);
                if (temp != NULL) {
                    match_count++;
                }
                word = strtok(NULL, " ");
            }
            scores[i] += ((float)match_count / word_count);
        }
    }

    // Select top scoring sentences for summary
    for (i = 0; i < num_lines/4; i++) {
        float max_score = -1;
        int max_index = -1;
        for (j = 0; j < num_lines; j++) {
            if (scores[j] > max_score && summary[j] == 0) {
                max_score = scores[j];
                max_index = j;
            }
        }
        summary[max_index] = 1;
    }
}

void print_summary(char article[][MAX_CHARS_PER_LINE], int num_lines, int summary[]) {
    int i;
    for (i = 0; i < num_lines; i++) {
        if (summary[i]) {
            printf("%s\n", article[i]);
        }
    }
}