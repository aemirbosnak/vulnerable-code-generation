//FormAI DATASET v1.0 Category: Spell checking ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char input[100]; //Stores the input string from user
    char word[20]; //Stores each word for checking

    printf("Enter a sentence: ");
    fgets(input, 100, stdin); //Takes the input sentence

    char *token = strtok(input, " "); //Tokenizing the sentence

    while(token != NULL) //Checking each word
    {
        int i=0;
        while(token[i] != '\0') //Checking individual characters of each word
        {
            if(isalpha(token[i])) //Checking if the character is alphabetical
                token[i] = tolower(token[i]); //Converting it to lowercase
            else 
            {
                printf("%c is not a letter. Spell check cancelled.\n", token[i]);
                return 0;
            }
            i++;
        }

        FILE *f;
        f = fopen("dictionary.txt", "r"); //Opening the dictionary file for reading
        
        if(f == NULL) //Error handling for dictionary file
        {
            printf("Unable to open dictionary file.\n");
            return 0;
        }

        int found = 0;
        while(fgets(word, 20, f)) //Reading each word from dictionary
        {
            word[strlen(word)-1] = '\0'; //Removing newline character

            if(strcmp(word, token) == 0) //Comparing the word from dictionary with input word
            {
                found = 1;
                break;
            }
        }

        fclose(f); //Closing the dictionary file
        
        if(found == 0) //If word is not found in dictionary
            printf("%s is not spelled correctly. Please check your spelling.\n", token);

        token = strtok(NULL, " "); //Getting next token
    }

    printf("Spell check complete.\n");

    return 0;
}