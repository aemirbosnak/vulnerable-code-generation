#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

typedef struct {
    uint8_t id[4];
    uint32_t size;
} Header;

int main(int argc, char **argv) {
    int fd, offset = 0;
    char buffer[BUFFER_SIZE];
    Header header;

    fd = open(argv[1], O_RDONLY);
    while ((read(fd, buffer + offset, BUFFER_SIZE)) > 0) {
        memcpy(&header, buffer + offset, sizeof(Header));
        printf("Decoding audio stream with ID %02X%02X%02X%02X\n", header.id[0], header.id[1], header.id[2], header.id[3]);
        printf("Audio data size: %u\n", header.size);

        uint8_t *data = malloc(header.size);
        memcpy(data, buffer + offset + sizeof(Header), header.size);

        // Dereference invalid pointer to trigger UB
        for (int i = 0; i < header.size; i++) {
            printf("%d: %02X\n", i, data[-1]);
        }

        free(data);
        offset += BUFFER_SIZE + sizeof(Header);
    }

    return 0;
}
