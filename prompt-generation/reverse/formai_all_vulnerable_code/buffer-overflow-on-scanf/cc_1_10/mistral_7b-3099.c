//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: immersive
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 1024
#define BUFFER_SIZE (BLOCK_SIZE + sizeof(uint32_t))

typedef struct {
    uint8_t buffer[BUFFER_SIZE];
    uint32_t checksum;
} checksum_buffer;

void checksum_update(checksum_buffer* buffer, uint32_t data) {
    buffer->checksum = (buffer->checksum << 1) ^ ((buffer->checksum & 0x80000000) ? ~(data & 0xFFFFFFFF) : data);
    memcpy(buffer->buffer, &data, sizeof(data));
    while (sizeof(data) < BLOCK_SIZE) {
        data = fgetc(stdin);
        checksum_update(buffer, data);
    }
}

int main() {
    checksum_buffer buffer;
    buffer.checksum = 0xFFFFFFFF;

    printf("Welcome to the C Checksum Calculator, the most immersive checksum calculator in the world!\n");
    printf("To calculate the checksum of a file, simply type the name of the file followed by enter.\n");
    printf("The checksum will be displayed in hexadecimal format.\n\n");

    char filename[256];
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    size_t bytes_read;
    while ((bytes_read = fread(buffer.buffer, 1, BLOCK_SIZE, file)) > 0) {
        checksum_update(&buffer, bytes_read);
    }

    fclose(file);

    printf("\nChecksum: %08X\n", buffer.checksum);

    return 0;
}