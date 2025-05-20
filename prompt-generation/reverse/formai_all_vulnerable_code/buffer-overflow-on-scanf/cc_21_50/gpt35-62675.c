//FormAI DATASET v1.0 Category: Syntax parsing ; Style: puzzling
#include<stdio.h>
#include<string.h>

int main()
{
    char code[1000]; 
    int i=0, j=0, k=0, flag=0, count=0, is_int=0, is_float=0, is_char=0, is_string=0;

    printf("Enter the C code snippet: "); 
    scanf("%[^\n]s",code);

    while (code[i]!='\0')
    {
        if (code[i]=='/' && code[i+1]=='/')
        {
            while (code[i]!='\n')
                i++;
        }
        else if (code[i]=='/' && code[i+1]=='*')
        {
            i+=2;
            while (code[i]!='*' || code[i+1]!='/')
                i++;
            i+=2;
        }
        else if (code[i]=='\"')
        {
            if (!is_string)
                is_string=1;
            else
                is_string=0;
            i++;
        }
        else if (code[i]=='\'')
        {
            if (!is_char)
                is_char=1;
            else
                is_char=0;
            i++;
        }
        else if (is_string || is_char)
        {
            i++;
        }
        else if (code[i]>='0' && code[i]<='9')
        {
            if (is_float || is_int)
            {
                i++;
            }
            else
            {
                j=i;
                while ((code[j]>='0' && code[j]<='9') || code[j]=='.')
                {
                    if (code[j]=='.')
                    {
                        is_float=1;
                    }
                    j++;
                }
                if (is_float)
                {
                    is_int=0;
                }
                else
                {
                    is_int=1;
                }
                i=j;
            }
        }
        else if ((code[i]>='a' && code[i]<='z')||(code[i]>='A' && code[i]<='Z')||code[i]=='_')
        {
            flag=0;
            j=i;
            while ((code[j]>='a' && code[j]<='z')||(code[j]>='A' && code[j]<='Z')||(code[j]>='0' && code[j]<='9')||code[j]=='_')
            {   
                if (code[j]=='(')
                {
                    flag=1;
                }
                j++;
            }
            if (flag)
            {
                while (code[j]!=')')
                {
                    if (code[j]==',')
                        count++;
                    j++;
                }
                count++;
            }
            i=j;
        }
        else
        {
            i++;
        }
    }

    printf("\nNumber of integer variables: %d", count);
    return 0;
}