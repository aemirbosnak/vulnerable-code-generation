//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024

/* Function to print error message and exit program */
void die(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

/* Function to read input from file or stdin */
char *read_input(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    /* Read input line by line */
    while ((read = getline(&line, &len, fp))!= -1) {
        if (read == 0) {
            /* Reallocate buffer to remove trailing newline */
            line[--len] = '\0';
        }
    }

    return line;
}

/* Function to count words in input */
int count_words(const char *input) {
    int count = 0;
    char *token;

    /* Tokenize input string */
    token = strtok(input, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char *input;
    int word_count;

    /* Check if correct number of arguments are provided */
    if (argc!= 2) {
        die("Incorrect number of arguments. Usage:./program <filename>");
    }

    /* Open input file */
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        die("Failed to open file");
    }

    /* Read input from file */
    input = read_input(fp);
    if (input == NULL) {
        die("Failed to read input");
    }

    /* Count words in input */
    word_count = count_words(input);

    /* Print word count */
    printf("The input contains %d words.\n", word_count);

    /* Clean up */
    free(input);
    fclose(fp);

    return 0;
}