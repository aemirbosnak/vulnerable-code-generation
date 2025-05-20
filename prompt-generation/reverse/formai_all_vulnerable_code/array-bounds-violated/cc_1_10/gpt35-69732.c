//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: brave
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define ASCII_ART_HEIGHT 7

// Define ASCII art for each letter
const char* ascii_art[] =
{
    "  __          __\n /  \\        /  \\\n|    |      |    |\n|    | ____ |    |\n|    |/    \\|    |\n|    |\\    /|    |\n \\__/  \\__/  \\__/",
    " __\n/  |\n`| |\n | |\n_| |_\n\\___/",
    "  ____ \n /    |\n|___\\ |\n    / / \n   / /  \n  / /___\n /_____/ ",
    " _____\n/ ___/\n\\___ \\ \n ___/ / \n/____/ \n       \n       ",
    " _____ \n|__  /\n  / / \n / /  \n/ /__ \n\\____|\n      ",
    "     __\n    / /\n   / / \n  / /  \n / /   \n/_/    \n       ",
    "  _____ \n / ____|\n| (___  \n \\___ \\ \n ____) |\n|_____/ \n        ",
    "  ______\n /      \\\n|  $$$$$$\\\n| $$___\\$$\n| $$/$$ $$\n| $$/\\ $$\n|__/  \\__/"
};

// Convert character to ASCII index
int char_to_index(char c)
{
    return (int)c - 65;
}

// Convert text to ASCII art
void text_to_ascii_art(char* text)
{
    int i, j, k, len;
    char line[MAX_LINE_LENGTH + 1];
    len = strlen(text);

    for (i = 0; i < ASCII_ART_HEIGHT; i++)
    {
        line[0] = '\0';

        for (j = 0; j < len; j++)
        {
            k = char_to_index(text[j]);

            if (k >= 0 && k <= 25)
            {
                strcat(line, ascii_art[k] + (i * MAX_LINE_LENGTH));
            }
            else
            {
                strcat(line, "        "); // 8 spaces for non-alphabetical characters
            }
        }

        printf("%s\n", line);
    }
}

int main()
{
    char text[MAX_LINE_LENGTH + 1];
    printf("Enter text to convert to ASCII art:\n");
    fgets(text, sizeof(text), stdin);
    text_to_ascii_art(text);
    return 0;
}