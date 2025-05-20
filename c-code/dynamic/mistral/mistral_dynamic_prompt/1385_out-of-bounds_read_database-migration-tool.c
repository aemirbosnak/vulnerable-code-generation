#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void readData(char *buffer, int size, int index) {
    FILE *file = fopen("data.bin", "rb");
    if (file) {
        fseek(file, index, SEEK_SET);
        fread(buffer, size, 1, file);
        fclose(file);
    } else {
        printf("Error: Unable to open data file.\n");
    }
}

void main() {
    char data[MAX_SIZE];
    int index;

    printf("Enter the index of the data to read: ");
    scanf("%d", &index);

    readData(data, MAX_SIZE, index);
    printf("Data at index %d:\n%s\n", index, data);
}
