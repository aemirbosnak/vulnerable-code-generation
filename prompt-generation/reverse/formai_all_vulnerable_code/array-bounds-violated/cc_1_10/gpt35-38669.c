//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: relaxed
#include <stdio.h>
#include <string.h>

void convertToMorse(char arr[], int len);

int main()
{
    char message[100];
    int len;

    printf("Enter a message in English to be converted to Morse code: ");
    fgets(message, 100, stdin);

    len = strlen(message);
    message[len-1] = '\0';

    convertToMorse(message, len-1);

    return 0;
}

void convertToMorse(char arr[], int len)
{
    char *morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/", ".--.-.", ".-.-.-"};

    char englishAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ /.";

    char morseMessage[1000] = "";
    int i, j, k;

    for(i=0; i<len; i++)
    {
        for(j=0; j<strlen(englishAlphabet); j++)
        {
            if(arr[i] == englishAlphabet[j])
            {
                strcat(morseMessage, morseCode[j]);
                strcat(morseMessage, " ");
                break;
            }
        }
    }

    for(k=0; k<strlen(morseMessage); k++)
    {
        if(morseMessage[k] != ' ')
        {
            printf("%c", morseMessage[k]);
        }
        else
        {
            printf(" ");
        }

        if(morseMessage[k] == '.' || morseMessage[k] == '-')
        {
            printf(" ");
        }
    }
}