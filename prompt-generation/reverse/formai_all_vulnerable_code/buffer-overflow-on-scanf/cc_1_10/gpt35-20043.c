//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: intelligent
#include<stdio.h>
#include<ctype.h>

int main()
{
    char catLanguage[] = "Meow Purr Hiss Scratch Claw";
    char english[] = "Hey there! How are you doing?";
    
    char input[1000];
    
    printf("Enter text in cat language: ");
    scanf("%[^\n]s", input);
    
    int i = 0, j = 0;
    char output[1000] = "";
    int length = strlen(input);
    
    // converting the input to lowercase
    for(i = 0; i < length; i++)
    {
        input[i] = tolower(input[i]);
    }
    
    // comparing the input with cat language words
    i = 0;
    while(i < length)
    {
        char word[1000] = "";
        j = 0;
        while(input[i] != ' ' && i < length)
        {
            word[j] = input[i];
            i++;
            j++;
        }
        if(strcmp(word, "meow") == 0)
        {
            strcat(output, "Hey ");
        }
        else if(strcmp(word, "purr") == 0)
        {
            strcat(output, "How are you ");
        }
        else if(strcmp(word, "hiss") == 0)
        {
            strcat(output, "I don't like it ");
        }
        else if(strcmp(word, "scratch") == 0)
        {
            strcat(output, "Stop that ");
        }
        else if(strcmp(word, "claw") == 0)
        {
            strcat(output, "Ouch! That hurts ");
        }
        else
        {
            strcat(output, word);
            strcat(output, " ");
        }
        i++;
    }
    
    // printing the converted output
    printf("Cat Language: %s\n", input);
    printf("English Language: %s\n", output);
    
    return 0;
}