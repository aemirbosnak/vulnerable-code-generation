//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define HASH_SIZE 256

unsigned int hash(char *str) {
    unsigned int hash_val = 0;
    int i = 0;

    while (str[i]) {
        hash_val += tolower(str[i]) * i++;
    }

    return hash_val % HASH_SIZE;
}

int main() {
    char input_file[MAX_LINE_SIZE];
    char output_file[MAX_LINE_SIZE];
    char line[MAX_LINE_SIZE];
    FILE *input_fp, *output_fp;
    int num_lines = 0;
    unsigned int hash_table[HASH_SIZE] = {0};

    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, input_fp)!= NULL) {
        num_lines++;
        hash_table[hash(line)]++;
    }

    fprintf(output_fp, "Number of lines: %d\n", num_lines);

    for (int i = 0; i < HASH_SIZE; i++) {
        if (hash_table[i] > 0) {
            fprintf(output_fp, "Hash %d: %d\n", i, hash_table[i]);
        }
    }

    fclose(input_fp);
    fclose(output_fp);

    return 0;
}