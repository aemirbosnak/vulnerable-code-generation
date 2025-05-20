//FormAI DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    printf("Welcome to my unique C Compression Algorithm!\n");

    // Get user input string
    char input_string[100];
    printf("Please enter the string you want to compress: ");
    scanf("%s", input_string);

    // Determine length of input string
    int string_length = strlen(input_string);

    // Create compressed string
    char compressed_string[100];
    memset(compressed_string, '\0', sizeof(compressed_string));

    // Compress the input string
    int index = 0;
    for(int i = 0; i < string_length; i++) {
        int count = 1;
        while(input_string[i] == input_string[i+1] && i < string_length - 1) {
            count++;
            i++;
        }
        compressed_string[index++] = input_string[i];
        compressed_string[index++] = (char)(count + '0');
    }
    compressed_string[index] = '\0';

    // Print compressed string
    printf("Your compressed string is: %s\n", compressed_string);

    // Get user input for decompression
    char choice;
    printf("\nDo you want to decompress the string? (y/n): ");
    scanf(" %c", &choice);

    if(choice == 'y') {
        // Create decompressed string
        char decompressed_string[100];
        memset(decompressed_string, '\0', sizeof(decompressed_string));

        // Decompress the compressed string
        int compressed_length = strlen(compressed_string);
        index = 0;
        for(int i = 0; i < compressed_length; i += 2) {
            int count = (int)(compressed_string[i+1] - '0');
            for(int j = 0; j < count; j++) {
                decompressed_string[index++] = compressed_string[i];
            }
        }
        decompressed_string[index] = '\0';

        // Print decompressed string
        printf("\nYour decompressed string is: %s\n", decompressed_string);
    } else {
        printf("\nThank you for using my unique C Compression Algorithm!");
    }

    return 0;
}