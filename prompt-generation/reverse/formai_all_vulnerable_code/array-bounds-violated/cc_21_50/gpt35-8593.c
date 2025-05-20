//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Claude Shannon
#include<stdio.h>
#include<string.h>

int main()
{
    char input[100],output[100],temp[100];
    int i,j,k;
    printf("Enter a sentence in C Cat language: ");
    fgets(input,100,stdin);
    input[strlen(input)-1]='\0';
    k=0;
    for(i=0;i<strlen(input);i++)
    {
        if(input[i]=='m'&&input[i+1]=='e'&&input[i+2]=='o'&&input[i+3]=='w')
        {
            output[k++]='c';
            output[k++]='a';
            output[k++]='t';
            i=i+3;
        }
        else if(input[i]=='p'&&input[i+1]=='u'&&input[i+2]=='r'&&input[i+3]=='r')
        {
            output[k++]='p';
            output[k++]='u';
            output[k++]='r';
            output[k++]='r';
            i=i+3;
        }
        else if(input[i]=='h'&&input[i+1]=='i'&&input[i+2]=='s'&&input[i+3]=='s')
        {
            output[k++]='s';
            output[k++]='s';
            output[k++]='h';
            i=i+3;
        }
        else if(input[i]=='m'&&input[i+1]=='e'&&input[i+2]=='r'&&input[i+3]=='r')
        {
            output[k++]='m';
            output[k++]='u';
            output[k++]='r';
            output[k++]='r';
            i=i+3;
        }
        else if(input[i]=='b'&&input[i+1]=='i'&&input[i+2]=='t'&&input[i+3]=='e')
        {
            output[k++]='b';
            output[k++]='i';
            output[k++]='t';
            output[k++]='e';
            i=i+3;
        }
        else 
        {
            output[k++]=input[i];
        }
    }
    output[k]='\0';
    printf("Translated sentence: %s\n",output);
    return 0;
}