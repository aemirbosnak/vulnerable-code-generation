//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define ASCII_ROWS 7
#define ASCII_COLS 6

char ascii_art[128][ASCII_ROWS][ASCII_COLS] = {
    {
        "    #    ",
        "   # #   ",
        "  #   #  ",
        " #     # ",
        " ####### ",
        " #     # ",
        " #     # "
    },
    {
        " ######  ",
        "      #  ",
        "      #  ",
        " #####   ",
        " #       ",
        " #       ",
        "#######  "
    },
    {
        " ######  ",
        "      #  ",
        "      #  ",
        " #####   ",
        "      #  ",
        "      #  ",
        " ######  "
    },
    // Additional ASCII art can be added here
};

void generate_ascii_art(char *text) {
    int text_len = strlen(text);
    for (int j = 0; j < ASCII_ROWS; j++) {
        for (int i = 0; i < text_len; i++) {
            int index = (int)text[i];
            if (index >= 0 && index < 128) {
                printf("%s", ascii_art[index][j]);
            } else {
                printf("      ");
            }
        }
        printf("\n");
    }
}

int main(void) {
    char text[100];
    printf("Enter a text to convert to ASCII art:\n");
    scanf("%[^\n]", text);
    printf("\n");
    generate_ascii_art(text);
    return 0;
}