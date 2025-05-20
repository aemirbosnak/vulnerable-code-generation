//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_HEIGHT 10 // Maximum height of the ASCII art

// A function to generate the ASCII art for a given character
void generate_char_art(char c) {
    int i, j;
    int width, height;
    char ascii_art[MAX_HEIGHT][MAX_HEIGHT] = { // ASCII art for each character
        {' ', '_', '_', '_', ' '},
        {'|', ' ', ' ', ' ', '|'},
        {'|', '_', '_', '_', '|'},
        {'|', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', '|'},
        {'|', '_', '_', '_', '|'},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '}
    };
    width = strlen(ascii_art[0]); // Width of the ASCII art
    height = MAX_HEIGHT; // Default height of the ASCII art
    
    if (c == 'A') { // Update ASCII art for character 'A'
        for (i = 0; i < 5; i++) {
            ascii_art[i][2] = '|'; // Update middle column
        }
    }
    else if (c == 'B') { // Update ASCII art for character 'B'
        ascii_art[2][0] = '|'; // Update first column
        ascii_art[2][width-1] = '_'; // Update last column
        ascii_art[3][0] = '|'; // Update first column
        ascii_art[3][width-1] = '_'; // Update last column
        ascii_art[4][0] = '|'; // Update first column
        ascii_art[4][width-1] = '_'; // Update last column
        ascii_art[5][0] = '|'; // Update first column
        ascii_art[5][width-1] = '_'; // Update last column
        ascii_art[6][0] = '|'; // Update first column
    }
    else if (c == 'C') { // Update ASCII art for character 'C'
        ascii_art[1][width-2] = '_'; // Update second-to-last column
        ascii_art[2][0] = '|'; // Update first column
        ascii_art[3][0] = '|'; // Update first column
        ascii_art[4][0] = '|'; // Update first column
        ascii_art[5][0] = '|'; // Update first column
        ascii_art[6][width-2] = '_'; // Update second-to-last column
    }
    else if (c == 'D') { // Update ASCII art for character 'D'
        ascii_art[2][0] = '|'; // Update first column
        ascii_art[2][width-1] = '_'; // Update last column
        ascii_art[3][0] = '|'; // Update first column
        ascii_art[3][width-1] = '_'; // Update last column
        ascii_art[4][0] = '|'; // Update first column
        ascii_art[4][width-1] = '_'; // Update last column
        ascii_art[5][0] = '|'; // Update first column
        ascii_art[5][width-1] = '_'; // Update last column
        ascii_art[6][0] = '|'; // Update first column
        ascii_art[6][width-2] = '_'; // Update second-to-last column
    }
    else if (c == 'E') { // Update ASCII art for character 'E'
        ascii_art[2][0] = '|'; // Update first column
        ascii_art[3][0] = '|'; // Update first column
        ascii_art[4][0] = '|'; // Update first column
        ascii_art[5][0] = '|'; // Update first column
        ascii_art[2][width-1] = '_'; // Update last column
        ascii_art[6][0] = '|'; // Update first column
        ascii_art[6][width-1] = '_'; // Update last column
    }
    else if (c == 'F') { // Update ASCII art for character 'F'
        ascii_art[2][0] = '|'; // Update first column
        ascii_art[3][0] = '|'; // Update first column
        ascii_art[4][0] = '|'; // Update first column
        ascii_art[2][width-1] = '_'; // Update last column
        ascii_art[6][0] = '|'; // Update first column
    }
    
    // Print the generated ASCII art
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }
}

// Main function to accept user input and call the ASCII art generation function
int main() {
    char input_char;
    printf("Enter a character to generate ASCII art: ");
    scanf("%c", &input_char);
    generate_char_art(input_char);
    return 0;
}