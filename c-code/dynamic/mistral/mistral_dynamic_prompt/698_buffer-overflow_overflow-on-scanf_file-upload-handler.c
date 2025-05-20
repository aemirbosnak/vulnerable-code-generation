#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    FILE *file;
    char *filename;

    printf("Upload a file: ");
    scanf("%s", buffer);

    filename = malloc(strlen(buffer) + 1);
    strcpy(filename, buffer);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    char fileContent[BUFFER_SIZE];
    fread(fileContent, sizeof(char), BUFFER_SIZE, file);

    printf("File content:\n");
    printf("%s\n", fileContent);

    fclose(file);
    free(filename);

    return 0;
}
