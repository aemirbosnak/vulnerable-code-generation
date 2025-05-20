//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to print ASCII art
void print_ascii_art(char *text) {
    int len = strlen(text);
    int height = (len * 2) / 3;
    int width = height * 3;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int x = i * 3;
            int y = j * 2;

            if (i < height / 2) {
                if (j < width / 2) {
                    printf(" ");
                } else {
                    printf(".");
                }
            } else {
                if (j < width / 2) {
                    printf(". ");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    char input[200];

    printf("Enter your text: ");
    scanf("%s", input);

    // Convert input to uppercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // Print ASCII art
    print_ascii_art(input);

    return 0;
}