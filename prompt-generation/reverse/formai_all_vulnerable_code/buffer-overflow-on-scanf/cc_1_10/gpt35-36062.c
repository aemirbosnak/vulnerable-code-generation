//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to find the length of a string
int string_length(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Function to print the binary representation of an integer
void print_binary(int n) {
    int binary[MAX_SIZE], i = 0;
    while (n > 0) {
        binary[i++] = n % 2;
        n /= 2;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

// Function to embed the watermark into the binary representation of the input integer
int embed_watermark(int n, char *watermark) {
    int len = string_length(watermark);
    int pos = 0;
    for (int i = 0; i < len; i++) {
        // Get the binary representation of the ASCII value of the current character of the watermark
        int binary[MAX_SIZE];
        int ascii = (int) watermark[i];
        int j = 0;
        while (ascii > 0) {
            binary[j++] = ascii % 2;
            ascii /= 2;
        }
        // Embed the watermark bit by bit into the binary representation of the input integer
        for (int k = j - 1; k >= 0; k--) {
            int bit = (n >> pos) & 1;
            if (binary[k] == 0 && bit == 1) {
                n -= (1 << pos);
            } else if (binary[k] == 1 && bit == 0) {
                n += (1 << pos);
            }
            pos++;
        }
    }
    return n;
}

int main() {
    int n;
    char watermark[MAX_SIZE];

    // Take user input for integer and watermark
    printf("Enter an integer to embed the watermark: ");
    scanf("%d", &n);
    printf("Enter the watermark to embed: ");
    scanf("%s", watermark);

    // Embed the watermark into the binary representation of the integer
    int embedded = embed_watermark(n, watermark);

    // Print the binary representation of the integer before and after embedding the watermark
    printf("Binary representation of %d before embedding:\n", n);
    print_binary(n);
    printf("\nBinary representation of %d after embedding the watermark \"%s\":\n", n, watermark);
    print_binary(embedded);

    return 0;
}