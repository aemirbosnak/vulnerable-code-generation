//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void compressRLE(const char* input, char* output);
void decompressRLE(const char* input, char* output);
void printMenu();

int main() {
    char input[256];
    char compressed[512];
    char decompressed[256];
    int choice;

    while (1) {
        printMenu();
        printf("Enter your choice (1-3, 0 to exit): ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character

        switch (choice) {
            case 1:
                printf("Enter a string to compress: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline

                compressRLE(input, compressed);
                printf("Compressed: %s\n", compressed);
                break;

            case 2:
                printf("Enter a compressed string to decompress: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline

                decompressRLE(input, decompressed);
                printf("Decompressed: %s\n", decompressed);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void compressRLE(const char* input, char* output) {
    int count, i = 0, j = 0;

    while (input[i]) {
        count = 1;
        while (input[i] == input[i + 1]) {
            count++;
            i++;
        }
        output[j++] = input[i];
        output[j++] = count + '0'; // Convert count to char
        i++;
    }
    output[j] = '\0'; // Null-terminate the string
}

void decompressRLE(const char* input, char* output) {
    int i = 0, j = 0;

    while (input[i]) {
        char ch = input[i++];
        int count = input[i++] - '0'; // Convert char back to int

        for (int k = 0; k < count; k++) {
            output[j++] = ch;
        }
    }
    output[j] = '\0'; // Null-terminate the string
}

void printMenu() {
    printf("\n--- Run-Length Encoding (RLE) ---\n");
    printf("1. Compress a string\n");
    printf("2. Decompress a string\n");
    printf("3. Exit\n");
}