#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 2048

void readFile(const char *fileName, char *buffer) {
    FILE *file = fopen(fileName, "r");
    fgets(buffer, MAX_LINE, file);
    fclose(file);
}

void writeFile(const char *fileName, const char *buffer) {
    FILE *file = fopen(fileName, "w");
    fprintf(file, "%s", buffer);
    fclose(file);
}

void edit(const char *fileName, char *command) {
    char buffer[MAX_LINE];
    readFile(fileName, buffer);

    char *ptr = strstr(buffer, command);
    if (ptr != NULL) {
        // Out of bounds read vulnerability here: accessing memory beyond the command
        printf("Accessing memory beyond the command: %p\n", ptr + strlen(command));
    }

    char newBuffer[2 * MAX_LINE];
    strcpy(newBuffer, buffer);

    writeFile(fileName, newBuffer);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: text_editor old_file new_content\n");
        return 1;
    }

    edit(argv[1], argv[2]);

    return 0;
}
