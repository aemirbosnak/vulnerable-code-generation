#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void handle_file(char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[BUFFER_SIZE];
    if (!file) {
        perror("Error opening file");
        return;
    }

    printf("Uploading %s...\n", filename);
    size_t bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file);
    fclose(file);

    // Buffer overflow vulnerability: no bounds checking on scanf
    char input[10];
    printf("Enter a password to verify: ");
    scanf("%s", input);

    // Do something with the password...
    printf("Verification successful.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    handle_file(argv[1]);
    return 0;
}
