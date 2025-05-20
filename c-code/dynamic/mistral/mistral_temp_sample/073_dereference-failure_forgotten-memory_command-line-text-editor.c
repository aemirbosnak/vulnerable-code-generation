#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void read_line(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

void print_buffer(char *buffer) {
    printf("%s\n", buffer);
}

void append_buffer(char *buffer1, char *buffer2) {
    strcat(buffer1, buffer2);
}

int main() {
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    char *cursor = buffer;

    while (1) {
        print_buffer(buffer);
        read_line(command, BUFFER_SIZE);

        if (strcmp(command, "save") == 0) {
            FILE *file = fopen("file.txt", "w");
            fprintf(file, "%s", buffer);
            fclose(file);
            break;
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            append_buffer(cursor, command);
        }
    }

    char *file_content = malloc(sizeof(char) * BUFFER_SIZE);
    file_content = fgets(file_content, BUFFER_SIZE, "file.txt");
    printf("%s\n", file_content);

    free(file_content);

    return 0;
}
