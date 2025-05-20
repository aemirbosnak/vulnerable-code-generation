//FormAI DATASET v1.0 Category: HTML beautifier ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char keyword[][10] ={"if","else","for","while","do","int","float","char","double","static","struct","typedef","union","void","goto","case","break","switch","long","short","unsigned","sizeof","return","const","continue","volatile","register","default","extern"};

int main()
{
    FILE *fp1,*fp2;
    char ch, input[1000],filename[20];
    int i,j,n=0;
    printf("Enter the filename with extension: ");
    scanf("%s",filename);
    fp1=fopen(filename,"r");
    if(!fp1)
    {
        printf("File doesn't exist!");
        exit(0);
    }
    while((ch=fgetc(fp1))!=EOF)
    {
        input[n++]=ch;
    }
    fclose(fp1);
    input[n]='\0';
    fp2=fopen("formatted.html","w");
    if(!fp2)
    {
        printf("Error creating file!");
        exit(0);
    }
    for(i=0;i<strlen(input);i++)
    {
        if(input[i]=='<')
        {
            fputc(input[i],fp2);
            if(input[i+1]!='/')
            {
                fputc('\n',fp2);
                for(j=0;j<(i/4);j++)
                {
                    fputc('\t',fp2);
                }
            }
            else
            {
                for(j=0;j<(i/4)-1;j++)
                {
                    fputc('\t',fp2);
                }
            }
        }
        else if(input[i]=='>')
        {
            fputc(input[i],fp2);
            if(input[i-1]!='/')
            {
                fputc('\n',fp2);
                for(j=0;j<((i-1)/4);j++)
                {
                    fputc('\t',fp2);
                }
            }
        }
        else if(input[i]=='/')
        {
            fputc(input[i],fp2);
            if(input[i+1]=='>')
            {
                fputc('\n',fp2);
                for(j=0;j<(i/4);j++)
                {
                    fputc('\t',fp2);
                }
            }
        }
        else if(input[i]==' ' && input[i-1]!=' ' && input[i+1]!=' ' && input[i+1]!='>' && input[i+1]!='>')
        {
            fputc(input[i],fp2);
        }
        else if(input[i]=='\n' && input[i-1]!='>')
        {
            fputc(input[i],fp2);
            for(j=0;j<(i/4);j++)
            {
                fputc('\t',fp2);
            }
        }
        else if(input[i]!=' ' && input[i+1]==' ' && input[i-1]!='>')
        {
            fputc(input[i],fp2);
            fputc(' ',fp2);
        }
        else if(input[i]==' ' && input[i-1]!=' ' && input[i+1]!=' ' && input[i+1]!='>' && input[i+1]!='/')
        {
            fputc(input[i],fp2);
        }
        else if(input[i-1]==' ' && input[i+1]!=' ' && input[i+1]!='>' && input[i]!=' ')
        {
            fputc(input[i],fp2);
        }
        else if(input[i]==' ' && input[i-1]=='>' && input[i+1]!=' ')
        {
            fputc(input[i],fp2);
        }
        else if(input[i]!=' ' && input[i-1]==' ' && input[i+1]!=' ')
        {
            fputc(input[i],fp2);
        }
        else if(input[i+1]==' ' && input[i]!=' ' && input[i-1]!='>')
        {
            fputc(input[i],fp2);
        }
        else if(input[i]==' ' && input[i+1]==' ')
        {
            continue;
        }
        else
        {
            fputc(input[i],fp2);
        }
    }
    fclose(fp2);
    printf("Formatted HTML has been created successfully!");
    return 0;
}