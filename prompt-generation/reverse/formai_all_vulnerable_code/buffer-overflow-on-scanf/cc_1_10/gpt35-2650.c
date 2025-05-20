//FormAI DATASET v1.0 Category: Compression algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_SIZE 1000

void compress(char* text) {
    int count = 1, size = strlen(text);
    char compressed[MAX_TEXT_SIZE];
    int ci = 0;
    for(int i = 0; i < size; i++) {
        if(text[i] == text[i+1]) {
            count++;
        } else {
            compressed[ci++] = text[i];
            compressed[ci++] = count + '0';
            count = 1;
        }
    }
    compressed[ci] = '\0';
    printf("Compressed text: %s\n", compressed);
}

void decompress(char* compressed) {
    int size = strlen(compressed);
    char text[MAX_TEXT_SIZE];
    int ti = 0;
    for(int i = 0; i < size; i += 2) {
        char c = compressed[i];
        int count = compressed[i+1] - '0';
        for(int j = 0; j < count; j++) {
            text[ti++] = c;
        }
    }
    text[ti] = '\0';
    printf("Decompressed text: %s\n",text);
}

int main() {
    char text[MAX_TEXT_SIZE];
    printf("Enter text to compress: ");
    fgets(text, MAX_TEXT_SIZE, stdin);
    text[strcspn(text, "\n")] = '\0';

    int option = 0;
    while(option != 3) {
        printf("Choose an option:\n"
               "1. Compress text\n"
               "2. Decompress text\n"
               "3. Exit\n");
        scanf("%d", &option);
        getchar();
        switch(option) {
            case 1:
                compress(text);
                break;
            case 2:{
                printf("Enter compressed text: ");
                char compressed[MAX_TEXT_SIZE];
                fgets(compressed, MAX_TEXT_SIZE, stdin);
                compressed[strcspn(compressed, "\n")] = '\0';
                decompress(compressed);
                break;
            }
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    }

    return 0;
}