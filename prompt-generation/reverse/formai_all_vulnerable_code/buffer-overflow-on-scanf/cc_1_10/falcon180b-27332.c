//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 10000

typedef struct {
    char str[MAX_STR_LEN];
    int freq;
} StringFreq;

void buildTable(StringFreq table[], char str[], int n) {
    for (int i = 0; i < n; i++) {
        table[i].freq = 0;
    }
    for (int i = 0; i < strlen(str); i++) {
        table[str[i]].freq++;
    }
}

void encode(StringFreq table[], char str[], int n) {
    int j = 0;
    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        while (table[c].freq > 0) {
            table[c].freq--;
            j++;
        }
        if (j > 0) {
            j--;
        } else {
            strcat(str, &c);
        }
    }
}

void decode(StringFreq table[], char str[], int n) {
    int j = 0;
    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        while (table[c].freq == 0) {
            table[c].freq++;
            j++;
        }
        if (j > 0) {
            j--;
        } else {
            strcat(str, &c);
        }
    }
}

int main() {
    char input[MAX_STR_LEN];
    printf("Enter string to compress: ");
    scanf("%s", input);
    int len = strlen(input);
    StringFreq table[256];
    buildTable(table, input, len);
    char compressed[MAX_STR_LEN];
    encode(table, compressed, len);
    printf("Compressed string: %s\n", compressed);
    char decompressed[MAX_STR_LEN];
    decode(table, compressed, len);
    printf("Decompressed string: %s\n", decompressed);
    return 0;
}