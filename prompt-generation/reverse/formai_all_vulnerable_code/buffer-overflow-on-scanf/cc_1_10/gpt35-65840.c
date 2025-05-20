//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

int main()
{
    FILE* fp;
    char filename[MAX];
    char ch;
    char search[MAX];
    int count=0;

    printf("Enter the file name: ");
    scanf("%s",filename);

    fp = fopen(filename,"r"); // opening the file in read mode

    if(fp == NULL)
    {
        printf("File does not exist!");
        exit(0);
    }

    printf("Enter the word to search: ");
    scanf("%s",search);

    while((ch=getc(fp))!=EOF)
    {
        if(ch==' ' || ch=='\n') // checking for spaces and new line characters
        {
            if(strcmp(search,"")==0)
            {
                count++; // increment the occurence count
            }
            else if(strcmp(filename,search)==0)
            {
                count++;
            }
            *search='\0'; // resetting the search string
        }
        else
        {
            strncat(search,&ch,1); // appending the character to the search string
        }
    }

    printf("\n\nThe word '%s' occurs %d times in file '%s' ",search,count,filename);

    fclose(fp);

    return 0;
}