#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void handle_upload(char *filename) {
    char buffer[BUFFER_SIZE];
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file\n");
        return;
    }
    while (fgets(buffer, sizeof(buffer), file)) {
        // Simulate processing the file content
        printf("%s", buffer);
    }
    fclose(file);
}

int main() {
    char filename[256];
    printf("Enter file name: ");
    gets(filename); // Vulnerable to buffer overflow
    handle_upload(filename);
    return 0;
}
