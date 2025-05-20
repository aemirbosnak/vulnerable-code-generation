//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void main()
{
    FILE *fp,*fp2;
    char ch,filename[100],filename2[100],temp;
    int i=0,j=0,k=0;

    printf("Enter the name of the file to be encrypted: ");
    scanf("%s",filename);

    fp=fopen(filename,"r");

    if(fp==NULL)
    {
        printf("File does not exist");
        exit(0);
    }

    fp2=fopen("encrypted.txt","w");

    if(fp2==NULL)
    {
        printf("File could not be created");
        exit(0);
    }

    while((ch=fgetc(fp))!=EOF)
    {
        if(isalpha(ch))
        {
            temp=ch+13;
            if(temp>='z')
            {
                temp=temp-'z'+'a'-1;
            }
            fprintf(fp2,"%c",temp);
        }
        else
        {
            fprintf(fp2,"%c",ch);
        }
    }

    fclose(fp);
    fclose(fp2);

    printf("File encrypted successfully");

    system("pause");
}