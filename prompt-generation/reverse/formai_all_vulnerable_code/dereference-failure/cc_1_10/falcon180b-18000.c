//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024) // 1MB
#define VIRUS_SIGNATURE "X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*"

void read_file(char *filename, char *buffer, int *filesize) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    *filesize = ftell(fp);
    rewind(fp);
    if (*filesize > MAX_FILE_SIZE) {
        printf("Error: file %s is too large (%d bytes)\n", filename, *filesize);
        exit(1);
    }
    fread(buffer, 1, *filesize, fp);
    fclose(fp);
}

int scan_file(char *buffer, int filesize, char *virus_signature) {
    int i, j;
    for (i = 0; i < filesize - strlen(virus_signature); i++) {
        for (j = 0; j < strlen(virus_signature); j++) {
            if (buffer[i + j]!= virus_signature[j]) {
                break;
            }
        }
        if (j == strlen(virus_signature)) {
            printf("Virus detected in file %s\n", buffer);
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    char filename[256];
    strcpy(filename, argv[1]);
    char buffer[MAX_FILE_SIZE];
    int filesize;
    read_file(filename, buffer, &filesize);
    char virus_signature[strlen(VIRUS_SIGNATURE) + 1];
    strcpy(virus_signature, VIRUS_SIGNATURE);
    int result = scan_file(buffer, filesize, virus_signature);
    if (result == 0) {
        printf("File %s is clean\n", filename);
    }
    return 0;
}