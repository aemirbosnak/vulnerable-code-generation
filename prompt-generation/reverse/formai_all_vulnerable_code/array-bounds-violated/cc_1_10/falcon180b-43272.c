//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_CHECKSUM_LENGTH 32

char *calculate_checksum(const char *filename) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char checksum[MAX_CHECKSUM_LENGTH];
    char *result;
    int checksum_length;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        exit(1);
    }

    checksum_length = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int line_length = strlen(line);
        if (line_length > 0 && line[line_length - 1] == '\n') {
            line[--line_length] = '\0';
        }
        for (int i = 0; i < line_length; i++) {
            if (!isspace(line[i])) {
                checksum[checksum_length++] = tolower(line[i]);
            }
        }
    }

    result = malloc(checksum_length + 1);
    if (result == NULL) {
        fprintf(stderr, "Error allocating memory for checksum\n");
        exit(1);
    }

    strcpy(result, "");
    for (int i = 0; i < checksum_length; i++) {
        char c = checksum[i];
        if (isalpha(c)) {
            c = (c - 'a' + 13) % 26 + 'a';
        } else if (isdigit(c)) {
            c = (c - '0' + 13) % 10 + '0';
        }
        strcat(result, &c);
    }

    fclose(fp);
    return result;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <filename> <expected_checksum>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    char *expected_checksum = argv[2];

    char *calculated_checksum = calculate_checksum(filename);
    if (strcmp(calculated_checksum, expected_checksum) == 0) {
        printf("Checksums match\n");
        exit(0);
    } else {
        printf("Checksums do not match\n");
        exit(1);
    }
}