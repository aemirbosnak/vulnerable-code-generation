//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// Creative struct for checksum calculation
typedef struct {
    uint16_t sum;
    const uint8_t *buf;
} checksum_t;

// Relaxed function to calculate checksum using Adler-32 algorithm
void adler32(checksum_t *cs, size_t size) {
    const uint16_t ONE = 0x0001;
    const uint16_t FIVE_THOUSAND_FIFTY_THREE = 0x5555;
    const uint16_t A = 0x6587;
    const uint16_t B = 0x812C;

    cs->sum = A;
    cs->sum += B;

    while (size--) {
        uint8_t b = *cs->buf++;
        uint16_t s1 = cs->sum & 0xFFFF;
        uint16_t s2 = s1 + b;
        s1 = s1 >> 16;
        s2 += s1;
        s1 = s2 & 0xFFFF;
        s2 = (s2 >> 16) + s1;

        cs->sum = s2 << 16 | s1;
    }

    cs->sum += (cs->sum >> 16) & FIVE_THOUSAND_FIFTY_THREE;
    cs->sum += FIVE_THOUSAND_FIFTY_THREE;
}

// Calm and collected function to print binary data and checksum
void print_data_and_checksum(const char *data, size_t size) {
    checksum_t cs;
    cs.buf = (const uint8_t *) data;

    adler32(&cs, size);

    printf("Data: ");
    for (size_t i = 0; i < size; ++i) {
        if ((i + 1) % 16 == 0 || i == size - 1) {
            if (i > 0)
                printf("\n   ");
            printf("%02X", data[i]);
        } else {
            printf("%02X ", data[i]);
        }
    }

    printf("\nChecksum: %04X\n", cs.sum);
}

int main() {
    // Calm and composed data to calculate checksum
    const char data[] = "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0A\x0B\x0C\x0D\x0E\x0F";

    // Chill and relaxed main function
    printf("Calculating checksum for the following data:\n");
    print_data_and_checksum(data, sizeof(data));

    return EXIT_SUCCESS;
}