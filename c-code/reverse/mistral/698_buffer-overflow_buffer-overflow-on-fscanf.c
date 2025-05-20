#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 100
#define WORD_SIZE 256

void count_words(FILE *file, char *word) {
    int count[WORD_SIZE] = {0};
    char buffer[BUFFER_SIZE];
    char *token;

    while (fgets(buffer, BUFFER_SIZE, file)) {
        token = strtok(buffer, " \t\n");
        while (token) {
            strcpy(word, token);
            count[strlen(word)]++;
            token = strtok(NULL, " \t\n");
        }
    }

    for (int i = 0; i < WORD_SIZE; ++i) {
        if (count[i])
            printf("%s: %d\n", &word[i], count[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char word[WORD_SIZE];
    count_words(file, word);

    fclose(file);
    return 0;
}
