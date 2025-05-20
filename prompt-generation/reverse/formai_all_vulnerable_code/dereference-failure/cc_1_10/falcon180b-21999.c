//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1024
#define POLY 0xEDB88320

int checksum(char* data, int length) {
    unsigned int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += (unsigned char)data[i];
    }
    return (int)(~sum & 0xFF);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <filename> <hex_checksum>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char buffer[MAX_LENGTH];
    fseek(file, 0, SEEK_END);
    int filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (filesize > MAX_LENGTH) {
        printf("Error: File is too large.\n");
        fclose(file);
        return 1;
    }

    fread(buffer, 1, filesize, file);
    fclose(file);

    int calculated_checksum = checksum(buffer, filesize);
    int provided_checksum = strtol(argv[2], NULL, 16);

    if (calculated_checksum == provided_checksum) {
        printf("Checksum matches.\n");
    } else {
        printf("Checksum does not match.\n");
    }

    return 0;
}