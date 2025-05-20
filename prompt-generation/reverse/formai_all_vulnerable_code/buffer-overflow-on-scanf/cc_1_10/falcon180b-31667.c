//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLE_SIZE 256

// Function to initialize the table
void initializeTable(int table[], int size) {
    for (int i = 0; i < size; i++) {
        table[i] = 0;
    }
}

// Function to compress the input string using the Knuth-Morris-Pratt algorithm
void kmp(char input[], int input_size, int table[], int table_size) {
    int j = 0;
    for (int i = 0; i < input_size; i++) {
        while (j > 0 && input[i]!= input[j]) {
            j = table[j - 1];
        }
        if (input[i] == input[j]) {
            j++;
        }
        table[i] = j;
    }
}

// Function to decompress the compressed string using the Knuth-Morris-Pratt algorithm
void decompress(char input[], int input_size, int table[], int table_size) {
    int j = 0;
    for (int i = 0; i < input_size; i++) {
        if (i < table_size && input[i] == input[j]) {
            j++;
        }
        printf("%c", input[i]);
    }
}

int main() {
    char input[100];
    printf("Enter the input string: ");
    scanf("%s", input);
    int input_size = strlen(input);

    // Initialize the table
    int table[MAX_TABLE_SIZE];
    initializeTable(table, MAX_TABLE_SIZE);

    // Compress the input string
    kmp(input, input_size, table, MAX_TABLE_SIZE);

    // Print the compressed string
    printf("Compressed string: ");
    for (int i = 0; i < input_size; i++) {
        printf("%d", table[i]);
    }
    printf("\n");

    // Decompress the compressed string
    char decompressed_input[100];
    int decompressed_input_size = 0;
    for (int i = 0; i < input_size; i++) {
        if (table[i] > 0) {
            decompressed_input[decompressed_input_size++] = input[i];
        }
    }
    decompressed_input[decompressed_input_size] = '\0';

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed_input);

    return 0;
}