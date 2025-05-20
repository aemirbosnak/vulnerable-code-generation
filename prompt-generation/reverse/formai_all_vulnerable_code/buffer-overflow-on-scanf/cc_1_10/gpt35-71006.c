//FormAI DATASET v1.0 Category: Compression algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char *input, char *output) {
    int length = strlen(input);
    int index = 0;
    int count = 1;
    char current = input[0];
    
    for(int i = 1; i < length; i++) {
        if(current == input[i]) {
            count++;
        } else {
            output[index++] = current;
            output[index++] = count + '0';
            current = input[i];
            count = 1;
        }
    }
    
    output[index++] = current;
    output[index++] = count + '0';
    output[index] = '\0';
}

void decompress(char *input, char *output) {
    int length = strlen(input);
    int index = 0;
    
    for(int i = 0; i < length; i += 2) {
        char current = input[i];
        int count = input[i+1] - '0';
        for(int j = 0; j < count; j++) {
            output[index++] = current;
        }
    }
    
    output[index] = '\0';
}

int main() {
    char input[100];
    printf("Enter the string to be compressed: ");
    scanf("%[^\n]", input);
    
    char compressed[100];
    compress(input, compressed);
    printf("Compressed string: %s\n", compressed);
    
    char decompressed[100];
    decompress(compressed, decompressed);
    printf("Decompressed string: %s\n", decompressed);
    
    return 0;
}