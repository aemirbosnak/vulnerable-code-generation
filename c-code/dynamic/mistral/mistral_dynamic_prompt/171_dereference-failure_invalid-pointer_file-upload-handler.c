#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

void process_file(FILE *fp) {
    char buffer[MAX_LENGTH];
    char *user_input;
    size_t num_chars;

    if (!(user_input = (char *) malloc(MAX_LENGTH))) {
        perror("Memory allocation failure");
        return;
    }

    while ((num_chars = fread(buffer, sizeof(char), MAX_LENGTH, fp)) > 0) {
        strncat(user_input, buffer, num_chars);
    }

    // Dereference failure vulnerability here
    printf("%s\n", user_input[MAX_LENGTH]);

    free(user_input);
}

int main(int argc, char *argv[]) {
    FILE *file;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        perror("File opening failure");
        return 1;
    }

    process_file(file);
    fclose(file);

    return 0;
}
