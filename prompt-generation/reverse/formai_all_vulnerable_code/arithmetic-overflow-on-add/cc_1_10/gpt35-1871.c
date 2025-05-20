//FormAI DATASET v1.0 Category: Compression algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

//The following two lines are the struct where we will store the compressed data.
struct CompressedData {
    unsigned char symbol;
    int freq;
};

typedef struct CompressedData CompressedData;

int main()
{
    char input[MAX];
    int counter[MAX], i, j;
    CompressedData freqTable[MAX];
    printf("Enter the string to compress : ");
    fgets(input, MAX, stdin);
    // converting input string to an array of characters.
    input[strcspn(input, "\n")] = 0;
    int size = strlen(input);
    memset(counter, 0, sizeof(counter));
    memset(freqTable, 0, sizeof(freqTable));

    // counting the frequency of each character.
    for (i = 0; i < size; i++) {
        counter[(int)input[i]]++;
    }

    int compressedLength = 0;
    for (i = 0; i < MAX; i++) {
        if (counter[i] != 0) {
            freqTable[compressedLength].symbol = i;
            freqTable[compressedLength].freq = counter[i];
            compressedLength++;
        }
    }

    printf("\n");

    printf("%-5s%-5s%-5s%-5s\n", "Char", "Freq", "Code", "ASCII");
    for (i = 0; i < compressedLength; i++) {
        printf("%-5c%-5d", freqTable[i].symbol, freqTable[i].freq);

        // converting the frequency of each character to a binary string
        char binary[MAX] = "";
        int quotient = freqTable[i].freq, index = 0;

        while (quotient != 0) {
            int remainder = quotient % 2;
            quotient = quotient / 2;
            char temp[2];
            temp[0] = '0' + remainder;
            temp[1] = '\0';
            strcat(binary, temp);
            index++;
        }

        //reversing the binary string to get the actual binary representation of the frequency.
        char binaryString[MAX] = "";
        for (j = strlen(binary) - 1; j >= 0; j--) {
            char tempChar[2];
            tempChar[0] = binary[j];
            tempChar[1] = '\0';
            strcat(binaryString, tempChar);
        }

        printf("%-8s", binaryString);
        printf("%-5d\n", freqTable[i].symbol);
    }

    printf("\n");
    printf("The Compressed String is : ");
    for (i = 0; i < size; i++) {
        for (j = 0; j < compressedLength; j++) {
            if (input[i] == freqTable[j].symbol) {
                printf("%d", freqTable[j].freq);
            }
        }
    }

    printf("\n");

    return 0;
}