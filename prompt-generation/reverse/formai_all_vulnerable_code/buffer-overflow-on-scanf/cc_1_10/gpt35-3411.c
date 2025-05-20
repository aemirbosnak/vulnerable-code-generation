//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: secure
#include <stdio.h>
#include <string.h>

// Function to print the ASCII art for given string
void printAsciiArt(char *str) {
    int len = strlen(str);
    char asciiArt[10][100];

    // Initialize the ASCII art array
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 100; j++) {
            asciiArt[i][j] = ' ';
        }
    }

    // Generate the ASCII art for given string
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            for (int j = 0; j < 10; j++) {
                asciiArt[j][i*9+8] = '|';
            }
        } else {
            int val = str[i] - 'A';

            for (int j = 0; j < 10; j++) {
                if (j == 0 || j == 9) {
                    asciiArt[j][i*9+1] = '/';
                    asciiArt[j][i*9+7] = '\\';
                } else if (j == 4) {
                    asciiArt[j][i*9+2] = '_';
                    asciiArt[j][i*9+6] = '_';
                    asciiArt[j][i*9+3] = str[i];
                } else if (j < 4) {
                    asciiArt[j][i*9+j+1] = '/';
                    asciiArt[8-j][i*9+j+1] = '\\';
                } else {
                    asciiArt[j][i*9+9-j] = '/';
                    asciiArt[8-j][i*9+9-j] = '\\';
                }
            }
        }
    }

    // Print the generated ASCII art
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < len*9+2; j++) {
            printf("%c", asciiArt[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char str[100];

    printf("Enter a string (uppercase letters only): ");
    scanf("%[^\n]s", str);

    // Validate the input string
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] < 'A' || str[i] > 'Z') {
            printf("Invalid input! Please enter uppercase letters only.\n");
            return 0;
        }
    }

    // Generate and print the ASCII art for given string
    printAsciiArt(str);

    return 0;
}