//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: sophisticated
#include <stdio.h>
#include <string.h>

#define DOT_LENGTH 1
#define DASH_LENGTH 3
#define SPACE_LENGTH 7

void convertToMorseCode(char *str)
{
    char morse[37][6] = {".-",   // A
                         "-...", // B
                         "-.-.", // C
                         "-..",  // D
                         ".",    // E
                         "..-.", // F
                         "--.",  // G
                         "....", // H
                         "..",   // I
                         ".---", // J
                         "-.-",  // K
                         ".-..", // L
                         "--",   // M
                         "-.",   // N
                         "---",  // O
                         ".--.", // P
                         "--.-", // Q
                         ".-.",  // R
                         "...",  // S
                         "-",    // T
                         "..-",  // U
                         "...-", // V
                         ".--",  // W
                         "-..-", // X
                         "-.--", // Y
                         "--..", // Z
                         "-----", // 0
                         ".----", // 1
                         "..---", // 2
                         "...--", // 3
                         "....-", // 4
                         ".....", // 5
                         "-....", // 6
                         "--...", // 7
                         "---..", // 8
                         "----.", // 9
                         "      "}; // Space

    int i, j;
    for (i = 0; i < strlen(str); i++)
    {
        // spaces between the letters
        if (str[i] == ' ')
        {
            printf("%s", morse[36]);
            for(j = 0; j < SPACE_LENGTH; j++)
            {
                printf(" ");
            }
        }
        else if(str[i] >= '0' && str[i] <= '9')
        {
            printf("%s", morse[str[i] - '0' + 26]);
            for(j = 0; j < DASH_LENGTH; j++)
            {
                printf(" ");
            }
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            printf("%s", morse[str[i] - 'A']);
            for(j = 0; j < DASH_LENGTH; j++)
            {
                printf(" ");
            }
        }
        else if(str[i] >= 'a' && str[i] <= 'z')
        {
            printf("%s", morse[str[i] - 'a']);
            for(j = 0; j < DASH_LENGTH; j++)
            {
                printf(" ");
            }
        }
        else
        {
            printf("Invalid character: %c\n", str[i]);
        }
    }
    printf("\n");
}

int main()
{
    char string[100];
    printf("Enter the string to convert to Morse code: ");
    scanf("%[^\n]", string);
    convertToMorseCode(string);
    return 0;
}