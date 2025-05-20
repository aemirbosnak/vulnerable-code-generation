//Falcon2-11B DATASET v1.0 Category: Cat Language Translator ; Style: authentic
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char sentence[100], word[100], temp[100], uppercase[100], lowercase[100], newWord[100];
    int i, j, k, l, m, n, flag;

    printf("Enter a sentence: ");
    gets(sentence);

    for(i=0;sentence[i];i++)
    {
        sentence[i] = tolower(sentence[i]);
    }

    strcpy(uppercase, sentence);
    strcpy(lowercase, sentence);

    for(i=0;uppercase[i];i++)
    {
        if(uppercase[i]!= lowercase[i])
        {
            flag = 1;
            break;
        }
    }

    if(flag)
    {
        printf("Given sentence contains both uppercase and lowercase letters.\n");
        printf("Converting sentence to lowercase.\n");
        for(i=0;sentence[i];i++)
        {
            sentence[i] = tolower(sentence[i]);
        }
    }

    else
    {
        printf("Given sentence contains only lowercase letters.\n");
    }

    for(i=0;uppercase[i];i++)
    {
        if(uppercase[i] == lowercase[i])
        {
            sentence[i] = tolower(sentence[i]);
        }
    }

    printf("Converted sentence: %s\n", sentence);
    return 0;
}