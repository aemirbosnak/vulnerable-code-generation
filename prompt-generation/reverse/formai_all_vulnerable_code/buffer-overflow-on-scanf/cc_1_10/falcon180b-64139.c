//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CRC_POLYNOMIAL 0xEDB88320

unsigned int calculate_crc(unsigned char* data, int length) {
    unsigned int crc = 0xffffffff;
    for (int i = 0; i < length; i++) {
        crc ^= data[i];
        for (int j = 0; j < 8; j++) {
            crc = (crc >> 1) ^ (CRC_POLYNOMIAL & -crc);
        }
    }
    return crc ^ 0xffffffff;
}

int main() {
    char file_name[256];
    printf("Enter file name: ");
    scanf("%s", file_name);

    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    unsigned char* data = malloc(file_size);
    if (data == NULL) {
        printf("Error allocating memory.\n");
        fclose(file);
        return 1;
    }

    if (fread(data, 1, file_size, file)!= file_size) {
        printf("Error reading file.\n");
        free(data);
        fclose(file);
        return 1;
    }

    fclose(file);

    unsigned int crc = calculate_crc(data, file_size);

    printf("File name: %s\n", file_name);
    printf("File size: %d bytes\n", file_size);
    printf("CRC-32: %08X\n", crc);

    free(data);
    return 0;
}