//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert text to ASCII art
void text_to_ascii(char* text) {
    int height = 7; // height of ASCII art
    int width = strlen(text) + 2; // width of ASCII art
    char* ascii_art[height]; // array to hold ASCII art

    // allocate memory for each row of ASCII art
    for (int i = 0; i < height; i++) {
        ascii_art[i] = (char*) malloc(width*sizeof(char));
    }

    // create top and bottom borders of ASCII art
    for (int i = 0; i < width; i++) {
        ascii_art[0][i] = ascii_art[height-1][i] = '-';
    }

    // create left and right borders of ASCII art
    for (int i = 1; i < height-1; i++) {
        ascii_art[i][0] = ascii_art[i][width-1] = '|';
    }

    // initialize all characters in ASCII art to blank space
    for (int i = 1; i < height-1; i++) {
        for (int j = 1; j < width-1; j++) {
            ascii_art[i][j] = ' ';
        }
    }

    // convert each letter in text to ASCII art
    for (int i = 0; i < strlen(text); i++) {
        // create array to hold ASCII art for current letter
        char* letter[height];

        // select ASCII art for current letter
        switch (text[i]) {
            case 'A':
                letter[0] = "  ___  ";
                letter[1] = " / _ \\ ";
                letter[2] = "/_/ \\_\\";
                letter[3] = "\\ \\_/ /";
                letter[4] = " \\___/ ";
                letter[5] = "       ";
                letter[6] = "       ";
                break;
            case 'B':
                letter[0] = " ____  ";
                letter[1] = "|  _ \\ ";
                letter[2] = "| |_) |";
                letter[3] = "|  _ < ";
                letter[4] = "| |_) |";
                letter[5] = "|____/ ";
                letter[6] = "       ";
                break;
            case 'C':
                letter[0] = "  ____ ";
                letter[1] = " / ___|";
                letter[2] = "| |    ";
                letter[3] = "| |    ";
                letter[4] = "| |___ ";
                letter[5] = " \\____|";
                letter[6] = "       ";
                break;
            // continue with remaining letters of the alphabet
            case 'D':
                letter[0] = " ____  ";
                letter[1] = "|  _ \\ ";
                letter[2] = "| |_) |";
                letter[3] = "| |   <";
                letter[4] = "| |_) |";
                letter[5] = "|____/ ";
                letter[6] = "       ";
                break;
            default:
                letter[0] = "      ";
                letter[1] = "      ";
                letter[2] = "      ";
                letter[3] = "      ";
                letter[4] = "      ";
                letter[5] = "      ";
                letter[6] = "      ";
                break;
        }

        // copy ASCII art for current letter to ASCII art array
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < strlen(letter[j]); k++) {
                ascii_art[j][2*i+1+k] = letter[j][k];
            }
        }
    }

    // print ASCII art
    for (int i = 0; i < height; i++) {
        printf("%s\n", ascii_art[i]);
    }

    // free memory allocated for ASCII art array
    for (int i = 0; i < height; i++) {
        free(ascii_art[i]);
    }
}

int main() {
    // get text input from user
    char text[100];
    printf("Enter text to convert to ASCII art: ");
    scanf("%[^\n]", text);

    // convert text to ASCII art
    text_to_ascii(text);

    return 0;
}