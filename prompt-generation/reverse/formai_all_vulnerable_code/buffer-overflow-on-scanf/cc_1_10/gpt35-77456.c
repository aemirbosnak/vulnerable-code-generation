//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define size of ASCII art
#define ROWS 20
#define COLS 60

char art[ROWS][COLS]; // 2D array to store ASCII art

// Function to print the ASCII art
void print_art() {
    printf("ASCII ART:\n\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to generate the ASCII art
void generate_art(char* message) {
    char* output;
    output = (char*) malloc(strlen(message) * sizeof(char)); // Allocate memory for output string
    strcpy(output, message); // Copy input message to output string

    // Convert output string to uppercase
    for(int i=0; i<strlen(output); i++) {
        if(output[i] >= 'a' && output[i] <= 'z') {
            output[i] = output[i] - ('a' - 'A');
        }
    }

    // Generate ASCII art from output string
    for(int i=0; i<strlen(output); i++) {
        char c = output[i];
        int pos = i*3;

        // Generate ASCII art for uppercase letters
        if(c >= 'A' && c <= 'Z') {
            int offset = (c - 'A') * 6;
            for(int j=0; j<5; j++) {
                art[j][pos] = '|';
                art[j][pos+2] = '|';
                art[j][pos+4] = '|';
                art[5][pos+j*2] = '-';
                art[5][pos+j*2+1] = c;
                art[5][pos+j*2+2] = '-';
                art[6][pos] = '|';
                art[6][pos+2] = '|';
                art[6][pos+4] = '|';
                art[7][pos+j*2] = '-';
                art[7][pos+j*2+1] = c + ' ';
                art[7][pos+j*2+2] = '-';
                art[8][pos] = '|';
                art[8][pos+2] = '|';
                art[8][pos+4] = '|';
                art[9][pos+j*2] = '-';
                art[9][pos+j*2+1] = c;
                art[9][pos+j*2+2] = '-';
            }
            pos += 6;
        }

        // Generate ASCII art for whitespace
        if(c == ' ') {
            for(int j=0; j<5; j++) {
                art[j][pos] = '|';
                art[j][pos+1] = '|';
                art[j][pos+2] = '|';
                art[5][pos] = '|';
                art[5][pos+1] = '|';
                art[5][pos+2] = '|';
                art[6][pos] = '|';
                art[6][pos+1] = '|';
                art[6][pos+2] = '|';
                art[7][pos] = '|';
                art[7][pos+1] = '|';
                art[7][pos+2] = '|';
                art[8][pos] = '|';
                art[8][pos+1] = '|';
                art[8][pos+2] = '|';
                art[9][pos] = '|';
                art[9][pos+1] = '|';
                art[9][pos+2] = '|';
            }
            pos += 3;
        }

        // Generate ASCII art for unknown characters
        if(c < 'A' || c > 'Z') {
            for(int j=0; j<5; j++) {
                art[j][pos] = '+';
                art[j][pos+1] = '-';
                art[j][pos+2] = '+';
                art[5][pos] = '|';
                art[5][pos+1] = c;
                art[5][pos+2] = '|';
                art[6][pos] = '|';
                art[6][pos+1] = ' ';
                art[6][pos+2] = '|';
                art[7][pos] = '|';
                art[7][pos+1] = ' ';
                art[7][pos+2] = '|';
                art[8][pos] = '|';
                art[8][pos+1] = ' ';
                art[8][pos+2] = '|';
                art[9][pos] = '+';
                art[9][pos+1] = '-';
                art[9][pos+2] = '+';
            }
            pos += 3;
        }
    }
    free(output); // Free memory allocated for output string
}

int main() {
    printf("Welcome to the ASCII Art Generator!\n");
    while(1) {
        char message[100];
        printf("Enter a message (or 'quit' to exit): ");
        scanf("%s", message);

        if(strcmp(message, "quit") == 0) {
            printf("Goodbye!\n");
            return 0;
        }

        generate_art(message);
        print_art();
    }
    return 0;
}