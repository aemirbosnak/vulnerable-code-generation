#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void edit(char *filename) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char command[10];
    int i;

    file = fopen(filename, "r+");
    if (!file) {
        printf("Error: Unable to open file.\n");
        return;
    }

    printf("Text Editor\n");
    while (1) {
        printf("\nFilename: %s\n", filename);
        printf("\nRead - r\nWrite - w\nQuit - q\n");
        fgets(command, sizeof(command), stdin);
        sscanf(command, "%s", command);

        if (strcmp(command, "r") == 0) {
            fseek(file, 0, SEEK_SET);
            fgets(buffer, BUFFER_SIZE, file);
            printf("%s", buffer);
        } else if (strcmp(command, "w") == 0) {
            fseek(file, 0, SEEK_SET);
            fgets(buffer, BUFFER_SIZE, stdin);
            fputs(buffer, file);
        } else if (strcmp(command, "q") == 0) {
            break;
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: text_editor <filename>\n");
        return 1;
    }

    edit(argv[1]);

    return 0;
}
