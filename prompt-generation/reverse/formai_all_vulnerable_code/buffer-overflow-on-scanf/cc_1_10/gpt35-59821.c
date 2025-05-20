//FormAI DATASET v1.0 Category: Text processing ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to find the longest word in the given sentence
char* longest_word(char *str)
{
    char *word,*longest_word_ptr;
    int len=0,max_len=0;

    word=strtok(str," ");
    while(word!=NULL)
    {
      len=strlen(word);
      if(len>max_len)
      {
           max_len=len;
           longest_word_ptr=word;
      }
      word=strtok(NULL," ");
    }

    return longest_word_ptr;
}

//Function to count the occurence of a given character in the sentence
int char_count(char *str,char c)
{
    int cnt=0;
    while(*str)
    {
        if(*str==c)
         cnt++;
        str++;
    }

    return cnt;
}

//Main Function
int main()
{
    char str[100];
    printf("Enter a sentence: ");
    gets(str);

    printf("\n\nThe Longest word in the sentence is: %s",longest_word(str));

    char c;
    printf("\n\nEnter the character to count its occurence: ");
    scanf("%c",&c);

    printf("\n\nThe Character %c occurs for : %d times",c,char_count(str,c));
    return 0;
}