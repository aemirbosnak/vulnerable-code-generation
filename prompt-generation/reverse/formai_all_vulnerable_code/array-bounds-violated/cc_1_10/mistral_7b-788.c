//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: mathematical
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 1024
#define CHECKSUM_SIZE 4

typedef struct {
    uint32_t sum_low;
    uint32_t sum_high;
} checksum_t;

void process_block(const void *buffer, checksum_t *sum);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    checksum_t checksum = {0, 0};
    char buffer[BLOCK_SIZE];

    while (true) {
        size_t bytes_read = fread(buffer, 1, BLOCK_SIZE, file);
        if (bytes_read == 0) {
            break;
        }

        process_block(buffer, &checksum);
    }

    fclose(file);

    printf("Checksum: ");
    uint8_t checksum_bytes[CHECKSUM_SIZE];
    checksum_bytes[0] = (uint8_t) (checksum.sum_high >> 24);
    checksum_bytes[1] = (uint8_t) (checksum.sum_high >> 16);
    checksum_bytes[2] = (uint8_t) (checksum.sum_high >> 8);
    checksum_bytes[3] = (uint8_t) checksum.sum_high;
    checksum_bytes[4] = (uint8_t) (checksum.sum_low >> 24);
    checksum_bytes[5] = (uint8_t) (checksum.sum_low >> 16);
    checksum_bytes[6] = (uint8_t) (checksum.sum_low >> 8);
    checksum_bytes[7] = (uint8_t) checksum.sum_low;

    for (size_t i = 0; i < CHECKSUM_SIZE; i++) {
        printf("%02X", checksum_bytes[i]);
    }
    printf("\n");

    return 0;
}

void process_block(const void *buffer, checksum_t *sum) {
    const uint8_t *data = (const uint8_t *) buffer;

    for (size_t i = 0; i < BLOCK_SIZE; i++) {
        uint32_t old_sum = sum->sum_low;
        sum->sum_low = old_sum ^ data[i];
        sum->sum_high += old_sum < sum->sum_low ? (uint32_t) 1 : 0;
    }
}