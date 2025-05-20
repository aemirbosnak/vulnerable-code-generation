#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void edit_text(char *buffer, int size) {
    char input[BUFFER_SIZE];
    printf("Editor: type 'exit' to quit\n");
    while (1) {
        printf("> ");
        if (fgets(input, sizeof(input), stdin) == NULL) break;
        if (strcmp(input, "exit\n") == 0) break;
        if (input[0] != '\n') {
            strncat(buffer, input, size - strlen(buffer) - 1);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r+");
    if (file == NULL) {
        file = fopen(argv[1], "w+");
        if (file == NULL) {
            perror("Failed to open file");
            return EXIT_FAILURE;
        }
    }

    fseek(file, 0L, SEEK_END);
    long length = ftell(file);
    char *buffer = malloc(length + 1);
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        fclose(file);
        return EXIT_FAILURE;
    }

    fseek(file, 0L, SEEK_SET);
    fread(buffer, 1, length, file);

    buffer[length] = '\0';

    edit_text(buffer, BUFFER_SIZE);

    fseek(file, 0L, SEEK_SET);
    fwrite(buffer, 1, strlen(buffer), file);
    ftruncate(fileno(file), strlen(buffer));

    free(buffer);
    fclose(file);

    return EXIT_SUCCESS;
}
