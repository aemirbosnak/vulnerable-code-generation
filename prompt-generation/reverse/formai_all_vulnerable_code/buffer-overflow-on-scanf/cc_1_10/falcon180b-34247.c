//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

// Function to count the frequency of each character in the input string
void countFreq(char* str, int freq[MAX_CHARS]) {
    int i = 0;
    while (*str!= '\0') {
        if (i < MAX_CHARS) {
            freq[*(unsigned char*)str]++;
        }
        str++;
        i++;
    }
}

// Function to build the frequency table
void buildTable(int freq[MAX_CHARS], char table[MAX_CHARS]) {
    int i = 0;
    for (i = 0; i < MAX_CHARS; i++) {
        table[i] = (char)i;
    }
    int j = 0;
    for (i = 0; i < MAX_CHARS; i++) {
        if (freq[i] > 0) {
            while (freq[table[j]] > 0 && freq[table[j]] <= freq[i]) {
                j++;
            }
            char temp = table[j];
            table[j] = (char)i;
            table[i] = temp;
            freq[i] = freq[temp];
            freq[temp] = 0;
        }
    }
}

// Function to compress the input string using the frequency table
void compress(char* str, int freq[MAX_CHARS], char table[MAX_CHARS], char* output) {
    int i = 0;
    while (*str!= '\0') {
        output[i] = table[(unsigned char)*str];
        str++;
        i++;
    }
    output[i] = '\0';
}

// Function to decompress the compressed string using the frequency table
void decompress(char* str, int freq[MAX_CHARS], char table[MAX_CHARS], char* output) {
    int i = 0;
    while (*str!= '\0') {
        int index = (int)table[(unsigned char)*str];
        output[i] = index;
        str++;
        i++;
    }
    output[i] = '\0';
}

int main() {
    char input[100];
    printf("Enter the input string: ");
    scanf("%s", input);

    int freq[MAX_CHARS] = {0};
    countFreq(input, freq);

    char table[MAX_CHARS];
    buildTable(freq, table);

    char compressed[100];
    compress(input, freq, table, compressed);

    printf("Compressed string: %s\n", compressed);

    char decompressed[100];
    decompress(compressed, freq, table, decompressed);

    printf("Decompressed string: %s\n", decompressed);

    return 0;
}