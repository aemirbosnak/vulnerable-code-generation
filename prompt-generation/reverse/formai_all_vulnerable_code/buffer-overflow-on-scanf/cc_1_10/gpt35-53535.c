//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: systematic
#include <stdio.h>
#include <string.h>

void alienTranslator(char* word){

    int len = strlen(word);

    for(int i=0; i<len; i++)
    {
        if(word[i] == 'z')
        {
            word[i] = 'a';
        }
        else if(word[i] >= 'a' && word[i] < 'z')
        {
            word[i] += 1;
        }
        else if(word[i] == 'Z')
        {
            word[i] = 'A';
        }
        else if(word[i] >= 'A' && word[i] < 'Z')
        {
            word[i] += 1;
        }
        else if(word[i] == ' ')
        {
            continue;
        }
        else
        {
            printf("Invalid Character Found!");
            return;
        }
    }

    printf("%s\n", word);
}

int main(){

    char word[100];

    printf("Enter a word in alien language: ");
    scanf("%[^\n]s", word);

    alienTranslator(word);

    return 0;
}