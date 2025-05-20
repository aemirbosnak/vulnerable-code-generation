//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHK_SIZE 16
#define CHK_VAL 0x1234

unsigned short calc_checksum(unsigned char *data, int size) {
    unsigned short chksum = 0;
    int i;

    for (i = 0; i < size; i++) {
        chksum += data[i];
    }

    chksum = (chksum & 0xFF) + (chksum >> 8);
    chksum &= 0xFF;

    return chksum;
}

int main() {
    unsigned char data[CHK_SIZE] = { 0 };
    int i, j;
    FILE *fp;

    printf("Enter the name of the file to calculate checksum: ");
    scanf("%s", data);

    strcat(data, ".txt");
    fp = fopen(data, "r");

    if (fp == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    unsigned char *buffer = (unsigned char*) malloc(size);
    fread(buffer, size, 1, fp);
    fclose(fp);

    unsigned short chksum = calc_checksum(buffer, size);

    printf("Checksum of %s is %04X\n", data, chksum);

    free(buffer);
    return 0;
}