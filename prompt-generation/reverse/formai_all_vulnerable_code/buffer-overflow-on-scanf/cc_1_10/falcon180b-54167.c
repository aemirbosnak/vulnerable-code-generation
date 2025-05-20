//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int checksum(char* data, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum;
}

int main() {
    char file_name[MAX_SIZE];
    printf("Enter file name: ");
    scanf("%s", file_name);

    FILE* fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    rewind(fp);

    char* data = malloc(size);
    if (data == NULL) {
        printf("Error allocating memory.\n");
        return 1;
    }

    size_t bytes_read = fread(data, 1, size, fp);
    if (bytes_read!= size) {
        printf("Error reading file.\n");
        return 1;
    }

    int checksum_value = checksum(data, size);

    printf("Checksum value: %d\n", checksum_value);

    free(data);
    fclose(fp);

    return 0;
}