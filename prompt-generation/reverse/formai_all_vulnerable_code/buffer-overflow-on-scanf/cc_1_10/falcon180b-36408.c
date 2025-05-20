//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the frequency of each character
typedef struct {
    char ch;
    int freq;
} CharFreq;

// Function to create a frequency table
void createFreqTable(char* str, CharFreq* freqTable) {
    int i, j;
    for (i = 0; i < 256; i++) {
        freqTable[i].ch = '\0';
        freqTable[i].freq = 0;
    }
    for (i = 0; str[i]!= '\0'; i++) {
        freqTable[str[i]].freq++;
    }
}

// Function to sort the frequency table
void sortFreqTable(CharFreq* freqTable) {
    int i, j;
    for (i = 0; i < 256; i++) {
        for (j = i + 1; j < 256; j++) {
            if (freqTable[j].freq > freqTable[i].freq) {
                CharFreq temp = freqTable[i];
                freqTable[i] = freqTable[j];
                freqTable[j] = temp;
            }
        }
    }
}

// Function to generate the compressed string
void generateCompressedString(char* str, CharFreq* freqTable) {
    int i, j;
    for (i = 0; i < strlen(str); i++) {
        printf("%c", str[i]);
        for (j = 0; j < freqTable[str[i]].freq; j++) {
            printf("%d", freqTable[str[i]].freq);
        }
    }
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    scanf("%s", str);
    CharFreq freqTable[256];
    createFreqTable(str, freqTable);
    sortFreqTable(freqTable);
    printf("Compressed string: ");
    generateCompressedString(str, freqTable);
    return 0;
}