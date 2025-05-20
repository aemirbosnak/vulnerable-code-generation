//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_SUM_LENGTH 32

void checksum_calculator(char *filename, char *sum) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *line_ptr;
    unsigned char checksum[MAX_SUM_LENGTH];
    int checksum_len;
    int line_len;
    int i;

    // Open the file
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    // Initialize checksum
    memset(checksum, 0, MAX_SUM_LENGTH);

    // Read file line by line
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_len = strlen(line);

        // Convert line to uppercase
        for (i = 0; i < line_len; i++) {
            line[i] = toupper(line[i]);
        }

        // Calculate checksum for line
        for (i = 0; i < line_len; i++) {
            checksum[i % MAX_SUM_LENGTH] ^= line[i];
        }
    }

    // Convert checksum to hexadecimal string
    checksum_len = 0;
    for (i = 0; i < MAX_SUM_LENGTH; i++) {
        if (checksum[i]!= 0) {
            sprintf(&sum[checksum_len], "%02X", checksum[i]);
            checksum_len += 2;
        }
    }

    // Close the file
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <sum>\n", argv[0]);
        exit(1);
    }

    char filename[MAX_LINE_LENGTH];
    strcpy(filename, argv[1]);

    char sum[MAX_SUM_LENGTH];
    strcpy(sum, argv[2]);

    checksum_calculator(filename, sum);

    printf("Checksum for file %s: %s\n", filename, sum);

    return 0;
}