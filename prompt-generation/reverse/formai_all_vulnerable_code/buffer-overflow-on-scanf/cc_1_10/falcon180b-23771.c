//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string using run-length encoding
void compress(char* input, char* output) {
    int i = 0, j = 0, count = 1;
    char ch = input[i];

    while (ch!= '\0') {
        if (i < strlen(input) - 1 && input[i] == input[i+1]) {
            count++;
            i++;
        } else {
            sprintf(output + j, "%d%c", count, ch);
            count = 1;
            j += strlen(output + j);
            i++;
            ch = input[i];
        }
    }

    sprintf(output + j, "%d%c", count, ch);
    j += strlen(output + j);
    output[j] = '\0';
}

// Function to decompress the compressed string back to its original form
void decompress(char* input, char* output) {
    int i = 0, j = 0;
    char ch;

    while (input[i]!= '\0') {
        ch = input[i];
        if (isdigit(ch)) {
            int count = ch - '0';
            i++;
            while (count > 0 && i < strlen(input)) {
                output[j] = input[i];
                j++;
                i++;
                count--;
            }
        } else {
            output[j] = ch;
            j++;
            i++;
        }
    }

    output[j] = '\0';
}

int main() {
    char input[1000], output[1000];

    printf("Enter the input string: ");
    scanf("%s", input);

    compress(input, output);
    printf("Compressed string: %s\n", output);

    decompress(output, input);
    printf("Decompressed string: %s\n", input);

    return 0;
}