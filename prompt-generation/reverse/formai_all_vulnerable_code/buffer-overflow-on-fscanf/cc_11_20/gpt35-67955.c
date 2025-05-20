//FormAI DATASET v1.0 Category: Spell checking ; Style: Cyberpunk
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define WORD_LEN 20

void cyberpunk_spell_check(char *filename);

int main()
{
    char filename[50];

    printf("Enter the filename to spell check: ");
    scanf("%s", filename);

    cyberpunk_spell_check(filename);

    return 0;
}
void cyberpunk_spell_check(char *filename)
{
    FILE *fp=fopen(filename, "r");

    if(fp==NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    char word[WORD_LEN+1];
    int line_count=1;
    int error_count=0;

    while(fscanf(fp, "%s", word)!=EOF)
    {
        char *p=word;
        while(*p!='\0')
        {
            *p=tolower(*p);
            if(*p=='.' || *p==',' || *p=='-' || *p=='/' || *p=='!')
            {
                *p='\0';
                break;
            }
            p++;
        }

        if(strlen(word)<1 || strlen(word)>WORD_LEN)
        {
            continue;
        }

        if(strncmp(word, "//", 2)==0)
        {
            while(fgetc(fp)!='\n');
            line_count++;
            continue;
        }

        if(isdigit(word[0]))
        {
            continue;
        }

        if(strchr(word, '@')!=NULL || strstr(word, "http")!=NULL || strstr(word, ".com")!=NULL)
        {
            continue;
        }

        char dictionary[2705][6] = { //A list of words that would be frquently used in a cyberpunk programming context
            //Add your own words to the dictionary here
        };
        int length=sizeof(dictionary)/sizeof(dictionary[0]);
        int flag=0;
        for(int i=0; i<length; i++)
        {
            if(strcmp(word, dictionary[i])==0)
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
            printf("Error at line %d: %s\n", line_count, word);
            error_count++;
        }

        if(word[strlen(word)-1]=='\n')
        {
            line_count++;
        }
    }

    printf("\n%d spelling errors found!\n", error_count);

    fclose(fp);
}