//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// Function declaration
int compress(char str[], char compressed_str[]);
void decompress(char compressed_str[], char decompressed_str[]);

int main()
{
    char original_str[MAX_SIZE];
    char compressed_str[MAX_SIZE];
    char decompressed_str[MAX_SIZE];
    int choice;

    do {
        printf("MENU:\n");
        printf("1. Compress a string\n");
        printf("2. Decompress a compressed string\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to flush the newline character

        if (choice == 1) {
            printf("Enter a string to compress: ");
            fgets(original_str, MAX_SIZE, stdin);
            original_str[strcspn(original_str, "\n")] = 0; // to remove the newline character added by fgets

            int compressed_length = compress(original_str, compressed_str);
            printf("Compressed string: %s\n", compressed_str);
            printf("Compressed length: %d\n", compressed_length);
        }
        else if (choice == 2) {
            printf("Enter a compressed string to decompress: ");
            fgets(compressed_str, MAX_SIZE, stdin);
            compressed_str[strcspn(compressed_str, "\n")] = 0; // to remove the newline character added by fgets

            decompress(compressed_str, decompressed_str);
            printf("Decompressed string: %s\n", decompressed_str);
        }
        else if (choice != 3) {
            printf("Invalid choice. Try again.\n");
        }

        printf("\n");
    } while (choice != 3);

    printf("Goodbye!\n");

    return 0;
}

// Compression algorithm
int compress(char str[], char compressed_str[])
{
    int length = strlen(str);
    int i, j;
    int count = 1;
    int compressed_length = 0;

    // Iterate through the string and count how many times each character appears consecutively
    for (i = 0; i < length; i = j) {
        for (j = i+1; j < length && str[j] == str[i]; j++) {
            count++;
        }

        // Copy the character and the count to the compressed string
        compressed_str[compressed_length++] = str[i];
        compressed_str[compressed_length++] = count + '0';
        count = 1;
    }

    compressed_str[compressed_length] = '\0';
    return compressed_length;
}

// Decompression algorithm
void decompress(char compressed_str[], char decompressed_str[])
{
    int compressed_length = strlen(compressed_str);
    int i, j;
    int count;

    for (i = 0, j = 0; i < compressed_length; i = j) {
        // Get the character
        decompressed_str[j] = compressed_str[i];

        // Get the count
        count = compressed_str[i+1] - '0';

        // Repeat the character count times
        for (int k = 1; k <= count; k++) {
            decompressed_str[++j] = compressed_str[i];
        }

        j++;
    }

    decompressed_str[j] = '\0';
}