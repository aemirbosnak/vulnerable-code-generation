//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 10000

int qr_code_read(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);

    if (size <= 0) {
        printf("Error: File is empty.\n");
        fclose(fp);
        return -1;
    }

    fseek(fp, 0, SEEK_SET);

    char *data = (char *) malloc(size + 1);
    if (data == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(fp);
        return -1;
    }

    fread(data, size, 1, fp);
    fclose(fp);

    int i, j;
    for (i = 0, j = 0; i < size; i++) {
        if (isprint(data[i])) {
            printf("%c", data[i]);
        } else {
            printf(".");
        }
        if (++j == 80) {
            printf("\n");
            j = 0;
        }
    }

    printf("\n");
    free(data);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return -1;
    }

    qr_code_read(argv[1]);

    return 0;
}