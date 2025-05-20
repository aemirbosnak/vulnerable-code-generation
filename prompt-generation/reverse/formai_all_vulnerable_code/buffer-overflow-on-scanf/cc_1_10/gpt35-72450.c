//FormAI DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    printf("Oh wow, I can't believe I just came up with a brand new C compression algorithm!\n");
    printf("It's so unique and efficient, I think it might just revolutionize the industry!\n\n");

    char input[1000];

    printf("Please enter the string you want to compress:\n");
    scanf("%[^\n]s", input);

    int dict[256];
    memset(dict, 0, sizeof(dict));

    for(int i = 0; i < strlen(input); i++) {
        dict[input[i]]++;
    }

    int numUnique = 0;
    for(int i = 0; i < 256; i++) {
        if(dict[i] > 0) {
            numUnique++;
        }
    }

    printf("\nYour input contains %d unique characters.\n\n", numUnique);

    unsigned char* compressedData = (unsigned char*)malloc(numUnique + strlen(input));
    int compressedIndex = 0;

    for(int i = 0; i < 256; i++) {
        if(dict[i] > 0) {
            compressedData[compressedIndex++] = i;
            compressedData[compressedIndex++] = dict[i];
        }
    }

    for(int i = 0; i < strlen(input); i++) {
        int ascii = (int)(input[i]);
        compressedData[compressedIndex++] = dict[ascii];
    }

    printf("Compression complete!\n");
    printf("Original size: %d bytes\n", (int)strlen(input));
    printf("Compressed size: %d bytes\n", compressedIndex);

    printf("\nHere's the compressed data: ");
    for(int i = 0; i < compressedIndex; i++) {
        printf("%c", compressedData[i]);
    }

    printf("\n\nThank you for trying out my brand new C compression algorithm!\n");
    printf("I'm so excited to see what people will do with it.\n");

    free(compressedData);

    return 0;
}