//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024 * 1024 // 1MB
#define MAX_WORD_SIZE 64

// Function to split a string into words
void split_string(char *str, char *words[]) {
    char *token = strtok(str, " ");
    int count = 0;
    while (token!= NULL) {
        if (count >= MAX_WORD_SIZE) {
            break;
        }
        words[count] = token;
        count++;
        token = strtok(NULL, " ");
    }
}

// Function to read a log file into memory
char *read_log_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open log file\n");
        exit(1);
    }
    char *buffer = malloc(MAX_LOG_SIZE);
    fread(buffer, 1, MAX_LOG_SIZE, file);
    fclose(file);
    return buffer;
}

// Function to analyze the log file
void analyze_log_file(char *buffer) {
    char *line = strtok(buffer, "\n");
    while (line!= NULL) {
        char *request_type = strtok(line, " ");
        if (strcmp(request_type, "GET") == 0 || strcmp(request_type, "POST") == 0) {
            char *url = strtok(NULL, " ");
            printf("Request type: %s\nURL: %s\n", request_type, url);
        }
        line = strtok(NULL, "\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }
    char *buffer = read_log_file(argv[1]);
    analyze_log_file(buffer);
    free(buffer);
    return 0;
}