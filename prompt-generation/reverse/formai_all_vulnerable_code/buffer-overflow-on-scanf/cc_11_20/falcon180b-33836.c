//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: multivariable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
    char input[100];
    char result[100];
    int checksum,i,j;
    char delimiter;
    printf("Enter a string: ");
    scanf("%[^\n]s",input);
    printf("Enter a delimiter: ");
    scanf("%c",&delimiter);
    checksum=0;
    for(i=0;input[i]!='\0';i++)
    {
        if(isalpha(input[i]))
        {
            input[i]=tolower(input[i]);
        }
        else if(isdigit(input[i]))
        {
            input[i]='0';
        }
        else
        {
            input[i]=' ';
        }
    }
    for(i=0;input[i]!='\0';i++)
    {
        if(isalpha(input[i]))
        {
            checksum+=input[i];
        }
        else if(isdigit(input[i]))
        {
            checksum+=input[i]-'0';
        }
        else if(input[i]==delimiter)
        {
            result[j++]=delimiter;
        }
    }
    result[j]='\0';
    for(i=0;result[i]!='\0';i++)
    {
        if(isalpha(result[i]))
        {
            checksum+=result[i];
        }
        else if(isdigit(result[i]))
        {
            checksum+=result[i]-'0';
        }
        else if(result[i]==delimiter)
        {
            printf("%d\n",checksum);
            checksum=0;
        }
    }
    printf("%d\n",checksum);
    return 0;
}