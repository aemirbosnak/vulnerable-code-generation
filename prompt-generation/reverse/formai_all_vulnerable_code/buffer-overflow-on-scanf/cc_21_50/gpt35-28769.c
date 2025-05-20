//FormAI DATASET v1.0 Category: Text processing ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[1000];
    int count = 0;

    printf("Enter some text: ");
    fgets(text, sizeof(text), stdin);

    // counting number of words in the given text
    for(int i=0; i<strlen(text); i++)
    {
        if(text[i] == ' ' || text[i] == '\n' || text[i] == '\t')
        {
            count++;
        }
    }

    printf("Number of words in the given text: %d\n", count+1);

    // checking if the text contains any number
    for(int i=0; i<strlen(text); i++)
    {
        if(text[i]>='0' && text[i]<='9')
        {
            printf("The given text contains a number.\n");
            break;
        }   
    }

    // checking if the text contains any special characters
    for(int i=0; i<strlen(text); i++)
    {
        if((text[i]>='!' && text[i]<='/') || (text[i]>=':' && text[i]<='@') || (text[i]>='[' && text[i]<='`') || (text[i]>='{' && text[i]<='~'))
        {
            printf("The given text contains a special character.\n");
            break;
        }   
    }

    // character replacing
    char old_char, new_char;
    printf("Enter the character you want to replace: ");
    scanf(" %c", &old_char);
    printf("Enter the new character: ");
    scanf(" %c", &new_char);

    int flag = 0;

    for(int i=0; i<strlen(text); i++)
    {
        if(text[i] == old_char)
        {
            text[i] = new_char;
            flag = 1;
        }
    }

    if(flag == 1)
    {
        printf("The text after replacing the %c with %c: %s", old_char, new_char, text);
    }

    // word replacing
    char old_word[50], new_word[50];

    printf("Enter the word you want to replace: ");
    scanf("%s", old_word);

    printf("Enter the new word: ");
    scanf("%s", new_word);

    char *ptr = strstr(text, old_word);

    if(ptr != NULL)
    {
        strcpy(ptr, new_word);
        printf("The text after replacing the %s with %s: %s", old_word, new_word, text);
    }

    return 0;
}