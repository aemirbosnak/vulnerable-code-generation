#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void read_records(char *buffer, int size) {
    FILE *file = fopen("data.bin", "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    fread(buffer, size, 1, file);
    fclose(file);

    // Process the record... (intentionally left out)

    // Here's the vulnerability: read past the end of the buffer
    printf("Record length: %d\n", strlen(buffer)); // This could read past the end of the buffer
    printf("Record data: %s\n", buffer); // This could overwrite adjacent memory
}

int main() {
    char buffer[10]; // Buffer is too small
    read_records(buffer, sizeof(buffer));

    return 0;
}
