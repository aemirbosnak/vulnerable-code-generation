#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void edit(char* file_name) {
    FILE* file = fopen(file_name, "r+");
    char buffer[BUFFER_SIZE];
    char command[10];

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        printf("%s", buffer);
    }

    printf("\nCommand: ");
    fseek(file, 0, SEEK_SET);
    fgets(command, sizeof(command), stdin);
    char* command_split = strtok(command, " \t\n");

    if (strcmp(command_split, "write") == 0) {
        char new_line[BUFFER_SIZE];
        fgets(new_line, BUFFER_SIZE, stdin);
        strcat(buffer, new_line);
        fseek(file, strlen(buffer), SEEK_SET);
        fwrite(buffer, strlen(buffer) + 1, 1, file);
    }

    fseek(file, 0, SEEK_SET);
    fputs(buffer, file);
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: editor <filename>\n");
        return 1;
    }

    edit(argv[1]);

    return 0;
}
