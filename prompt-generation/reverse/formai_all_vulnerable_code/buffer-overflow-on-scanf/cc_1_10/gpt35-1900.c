//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

char english_to_alien[ALPHABET_SIZE]; // map english alphabets to alien ones
char alien_to_english[ALPHABET_SIZE]; // map alien alphabets to english ones

/* function to initialize the mapping between english and alien alphabets */
void initialize_alien_language()
{
    /* code for mapping english alphabets to alien ones */
    english_to_alien[0] = 'a';
    english_to_alien[1] = 'b';
    english_to_alien[2] = 'c';
    english_to_alien[3] = 'd';
    english_to_alien[4] = 'e';
    english_to_alien[5] = 'f';
    english_to_alien[6] = 'g';
    english_to_alien[7] = 'h';
    english_to_alien[8] = 'i';
    english_to_alien[9] = 'j';
    english_to_alien[10] = 'k';
    english_to_alien[11] = 'l';
    english_to_alien[12] = 'm';
    english_to_alien[13] = 'n';
    english_to_alien[14] = 'o';
    english_to_alien[15] = 'p';
    english_to_alien[16] = 'q';
    english_to_alien[17] = 'r';
    english_to_alien[18] = 's';
    english_to_alien[19] = 't';
    english_to_alien[20] = 'u';
    english_to_alien[21] = 'v';
    english_to_alien[22] = 'w';
    english_to_alien[23] = 'x';
    english_to_alien[24] = 'y';
    english_to_alien[25] = 'z';

    /* code for mapping alien alphabets to english ones */
    alien_to_english[0] = 'q';
    alien_to_english[1] = 'w';
    alien_to_english[2] = 'e';
    alien_to_english[3] = 'r';
    alien_to_english[4] = 't';
    alien_to_english[5] = 'y';
    alien_to_english[6] = 'u';
    alien_to_english[7] = 'i';
    alien_to_english[8] = 'o';
    alien_to_english[9] = 'p';
    alien_to_english[10] = 'a';
    alien_to_english[11] = 's';
    alien_to_english[12] = 'd';
    alien_to_english[13] = 'f';
    alien_to_english[14] = 'g';
    alien_to_english[15] = 'h';
    alien_to_english[16] = 'j';
    alien_to_english[17] = 'k';
    alien_to_english[18] = 'l';
    alien_to_english[19] = 'z';
    alien_to_english[20] = 'x';
    alien_to_english[21] = 'c';
    alien_to_english[22] = 'v';
    alien_to_english[23] = 'b';
    alien_to_english[24] = 'n';
    alien_to_english[25] = 'm';
}

/* function to translate english text to alien language */
void english_to_alien_translation(char* english_text, int length)
{
    int i;
    char translated_text[length];

    /* map english alphabets to alien ones */
    for(i=0; i<length; i++)
    {
        translated_text[i] = english_to_alien[english_text[i]-'a'];
    }

    printf("Translated Text: %s\n", translated_text);
}

/* function to translate alien language text to english */
void alien_to_english_translation(char* alien_text, int length)
{
    int i;
    char translated_text[length];

    /* map alien alphabets to english ones */
    for(i=0; i<length; i++)
    {
        translated_text[i] = alien_to_english[alien_text[i]-'q'];
    }

    printf("Translated Text: %s\n", translated_text);
}

int main()
{
    char input_text[50];
    int choice, length;

    initialize_alien_language(); // function call to initialize the mapping between english and alien alphabets

    printf("*********** Welcome to Alien Language Translator ***********\n");

    while(1)
    {
        printf("Please choose an option from below:\n");
        printf("1. Translate English to Alien Language\n");
        printf("2. Translate Alien Language to English\n");
        printf("3. Quit\n");
        printf("Your choice: ");

        scanf("%d", &choice);

        if(choice==1) // translate english text to alien language
        {
            printf("Enter the english text to translate: ");
            scanf("%s", input_text);
            length = strlen(input_text);
            printf("English Text: %s (%d characters)\n", input_text, length);
            english_to_alien_translation(input_text, length); // function call to translate english text to alien language
        }
        else if(choice==2) // translate alien language text to english
        {
            printf("Enter the alien text to translate: ");
            scanf("%s", input_text);
            length = strlen(input_text);
            printf("Alien Text: %s (%d characters)\n", input_text, length);
            alien_to_english_translation(input_text, length); // function call to translate alien language text to english
        }
        else if(choice==3) // quit the program
        {
            printf("Thank you for using Alien Language Translator. Goodbye!\n");
            exit(0);
        }
        else // invalid choice
        {
            printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}