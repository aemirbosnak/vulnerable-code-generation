//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string using run-length encoding
void compress(char* input, int* output_size, char** output) {
    int i = 0, j = 0, count = 1;
    char* temp = (char*)malloc(1000000); // Allocate memory for temporary string
    strcpy(temp, input);

    // Count the frequency of each character in the input string
    while (temp[i]) {
        if (temp[i] == temp[i + 1]) {
            count++;
        } else {
            sprintf(temp + j, "%d%c", count, temp[i]);
            j += strlen(temp + j);
            count = 1;
        }
        i++;
    }
    sprintf(temp + j, "%d%c", count, temp[i - 1]);
    j += strlen(temp + j);

    // Copy the compressed string to output
    *output_size = j;
    *output = (char*)malloc((j + 1) * sizeof(char));
    strcpy(*output, temp);
    free(temp);
}

// Function to decompress the compressed string
void decompress(char* input, int* output_size, char** output) {
    int i = 0, j = 0;
    char* temp = (char*)malloc(1000000); // Allocate memory for temporary string
    strcpy(temp, input);

    // Decompress the compressed string
    while (temp[i]) {
        if (temp[i] >= '0' && temp[i] <= '9') {
            int count = temp[i] - '0';
            while (count--) {
                strcpy(temp + j, temp + i + 1);
                j += strlen(temp + j);
            }
        } else {
            strcpy(temp + j, temp + i);
            j += strlen(temp + j);
        }
        i++;
    }

    // Copy the decompressed string to output
    *output_size = j;
    *output = (char*)malloc((j + 1) * sizeof(char));
    strcpy(*output, temp);
    free(temp);
}

int main() {
    char input[1000000];
    char* output;
    int output_size;

    // Get input string from user
    printf("Enter the input string: ");
    scanf("%s", input);

    // Compress the input string
    compress(input, &output_size, &output);
    printf("Compressed string: %s\n", output);

    // Decompress the compressed string
    decompress(output, &output_size, &output);
    printf("Decompressed string: %s\n", output);

    return 0;
}