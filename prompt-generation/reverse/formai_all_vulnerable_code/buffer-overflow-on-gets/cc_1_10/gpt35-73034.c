//FormAI DATASET v1.0 Category: Compression algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len(char *a) {
    int i = 0;
    while(a[i] != '\0') {
        i++;
    }
    return i;
}

void compress(char *input, char *output) {
    int len1 = len(input);
    int cur = 0, count = 1;
    char prev = input[0];
    for(int i = 1; i < len1; i++) {
        if(input[i] == prev) {
            count++;
        }
        else {
            output[cur++] = prev;
            output[cur++] = count + '0';
            prev = input[i];
            count = 1;
        }
    }
    output[cur++] = prev;
    output[cur++] = count + '0';
    output[cur] = '\0';
}

void decompress(char *input, char *output) {
    int len1 = len(input);
    int cur = 0;
    for(int i = 0; i < len1; i += 2) {
        char c = input[i];
        int n = input[i+1] - '0';
        for(int j = 0; j < n; j++) {
            output[cur++] = c;
        }
    }
    output[cur] = '\0';
}

int main() {
    char str1[100], str2[100];
    printf("Enter a string: ");
    gets(str1);
    compress(str1, str2);
    printf("Compressed string: %s\n", str2);
    decompress(str2, str1);
    printf("Decompressed string: %s\n", str1);
    return 0;
}