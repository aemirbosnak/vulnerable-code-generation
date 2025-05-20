#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void handle_upload(char *filename, char *data) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Failed to open file\n");
        return;
    }

    // Vulnerability: No bounds checking on data length
    gets(data); // Use of gets is dangerous and can lead to buffer overflows

    fclose(file);
}

int main() {
    char filename[256];
    char data[BUFFER_SIZE];

    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);

    printf("Enter data: ");
    fgets(data, sizeof(data), stdin);

    handle_upload(filename, data);

    return 0;
}
