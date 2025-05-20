//Code Llama-13B DATASET v1.0 Category: Log analysis ; Style: funny
// Unique C Log Analysis Program
// in a Funny Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_SIZE 1000
#define MAX_WORD_SIZE 20

int main(void) {
    char log_file_name[20];
    char log_line[MAX_LOG_SIZE];
    char word[MAX_WORD_SIZE];
    char *log_file;
    char *token;
    int word_count = 0;
    int line_count = 0;
    int letter_count = 0;
    int i, j;

    printf("Enter the name of the log file: ");
    scanf("%s", log_file_name);

    log_file = fopen(log_file_name, "r");
    if (log_file == NULL) {
        printf("Error opening log file\n");
        exit(1);
    }

    while (fgets(log_line, MAX_LOG_SIZE, log_file) != NULL) {
        line_count++;
        token = strtok(log_line, " ");
        while (token != NULL) {
            strcpy(word, token);
            token = strtok(NULL, " ");
            word_count++;
            letter_count += strlen(word);
        }
    }

    printf("Line count: %d\n", line_count);
    printf("Word count: %d\n", word_count);
    printf("Letter count: %d\n", letter_count);

    fclose(log_file);

    return 0;
}