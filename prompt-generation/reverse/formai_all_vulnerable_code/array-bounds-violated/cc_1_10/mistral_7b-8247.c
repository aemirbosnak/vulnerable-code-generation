//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Define the CRC constants
#define CRC_INIT 0xFFFFFFFF
#define CRC_POLY 0xEDB88320

// Function to perform bitwise XOR between two 32-bit numbers
#define XOR(a, b) ((a) ^ (b))

// Function to perform left rotation of a 32-bit number by a given number of bits
#define ROTL(value, shift) (((value) << (shift)) | ((value) >> (32 - (shift))))

// CRC calculation function
void calculate_crc32(const uint8_t *data, size_t size, uint32_t crc) {
    size_t i;

    for (i = 0; i < size; i++) {
        uint8_t byte = data[i];

        // Calculate the CRC for each byte in the data
        for (size_t j = 0; j < 8; j++) {
            if (XOR(ROTL(crc, 1), byte & 0x01)) {
                crc = XOR(crc, CRC_POLY);
            }
            byte >>= 1;
        }
    }
}

// Function to print the hexadecimal representation of a 32-bit number
void print_hex(uint32_t number) {
    char hex[32];
    int index = 31;

    hex[32] = '\0';

    // Convert the number to hexadecimal and print it
    while (number != 0) {
        int digit = number % 16;

        if (digit < 10) {
            hex[index--] = '0' + digit;
        } else {
            hex[index--] = 'A' + (digit - 10);
        }

        number /= 16;
    }

    printf("%s\n", &hex[0]);
}

// Main function
int main() {
    const uint8_t test_data[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77};
    const size_t test_data_size = sizeof(test_data);
    uint32_t crc = CRC_INIT;

    // Calculate the checksum for the test data
    calculate_crc32(test_data, test_data_size, crc);

    // Print the checksum in hexadecimal format
    printf("Checksum: ");
    print_hex(crc);

    return 0;
}