//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alien_translator(char *alien_text)
{
    char *translated_text = malloc(strlen(alien_text) * 2);
    int i = 0;
    for (; alien_text[i] != '\0'; i++)
    {
        switch (alien_text[i])
        {
            case 'a':
                translated_text[i] = 'A';
                break;
            case 'b':
                translated_text[i] = 'B';
                break;
            case 'c':
                translated_text[i] = 'C';
                break;
            case 'e':
                translated_text[i] = 'E';
                break;
            case 'g':
                translated_text[i] = 'G';
                break;
            case 'h':
                translated_text[i] = 'H';
                break;
            case 'i':
                translated_text[i] = 'I';
                break;
            case 'j':
                translated_text[i] = 'J';
                break;
            case 'k':
                translated_text[i] = 'K';
                break;
            case 'l':
                translated_text[i] = 'L';
                break;
            case 'm':
                translated_text[i] = 'M';
                break;
            case 'n':
                translated_text[i] = 'N';
                break;
            case 'o':
                translated_text[i] = 'O';
                break;
            case 'p':
                translated_text[i] = 'P';
                break;
            case 'r':
                translated_text[i] = 'R';
                break;
            case 's':
                translated_text[i] = 'S';
                break;
            case 't':
                translated_text[i] = 'T';
                break;
            case 'u':
                translated_text[i] = 'U';
                break;
            case 'v':
                translated_text[i] = 'V';
                break;
            case 'w':
                translated_text[i] = 'W';
                break;
            case 'y':
                translated_text[i] = 'Y';
                break;
            case 'z':
                translated_text[i] = 'Z';
                break;
            default:
                translated_text[i] = alien_text[i];
                break;
        }
    }
    translated_text[strlen(alien_text)] = '\0';
    printf("%s", translated_text);
    free(translated_text);
}

int main()
{
    char *alien_text = "extraterrestrial greetings, human";
    alien_translator(alien_text);
    return 0;
}