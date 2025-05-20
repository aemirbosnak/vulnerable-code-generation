//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: immersive
#include <stdio.h>
#include <stdint.h>

#define POLY    0x04C11DB7      // CRC-32 polynomial
#define SIZE    1024            // Buffer size in bytes

uint32_t crc_table[256];        // Table of precomputed CRC32 values

/**
 * generate_crc_table()
 * Generates a table of all possible CRC32 values for a byte
 **/
void generate_crc_table() {
    uint32_t crc, data;
    int i, j;
    for (i = 0; i < 256; i++) {
        crc = i << 24;
        for (j = 0; j < 8; j++) {
            if (crc & 0x80000000) {
                crc = (crc << 1) ^ POLY;
            } else {
                crc = (crc << 1);
            }
        }
        crc_table[i] = crc;
    }
}

/**
 * calculate_crc()
 * Calculates the CRC32 checksum for a given byte array
 **/
uint32_t calculate_crc(uint8_t *data, int size) {
    uint32_t crc = 0xFFFFFFFF;
    int i, shift;
    for (i = 0; i < size; i++) {
        shift = (crc >> 24) ^ data[i];
        crc = (crc << 8) ^ crc_table[shift];
    }
    return ~crc;
}

int main() {
    generate_crc_table();       // Generate the CRC32 table
    
    uint8_t buffer[SIZE];       // Buffer to hold input data
    int count;                  // Number of bytes read
    uint32_t checksum;          // Calculated CRC32 value
    
    printf("Enter data to calculate CRC32 checksum:\n");
    count = fread(buffer, 1, SIZE, stdin);     // Read input data from standard input
    checksum = calculate_crc(buffer, count);  // Calculate the CRC32 checksum
    
    printf("CRC32 checksum is: 0x%X\n", checksum);
    return 0;
}