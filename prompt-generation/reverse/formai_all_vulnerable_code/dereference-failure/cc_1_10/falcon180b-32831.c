//Falcon-180B DATASET v1.0 Category: Text processing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove leading and trailing whitespaces from a string
char *trim(char *str) {
    char *end;

    // Trim leading spaces
    while (isspace(*str))
        str++;

    if (*str == 0) // All spaces
        return str;

    // Trim trailing spaces
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end))
        end--;

    // Add null terminator
    *++end = '\0';

    return str;
}

// Function to split a string into words
char **split(char *str) {
    int count = 0;
    char **words = NULL;
    char *word = strtok(str, " \t\n\r\f\v");

    while (word!= NULL) {
        words = realloc(words, sizeof(char *) * ++count);
        words[count-1] = trim(word);
        word = strtok(NULL, " \t\n\r\f\v");
    }

    return words;
}

// Function to reverse a string
char *reverse(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;

    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }

    return str;
}

// Function to print words in reverse order
void print_reverse(char **words) {
    int i;

    for (i = 0; words[i]!= NULL; i++) {
        printf("%s ", words[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    char **words = split(input);
    char *reversed_input = reverse(input);
    print_reverse(words);

    for (int i = 0; words[i]!= NULL; i++) {
        printf("%s ", words[i]);
    }

    printf("\nReversed input: %s\n", reversed_input);

    return 0;
}