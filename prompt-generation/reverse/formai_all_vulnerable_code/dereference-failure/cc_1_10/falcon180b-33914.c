//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_STR_LEN 1000
#define MAX_LINE_LEN 10000

char* read_file(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char* buffer = malloc(MAX_LINE_LEN);
    char* result = malloc(MAX_STR_LEN);
    int len = 0;

    while (fgets(buffer, MAX_LINE_LEN, fp)!= NULL) {
        len += strlen(buffer);
        if (len >= MAX_STR_LEN) {
            printf("Error: input string too long\n");
            exit(1);
        }
        strcat(result, buffer);
    }

    fclose(fp);
    return result;
}

int calculate_checksum(const char* input) {
    int sum = 0;
    int i;

    for (i = 0; input[i]!= '\0'; i++) {
        if (isdigit(input[i])) {
            sum += input[i] - '0';
        } else if (isupper(input[i])) {
            sum += input[i] - 'A' + 10;
        } else if (islower(input[i])) {
            sum += input[i] - 'a' + 10;
        } else {
            sum += input[i];
        }
    }

    return sum;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char* input = read_file(argv[1]);
    int checksum = calculate_checksum(input);

    printf("Checksum: %d\n", checksum);

    free(input);
    return 0;
}