//FormAI DATASET v1.0 Category: Compression algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

// Function prototypes
int compress(char *input, char *output);
int decompress(char *input, char *output);

int main(void) {
    char input[MAX_SIZE], output[MAX_SIZE];
    int option, result;
    
    printf("Enter string to compress: ");
    fgets(input, MAX_SIZE, stdin);
    input[strcspn(input, "\n")] = 0; // Removes newline character from input
    
    printf("Choose an option:\n");
    printf("1. Compress\n2. Decompress\n");
    scanf("%d", &option);
    
    switch(option) {
        case 1:
            result = compress(input, output);
            if(result == 0) {
                printf("Compressed string: %s\n", output);
            } else {
                printf("Error compressing string.\n");
            }
            break;
        case 2:
            result = decompress(input, output);
            if(result == 0) {
                printf("Decompressed string: %s\n", output);
            } else {
                printf("Error decompressing string.\n");
            }
            break;
        default:
            printf("Invalid option.\n");
            break;
    }
    
    return 0;
}

// Compresses the input string using a simple compression algorithm
int compress(char *input, char *output) {
    int i, j, count;
    char prev = input[0];
    char compressed[MAX_SIZE] = "";
    int length = strlen(input);
    
    if(length == 0) return -1; // Error if input is empty
    
    for(i = 1; i < length; i++) {
        if(input[i] == prev) {
            count++;
        } else {
            // Append character and count to compressed string
            sprintf(compressed, "%s%c%d", compressed, prev, count);
            prev = input[i];
            count = 1;
        }
    }
    
    // Append final character and count to compressed string
    sprintf(compressed, "%s%c%d", compressed, prev, count);
    
    // Copy compressed string to output
    strcpy(output, compressed);
    
    return 0;
}

// Decompresses the input string using the same compression algorithm
int decompress(char *input, char *output) {
    int i, j, count;
    char c;
    char decompressed[MAX_SIZE] = "";
    int length = strlen(input);
    
    if(length == 0) return -1; // Error if input is empty
    
    for(i = 0; i < length; i += 2) {
        c = input[i];
        count = input[i+1] - '0';
        for(j = 0; j < count; j++) {
            // Append character count times to decompressed string
            sprintf(decompressed, "%s%c", decompressed, c);
        }
    }
    
    // Copy decompressed string to output
    strcpy(output, decompressed);
    
    return 0;
}