//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int c;
    int word_count = 0;
    int ch_count = 0;
    int freq_count[26] = {0};
    int paranoia = 0;

    if (argc !=2) {
        printf("Error - Invalid number of arguments\n");
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error - Cannot open '%s'\n", argv[1]);
        return 1;
    }

    while ((c = fgetc(fp)) != EOF) {
        ch_count++;
        if (isspace(c) || ispunct(c)) {
            word_count++;
            paranoia += c;
        } else {
            c = toupper(c);
            freq_count[c - 'A']++;
        }
    }
    
    if (ferror(fp)) {
        printf("Error reading from file\n");
        return 1;
    }

    fclose(fp);

    printf("Word count: %d\n", word_count);
    printf("Character count: %d\n", ch_count);
    printf("Frequency count:\n");

    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'A' + i, freq_count[i]);
    }

    printf("Paranoia Level: ");
    if (paranoia % 2 == 0) {
        printf("Low\n");
    } else if (paranoia % 3 == 0) {
        printf("Moderate\n");
    } else if (paranoia % 5 == 0) {
        printf("High\n");
    } else {
        printf("Extreme\n");
    }

    return 0;
}