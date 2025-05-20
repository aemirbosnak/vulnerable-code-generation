#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 10

void readData(char* buf, int size, int offset) {
    printf("Reading data at offset %d\n", offset);
    if (offset < 0 || size <= offset) return;
    int i;
    for (i = 0; i < size; i++) {
        buf[i] = (char)(i + 48);
    }
    buf[offset] = '\0';
    printf("Data read: %s\n", buf);
}

int main() {
    int offset;
    char buffer[BUF_SIZE];

    printf("Enter offset value: ");
    scanf("%d", &offset);

    readData(buffer, BUF_SIZE, offset);

    printf("Migrating data from source to destination...\n");
    printf("Done.\n");
    return 0;
}
