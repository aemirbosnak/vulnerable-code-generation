//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// Function to print the ASCII art
void print_ascii_art(char* input_string) {
    int length = strlen(input_string);
    int rows = length / 80 + ((length % 80)? 1 : 0);
    int cols = 80;
    int i, j;

    // Loop through each row and print the ASCII art
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c", input_string[i * cols + j]);
        }
        printf("\n");
    }
}

int main() {
    char* input_string;
    int length;

    // Read the input file
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: input file not found.\n");
        exit(1);
    }

    // Get the length of the input string
    fseek(input_file, 0, SEEK_END);
    length = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    // Allocate memory for the input string
    input_string = (char*) malloc(length + 1);
    if (input_string == NULL) {
        printf("Error: memory allocation failed.\n");
        exit(1);
    }

    // Read the input string
    fread(input_string, length, 1, input_file);
    input_string[length] = '\0';

    // Close the input file
    fclose(input_file);

    // Print the ASCII art
    print_ascii_art(input_string);

    // Free the memory allocated for the input string
    free(input_string);

    return 0;
}