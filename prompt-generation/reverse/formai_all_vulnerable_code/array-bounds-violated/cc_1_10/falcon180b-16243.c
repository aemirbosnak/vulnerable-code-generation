//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define VIRUS_SIGNATURE "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*"

int is_infected(char *file_path) {
    FILE *fp;
    char buffer[BUF_SIZE];
    int file_size = 0;
    int virus_found = 0;

    fp = fopen(file_path, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", file_path);
        return 1;
    }

    while ((fread(buffer, sizeof(char), BUF_SIZE, fp)) > 0) {
        file_size += BUF_SIZE;
        for (int i = 0; i < BUF_SIZE; i++) {
            if (tolower(buffer[i]) == tolower(VIRUS_SIGNATURE[i])) {
                virus_found = 1;
                break;
            }
        }
        if (virus_found) {
            break;
        }
    }

    fclose(fp);

    if (virus_found) {
        printf("Virus detected in file %s\n", file_path);
        return 1;
    } else {
        printf("No virus detected in file %s\n", file_path);
        return 0;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char *file_path = argv[1];
    struct stat st;

    if (stat(file_path, &st) == -1) {
        printf("Error: File %s does not exist\n", file_path);
        return 1;
    }

    if (S_ISDIR(st.st_mode)) {
        printf("Error: %s is a directory\n", file_path);
        return 1;
    }

    is_infected(file_path);

    return 0;
}