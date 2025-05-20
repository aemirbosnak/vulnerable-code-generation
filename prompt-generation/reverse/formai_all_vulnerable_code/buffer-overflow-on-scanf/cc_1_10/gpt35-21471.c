//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to translate C Cat Language to English
void translate(char *inputLine)
{
    const int MAX_WORDS = 100;
    const int MAX_LENGTH = 20;
    char words[MAX_WORDS][MAX_LENGTH];
    int count = 0;
    
    // Split the input line into words
    char *token = strtok(inputLine, " ");
    while (token != NULL)
    {
        strncpy(words[count], token, MAX_LENGTH);
        count++;
        token = strtok(NULL, " ");
    }
    
    // Translate each word
    for (int i = 0; i < count; i++)
    {
        if (strcmp(words[i], "meow") == 0)
            printf("hello");
        else if (strcmp(words[i], "purr") == 0)
            printf("good");
        else if (strcmp(words[i], "hiss") == 0)
            printf("bad");
        else if (strcmp(words[i], "scratch") == 0)
            printf("write");
        else if (strcmp(words[i], "sleep") == 0)
            printf("exit");
        else if (strcmp(words[i], "run") == 0)
            printf("execute");
        else
            printf("%s", words[i]);
        
        printf(" ");
    }
}

int main()
{
    char inputLine[1000];
    
    // Prompt the user for input
    printf("Enter C Cat Language code:\n");
    scanf("%[^\n]", inputLine);
    
    // Translate the input and print the result
    translate(inputLine);
    
    return 0;
}