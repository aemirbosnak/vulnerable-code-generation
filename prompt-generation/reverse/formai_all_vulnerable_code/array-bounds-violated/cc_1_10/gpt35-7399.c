//FormAI DATASET v1.0 Category: Compression algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 128

int main(int argc, char* argv[])
{
    char text[MAXLEN] = {0};
    char compressed[MAXLEN] = {0};
    char decompressed[MAXLEN] = {0};
    int count = 0;
    int index = 0;
    int size = 0;

    // get input
    printf("Enter some text to compress: ");
    fgets(text, MAXLEN, stdin);

    // calculate frequency of each character
    int freq[128] = {0};  // assume ASCII characters
    for (int i = 0; i < strlen(text); i++) {
        freq[text[i]]++;
    }

    // build compressed string
    for (int i = 0; i < strlen(text); i++) {
        count++;
        if (text[i] != text[i + 1]) {
            compressed[index++] = text[i];  // add character to compressed string
            sprintf(&compressed[index], "%d", count);  // add count to compressed string
            index += strlen(&compressed[index]);  // move index to end of count
            count = 0;
        }
    }

    // print compressed string
    printf("Compressed string: %s\n", compressed);

    // calculate size savings
    size = strlen(text) - strlen(compressed);
    printf("Size savings: %d\n", size);

    // decompress string
    index = 0;
    int num = 0;
    for (int i = 0; i < strlen(compressed); i++) {
        if (compressed[i] >= '0' && compressed[i] <= '9') {
            num = num * 10 + (compressed[i] - '0');  // add digit to number
        } else {
            for (int j = 0; j < num; j++) {
                decompressed[index++] = compressed[i];  // add character to decompressed string num times
            }
            num = 0;
        }
    }

    // print decompressed string
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}