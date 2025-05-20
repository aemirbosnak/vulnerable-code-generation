//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: shape shifting
#include <stdio.h>
#include <string.h>

// Function that generates ASCII art for the input string
void generateArt(char *str) {
    int len = strlen(str);
    int i = 0, j = 0;
    int rows = 9, cols = len * 8;  // Set size of art

    // Loop through each row of the art
    for (i = 1; i <= rows; i++) {
        // Loop through each character of the input string
        for (j = 0; j < len; j++) {
            char c = str[j];

            // Generate ASCII art for different letters and characters
            switch(c) {
                case 'A':
                    if (i == 1 || i == 5 || j % 4 == 0) {
                        printf("  ##  ");
                    } else {
                        printf(" #  # ");
                    }
                    break;

                case 'B':
                    if (i == 1 || i == 5 || i == 9 || j % 4 == 0) {
                        printf(" ###  ");
                    } else {
                        printf(" #  # ");
                    }
                    break;

                case 'C':
                    if (i == 1 || i == 9 || (i >= 4 && i <= 6 && j == 0)) {
                        printf("  ##  ");
                    } else {
                        printf(" #    ");
                    }
                    break;

                case '!':
                    if (i == 1 || i == 4 || i == 7 || i == 9) {
                        printf("  !   ");
                    } else {
                        printf("      ");
                    }
                    break;

                default:
                    printf("      ");
                    break;
            }
        }

        printf("\n");  // Move to next row
    }
}

// Main function
int main() {
    char word[20];
    printf("Enter a word (up to 20 characters): ");
    scanf("%s", word);

    generateArt(word);  // Call function to generate ASCII art

    return 0;
}