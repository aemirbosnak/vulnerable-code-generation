//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024 // Maximum file size

unsigned char checksum(unsigned char *buffer, int size)
{
    unsigned char sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += buffer[i];
    }
    return sum;
}

int main(int argc, char *argv[])
{
    if (argc!= 3)
    {
        printf("Usage: %s <filename> <checksum>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file)
    {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    unsigned char buffer[MAX_SIZE];
    int file_size = fread(buffer, 1, MAX_SIZE, file);
    fclose(file);

    if (file_size <= 0)
    {
        printf("Error: File is empty or too large.\n");
        return 1;
    }

    unsigned char calculated_checksum = checksum(buffer, file_size);
    unsigned char expected_checksum = argv[2][0];

    if (calculated_checksum == expected_checksum)
    {
        printf("Checksum match: %02X\n", calculated_checksum);
    }
    else
    {
        printf("Checksum mismatch: %02X (expected: %02X)\n", calculated_checksum, expected_checksum);
    }

    return 0;
}