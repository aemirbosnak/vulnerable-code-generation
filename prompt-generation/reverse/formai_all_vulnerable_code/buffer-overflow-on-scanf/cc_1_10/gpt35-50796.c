//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: optimized
#include <stdio.h>
#include <string.h>

const char* MorseTable[37][2] = {
    {"A", ".-"},
    {"B", "-..."},
    {"C", "-.-."},
    {"D", "-.."},
    {"E", "."},
    {"F", "..-."},
    {"G", "--."},
    {"H", "...."},
    {"I", ".."},
    {"J", ".---"},
    {"K", "-.-"},
    {"L", ".-.."},
    {"M", "--"},
    {"N", "-."},
    {"O", "---"},
    {"P", ".--."},
    {"Q", "--.-"},
    {"R", ".-."},
    {"S", "..."},
    {"T", "-"},
    {"U", "..-"},
    {"V", "...-"},
    {"W", ".--"},
    {"X", "-..-"},
    {"Y", "-.--"},
    {"Z", "--.."},
    {"0", "-----"},
    {"1", ".----"},
    {"2", "..---"},
    {"3", "...--"},
    {"4", "....-"},
    {"5", "....."},
    {"6", "-...."},
    {"7", "--..."},
    {"8", "---.."},
    {"9", "----."},
    {" ", " "}
};

void TextToMorseCode(char* text, char* morseCode)
{
    int i, j;
    int len = strlen(text);
    int numTableEntries = sizeof(MorseTable) / (sizeof(char*) * 2);

    for (i = 0; i < len; i++)
    {
        char ch = toupper(text[i]);

        for (j = 0; j < numTableEntries; j++)
        {
            if (MorseTable[j][0][0] == ch)
            {
                strcat(morseCode, MorseTable[j][1]);
                strcat(morseCode, " "); // Add space after every Morse code letter
                break;
            }
        }
    }
}

int main()
{
    char text[100];
    char morseCode[1000];

    printf("Enter text (Only English Alphabets & Digits 0-9 are allowed): ");
    scanf("%[^\n]s", text);

    TextToMorseCode(text, morseCode);

    printf("Morse code: %s", morseCode);

    return 0;
}