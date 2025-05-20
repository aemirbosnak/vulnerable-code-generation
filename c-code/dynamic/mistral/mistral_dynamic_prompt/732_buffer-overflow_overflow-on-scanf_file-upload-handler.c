#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void handle_file_upload(char *filename) {
    FILE *file = fopen(filename, "w");
    char buffer[MAX_BUFFER_SIZE];

    printf("Enter data to write to file '%s':\n", filename);
    scanf("%s", buffer);

    fputs(buffer, file);
    fclose(file);
}

int main() {
    char input[MAX_BUFFER_SIZE];

    printf("Enter the file name for the upload: ");
    scanf("%s", input);

    handle_file_upload(input);

    return 0;
}
