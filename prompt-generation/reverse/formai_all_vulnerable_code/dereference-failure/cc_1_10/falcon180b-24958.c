//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to count frequency of each character in a string
void count_frequency(char *string, int *frequency) {
    int i = 0;
    for (i = 0; string[i]!= '\0'; i++) {
        frequency[tolower(string[i])]++;
    }
}

// function to check if a string is spam
int is_spam(char *string, int *frequency) {
    int i = 0;
    int spam_count = 0;
    for (i = 0; string[i]!= '\0'; i++) {
        if (frequency[tolower(string[i])] > 3) {
            spam_count++;
        }
    }
    if (spam_count >= 3) {
        return 1;
    } else {
        return 0;
    }
}

// function to read input from file
char *read_input_file(FILE *file) {
    char *input = NULL;
    char c;
    int i = 0;
    while ((c = fgetc(file))!= EOF) {
        input = realloc(input, i + 2);
        input[i++] = c;
        input[i] = '\0';
    }
    return input;
}

// main function
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage:./spam_detection_system input_file\n");
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }
    char *input = read_input_file(file);
    int frequency[26] = {0}; // initialize frequency array for 26 letters
    count_frequency(input, frequency); // count frequency of each character
    if (is_spam(input, frequency)) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }
    free(input);
    fclose(file);
    return 0;
}