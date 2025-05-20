//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_CHECKSUM_LENGTH 8

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char checksum[MAX_CHECKSUM_LENGTH];
    int line_number = 1;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int length = strlen(line);
        if (line[length - 1] == '\n') {
            line[length - 1] = '\0';
            length--;
        }
        for (int i = 0; i < length; i++) {
            if (!isdigit(line[i])) {
                printf("Error: invalid character in line %d\n", line_number);
                return 1;
            }
        }
        int sum = 0;
        for (int i = 0; i < length; i++) {
            sum += line[i] - '0';
        }
        sprintf(checksum, "%08X", sum);
        if (strcmp(checksum, line)!= 0) {
            printf("Error: checksum mismatch in line %d\n", line_number);
            return 1;
        }
        line_number++;
    }

    printf("Checksums match\n");
    return 0;
}