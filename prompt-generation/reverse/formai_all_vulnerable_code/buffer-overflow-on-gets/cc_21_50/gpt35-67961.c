//FormAI DATASET v1.0 Category: Text processing ; Style: shocked
#include<stdio.h>
#include<string.h>

int main()
{
    char sentence[1000];
    int i,j,k,l,c=0;
    printf("Enter a sentence:  ");
    gets(sentence);
    l=strlen(sentence);
    printf("\nProcessing...");

    for(i=0;i<l;i++)
    {
        if(sentence[i]==' ')
        {
            for(j=i+1;j<l;j++)
            {
                if(sentence[j]>='a' && sentence[j]<='z')
                {
                    for(k=j;k<l;k++)
                    {
                        if(sentence[k]==' ')
                        {
                            break;
                        }
                        else
                        {
                            printf("%c",sentence[k]-32);
                        }
                    }
                    printf(" ");
                    break;
                }
                else if(sentence[j]>='A' && sentence[j]<='Z')
                {
                    for(k=j;k<l;k++)
                    {
                        if(sentence[k]==' ')
                        {
                            break;
                        }
                        else
                        {
                            printf("%c",sentence[k]);
                        }
                    }
                    printf(" ");
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
        if(i==l-1)
        {
            if(sentence[i]>='a' && sentence[i]<='z')
            {
                for(k=i;k>=0;k--)
                {
                    if(sentence[k]==' ')
                    {
                        break;
                    }
                    else
                    {
                        printf("%c",sentence[k]-32);
                    }
                }
            }
            else if(sentence[i]>='A' && sentence[i]<='Z')
            {
                for(k=i;k>=0;k--)
                {
                    if(sentence[k]==' ')
                    {
                        break;
                    }
                    else
                    {
                        printf("%c",sentence[k]);
                    }
                }
            }
        }
    }
    printf("\nProcessing finished.");
    return 0;
}