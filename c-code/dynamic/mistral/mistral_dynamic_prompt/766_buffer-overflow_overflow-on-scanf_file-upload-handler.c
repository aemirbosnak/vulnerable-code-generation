#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char input[MAX_BUFFER_SIZE];
    char fileName[MAX_BUFFER_SIZE];
    FILE *file;

    printf("Upload a file: ");
    scanf("%s", input);

    strcpy(fileName, input);
    file = fopen(fileName, "rb");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", fileName);
        return 1;
    }

    char buffer[MAX_BUFFER_SIZE];
    while (fread(buffer, 1, MAX_BUFFER_SIZE, file)) {
        // process the file contents here (you didn't ask for that)
    }

    fclose(file);

    return 0;
}
