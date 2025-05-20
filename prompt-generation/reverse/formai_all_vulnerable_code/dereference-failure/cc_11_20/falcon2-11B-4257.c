//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

int main() {
    char filename[BUF_SIZE];
    printf("Enter the name of the file to encrypt: ");
    fgets(filename, BUF_SIZE, stdin);

    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    FILE *e = fopen("encrypted.txt", "w");
    if (e == NULL) {
        printf("Error creating encrypted file\n");
        return 1;
    }

    char buf[BUF_SIZE];
    while (fgets(buf, BUF_SIZE, f)) {
        char encrypted[BUF_SIZE];
        int i;

        for (i = 0; i < strlen(buf); i++) {
            if (buf[i] >= 'A' && buf[i] <= 'Z') {
                encrypted[i] = (buf[i] - 'A' + 'a' + 13) % 26 + 'A';
            } else if (buf[i] >= 'a' && buf[i] <= 'z') {
                encrypted[i] = (buf[i] - 'a' + 'A' - 13) % 26 + 'a';
            } else if (buf[i] >= '0' && buf[i] <= '9') {
                encrypted[i] = (buf[i] - '0' + 'A' - 13) % 26 + 'a';
            } else {
                encrypted[i] = buf[i];
            }
        }

        fputs(encrypted, e);
    }

    fclose(f);
    fclose(e);

    printf("File encrypted successfully\n");

    return 0;
}