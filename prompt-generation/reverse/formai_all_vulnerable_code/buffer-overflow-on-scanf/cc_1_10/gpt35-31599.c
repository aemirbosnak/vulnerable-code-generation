//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: standalone
#include <stdio.h>
#include <string.h>

int main()
{
    char alienLanguage[26]; //create a char array of size 26 to store alien language characters
    char message[100]; //create a char array of size 100 to store user's message
    int i, j; //declare variables i and j

    //Prompt user to enter the alien language characters
    printf("Enter the Alien Language characters (in order from 'a' to 'z'): \n");
    scanf("%s", alienLanguage);

    //Check if the entered characters are valid
    for(i=0; i<26; i++)
    {
        for(j=i+1; j<26; j++)
        {
            if(alienLanguage[i] == alienLanguage[j])
            {
                printf("Invalid Input! Please enter unique Alien Language characters.\n");
                return 0;
            }
        }
    }

    //Prompt user to enter the message to be translated
    printf("Enter the message to be translated: \n");
    scanf(" %[^\n]s", message);

    //Translate the message to Alien Language
    printf("\nThe translated message is: ");
    for(i=0; i<strlen(message); i++)
    {
        if(message[i] == ' ') //check if the current character is a space
        {
            printf(" "); //print a space in the Alien Language
        }
        else
        {
            for(j=0; j<26; j++) //find the index of the character in the Alien Language
            {
                if(message[i] == 'a' + j)
                {
                    printf("%c", alienLanguage[j]); //print the corresponding Alien Language character
                }
            }
        }
    }

    return 0;
}