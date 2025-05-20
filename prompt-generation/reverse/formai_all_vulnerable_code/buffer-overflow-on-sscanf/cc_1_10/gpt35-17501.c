//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: scientific
/*
 *  C Checksum Calculator
 * 
 *  This program calculates the checksum of a file and
 *  verifies whether the given checksum matches the
 *  calculated checksum.
 *
 *  The checksum of a file is calculated by summing up
 *  the byte values of all the bytes in the file. If the
 *  result is too large to fit in a byte, the sum is
 *  truncated to 8 bits by discarding the high-order
 *  bits.
 *
 *  A checksum is often used to detect errors in data
 *  transmission or storage. If the checksum calculated
 *  from the received data does not match the expected
 *  checksum, it indicates that an error has occurred.
 *
 *  This program takes the name of the file and the
 *  expected checksum as command-line arguments. It 
 *  calculates the checksum of the file and compares it
 *  with the expected checksum to determine whether the
 *  file has been corrupted.
 *
 *  Author: John Doe
 *  Version: 1.0
 *  Date: 2021-06-01
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: checksum <file> <expected_checksum>\n");
        exit(1);
    }

    FILE *fp;
    fp = fopen(argv[1], "rb");

    if (fp == NULL) {
        printf("Error: cannot open file %s\n", argv[1]);
        exit(1);
    }

    unsigned char checksum = 0;
    int byte_count = 0;
    int byte;

    while ((byte = fgetc(fp)) != EOF) {
        checksum += (unsigned char) byte;
        byte_count += 1;
    }

    fclose(fp);

    printf("Checksum of %s: %02X\n", argv[1], checksum);
    printf("Byte count: %d\n", byte_count);

    unsigned char expected_checksum;
    sscanf(argv[2], "%hhX", &expected_checksum);

    if (checksum == expected_checksum) {
        printf("Checksum verification successful.\n");
        return 0;
    } else {
        printf("Checksum verification failed: expected %02X, got %02X\n", expected_checksum, checksum);
        return 1;
    }
}