#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 100

void edit(char *filename) {
    FILE *file = fopen(filename, "r+");
    char buffer[BUFFER_SIZE];
    char command[30];

    if (!file) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    fseek(file, 0, SEEK_SET);
    while (fgets(buffer, BUFFER_SIZE, file)) {
        printf("%s", buffer);
    }

    printf("\n> ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = '\0';

    if (strcmp(command, "exit") == 0) {
        fseek(file, 0, SEEK_SET);
        return;
    }

    if (strlen(command) > BUFFER_SIZE - 1) {
        printf("Command too long.\n");
        return;
    }

    char *new_buffer = (char *)malloc(strlen(buffer) + strlen(command) + 1);
    strcpy(new_buffer, buffer);
    strcat(new_buffer, command);

    fseek(file, 0, SEEK_SET);
    fputs(new_buffer, file);
    free(new_buffer);

    fseek(file, 0, SEEK_SET);
    printf("\n");
    system("clear"); // or use fflush(stdin) on Windows
    edit(filename);
}

int main() {
    char filename[50];

    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    edit(filename);

    return 0;
}
