#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void edit(char *file) {
    char buffer[BUFFER_SIZE];
    char command[10];
    FILE *filePtr;

    if ((filePtr = fopen(file, "r+")) == NULL) {
        printf("Error: Cannot open file.\n");
        return;
    }

    while (1) {
        printf("\n%s\n", file);
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = '\0'; // Remove newline character

        if (strcmp(command, "save") == 0) {
            fseek(filePtr, 0, SEEK_SET);
            fputs(buffer, filePtr);
            fclose(filePtr);
            return;
        } else if (strcmp(command, "exit") == 0) {
            fclose(filePtr);
            return;
        } else if (strcmp(command, "insert") == 0) {
            printf("Insert text: ");
            fgets(buffer, BUFFER_SIZE, stdin);
            int len = strlen(buffer);

            // Dereference failure vulnerability
            strcpy(buffer + strlen(buffer) - 1, "A"); // Overwriting last character with 'A'
            fseek(filePtr, ftell(filePtr), SEEK_SET);
            fwrite(buffer, sizeof(char), strlen(buffer) + len + 1, filePtr);
        } else {
            printf("Unknown command.\n");
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    edit(argv[1]);
    return 0;
}
