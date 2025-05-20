//FormAI DATASET v1.0 Category: Compression algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 500
#define MAX_OUTPUT_SIZE 1000

void compress(char *input_str, char *output_str) {
    int input_len = strlen(input_str);
    int out_index = 0;

    // Iterate through each character of the input string
    for (int i = 0; i < input_len; i++) {
        int count = 1;

        // Count the number of consecutive characters that are the same
        while (i < input_len - 1 && input_str[i] == input_str[i+1]) {
            count++;
            i++;
        }

        // Add the character and its count to the output string
        output_str[out_index++] = input_str[i];
        sprintf(&output_str[out_index], "%d", count);
        out_index += strlen(&output_str[out_index]);
    }

    output_str[out_index] = '\0';
}

void decompress(char *input_str, char *output_str) {
    int input_len = strlen(input_str);
    int out_index = 0;

    // Iterate through each character of the input string
    for (int i = 0; i < input_len; i++) {
        // Get the character
        char current_char = input_str[i];

        // Get the number of times it occurs in the string
        int count = 0;
        while (i < input_len - 1 && input_str[i+1] >= '0' && input_str[i+1] <= '9') {
            count = count * 10 + (input_str[i+1] - '0');
            i++;
        }

        // Add the character to the output string
        for (int j = 0; j < count; j++) {
            output_str[out_index++] = current_char;
        }
    }

    output_str[out_index] = '\0';
}

int main() {
    char input_str[MAX_INPUT_SIZE], compressed_str[MAX_OUTPUT_SIZE], decompressed_str[MAX_INPUT_SIZE];
    int choice;

    do {
        printf("Enter a string: ");
        fgets(input_str, MAX_INPUT_SIZE, stdin);
        input_str[strcspn(input_str, "\n")] = '\0';

        printf("\n1. Compress String");
        printf("\n2. Decompress String");
        printf("\n3. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                compress(input_str, compressed_str);
                printf("\nCompressed String: %s\n\n", compressed_str);
                break;
            case 2:
                decompress(input_str, decompressed_str);
                printf("\nDecompressed String: %s\n\n", decompressed_str);
                break;
            case 3:
                printf("\nProgram terminated.\n\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }

        // Clear input buffer
        while ((getchar()) != '\n');
    } while (1);

    return 0;
}