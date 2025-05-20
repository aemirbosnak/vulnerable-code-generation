//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    regex_t regex;
    int reti;
    size_t len = 0;
    regmatch_t match;

    reti = regcomp(&regex, "\\b[a-zA-Z]+\\b\\s*", REG_EXTENDED | REG_NEWLINE);
    if (reti) {
        regfree(&regex);
        perror("Regex compilation failed");
        fclose(file);
        return 1;
    }

    int word_count = 0;
    while (fgets(buffer, BUFFER_SIZE, file)) {
        size_t nmatch = 0;
        reti = regexec(&regex, buffer, 1, &match, REG_NOTEOL);
        if (reti == 0 && match.rm_so > 0) {
            word_count++;
            size_t start = match.rm_so - 1;
            while (buffer[--start] != '\n' && start >= 0);
            buffer[start + 1] = '\0';
        }
    }

    fclose(file);
    regfree(&regex);

    printf("Word count: %d\n", word_count);

    return 0;
}