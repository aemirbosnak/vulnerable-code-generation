//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    char ascii_art[7][100];
    memset(ascii_art, ' ', sizeof(ascii_art)); // initialize ascii_art array with spaces

    printf("Welcome to the Text to ASCII Art generator!\n");
    printf("Enter the text you want to convert: ");
    scanf(" %[^\n]s", text);

    int len = strlen(text);
    int ascii_index;
    for(int i = 0; i < len; i++) {
        ascii_index = text[i] % 7; // get remainder of ASCII code after dividing it by 7
        switch (ascii_index) {
            case 0:
                strcat(ascii_art[0], "-");
                strcat(ascii_art[2], "|");
                strcat(ascii_art[3], "|");
                strcat(ascii_art[5], "|");
                break;
            case 1:
                strcat(ascii_art[0], "/");
                strcat(ascii_art[2], "/");
                strcat(ascii_art[3], "/");
                strcat(ascii_art[4], "/");
                strcat(ascii_art[5], "/");
                strcat(ascii_art[6], "/");
                break;
            case 2:
                strcat(ascii_art[0], "\\");
                strcat(ascii_art[1], "/");
                strcat(ascii_art[2], "\\");
                strcat(ascii_art[4], "\\");
                strcat(ascii_art[5], "\\");
                strcat(ascii_art[6], "\\");
                break;
            case 3:
                strcat(ascii_art[0], "-");
                strcat(ascii_art[1], "|");
                strcat(ascii_art[2], "-");
                strcat(ascii_art[3], "|");
                strcat(ascii_art[4], "-");
                break;
            case 4:
                strcat(ascii_art[0], "\\");
                strcat(ascii_art[2], "/");
                strcat(ascii_art[3], "/");
                strcat(ascii_art[4], "\\");
                break;
            case 5:
                strcat(ascii_art[1], "\\");
                strcat(ascii_art[2], "\\");
                strcat(ascii_art[4], "/");
                strcat(ascii_art[5], "/");
                break;
            case 6:
                strcat(ascii_art[0], "-");
                strcat(ascii_art[2], "|");
                strcat(ascii_art[3], "|");
                strcat(ascii_art[4], "|");
                strcat(ascii_art[5], "|");
                strcat(ascii_art[6], "-");
                break;
        }
    }
    for(int i = 0; i < 7; i++) {
        printf("%s\n", ascii_art[i]);
    }

    return 0;
}