#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void handle_file(char *filename) {
    FILE *file = fopen(filename, "w");
    char buffer[MAX_SIZE];

    printf("Enter file content (CTRL+D to stop):\n");
    gets(buffer);

    fputs(buffer, file);
    fclose(file);
}

int main() {
    char command[MAX_SIZE];
    printf("Enter filename to save the file:\n");
    gets(command);

    handle_file(command);
    printf("File saved successfully.\n");
    return 0;
}
