#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 256
#define MAX_FILE_LEN 1024 * 1024

void process_file(char* filename) {
    FILE* file = fopen(filename, "rb");
    char buffer[MAX_FILE_LEN];

    if (!file) {
        printf("Error: Could not open file.\n");
        return;
    }

    size_t read = fread(buffer, 1, sizeof(buffer) - 1, file);
    buffer[read] = '\0';

    printf("File content:\n%s\n", buffer);

    fclose(file);
}

int main(int argc, char* argv[]) {
    char name[MAX_NAME_LEN];

    printf("Upload a file (up to %d characters):\n", MAX_NAME_LEN);
    gets(name);

    if (strlen(name) > MAX_NAME_LEN) {
        printf("File name is too long.\n");
        return 1;
    }

    process_file(name);

    return 0;
}
