//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Ken Thompson
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
    "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--..", "/", "--..--", ".-.-.-", "..--.."
};

char *alpha[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K",
    "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V",
    "W", "X", "Y", "Z", " ", ".", "?"
};

void convert_to_morse(char *text)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        char ch = toupper(text[i]);
        int index = ch - 'A';
        if (ch == ' ')
        {
            index = 26;
        }
        else if (ch == '.')
        {
            index = 27;
        }
        else if (ch == '?')
        {
            index = 28;
        }
        else if (index < 0 || index > 25)
        {
            continue;
        }
        printf("%s ", morse_code[index]);
    }
    printf("\n");
}

int main()
{
    char input[100];
    printf("Enter a string to be converted to Morse code: ");
    scanf("%[^\n]s", input);

    printf("The Morse code for %s is: ", input);
    convert_to_morse(input);

    return 0;
}