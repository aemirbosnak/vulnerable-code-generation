//Falcon-180B DATASET v1.0 Category: Error handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

#define MAX_LINE_SIZE 1024

// Function to handle errors
void handle_error(int signum) {
    if (signum == SIGSEGV) {
        printf("Segmentation fault occurred\n");
    } else if (signum == SIGINT) {
        printf("Interrupted by user\n");
    } else if (signum == SIGABRT) {
        printf("Abort signal received\n");
    } else {
        printf("Unknown signal %d received\n", signum);
    }
    exit(1);
}

// Function to read a line from standard input
char *read_line(void) {
    char *line = NULL;
    size_t length = 0;
    ssize_t read;

    line = malloc(MAX_LINE_SIZE);
    if (line == NULL) {
        printf("Error: could not allocate memory for line\n");
        exit(1);
    }

    read = getline(&line, &length, stdin);
    if (read == -1) {
        printf("Error: could not read line from standard input\n");
        exit(1);
    }

    line[read - 1] = '\0';

    return line;
}

// Function to count the number of words in a line
int count_words(char *line) {
    int count = 0;
    char *word;

    word = strtok(line, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    return count;
}

// Main function
int main(void) {
    char *line;
    int count;

    signal(SIGSEGV, handle_error);
    signal(SIGINT, handle_error);
    signal(SIGABRT, handle_error);

    while (1) {
        line = read_line();
        count = count_words(line);
        printf("The line has %d words\n", count);
        free(line);
    }

    return 0;
}