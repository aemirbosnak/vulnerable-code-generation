//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_SUMMARIES 10
#define SUMMARY_LENGTH 100

struct summary {
    char text[SUMMARY_LENGTH];
    int length;
};

int main(int argc, char *argv[]) {
    FILE *input_file;
    char line[MAX_LINE_LENGTH];
    int line_count = 0;
    int summary_count = 0;
    struct summary summaries[MAX_SUMMARIES];

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        line_count++;
        if (summary_count >= MAX_SUMMARIES) {
            break;
        }
        int word_count = 0;
        char *word = strtok(line, " ");
        while (word!= NULL) {
            if (word_count >= SUMMARY_LENGTH) {
                break;
            }
            strncat(summaries[summary_count].text, word, SUMMARY_LENGTH - summaries[summary_count].length);
            summaries[summary_count].length += strlen(word);
            word_count++;
            word = strtok(NULL, " ");
        }
        summary_count++;
    }

    printf("Line count: %d\n", line_count);
    printf("Summary count: %d\n", summary_count);

    for (int i = 0; i < summary_count; i++) {
        printf("Summary %d: %s\n", i + 1, summaries[i].text);
    }

    fclose(input_file);
    return 0;
}