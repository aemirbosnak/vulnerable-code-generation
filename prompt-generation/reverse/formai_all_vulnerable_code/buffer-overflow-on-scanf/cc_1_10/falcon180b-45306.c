//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print the ASCII art
void print_ascii_art(char* text) {
    int length = strlen(text);
    int rows = length / 80 + ((length % 80)? 1 : 0);
    int cols = 80;
    int i, j;

    // Print the ASCII art
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(i * cols + j < length) {
                printf("%c", text[i * cols + j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Prompt the user for input
    char input_text[1000];
    printf("Enter the text you want to convert to ASCII art: ");
    scanf("%s", input_text);

    // Convert the input text to ASCII art
    char* ascii_art = malloc(sizeof(char) * (strlen(input_text) + 1));
    int i, j, k;
    for(i = 0, j = 0; i < strlen(input_text); i++, j++) {
        if(j == 80) {
            ascii_art[i] = '\n';
            j = 0;
        } else {
            ascii_art[i] = input_text[i];
        }
    }
    ascii_art[strlen(input_text)] = '\0';

    // Print the ASCII art
    printf("ASCII art:\n");
    print_ascii_art(ascii_art);

    // Free the memory used by the ASCII art
    free(ascii_art);

    return 0;
}