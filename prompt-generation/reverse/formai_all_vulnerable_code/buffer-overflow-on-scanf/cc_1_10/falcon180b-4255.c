//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    FILE *fp,*fp1;
    char filename[100],filename1[100],ch,ch1;
    int i,j,k,l,count=0;
    char key[100];

    printf("Enter the file name to be encrypted: ");
    scanf("%s",filename);

    printf("Enter the key for encryption: ");
    scanf("%s",key);

    fp = fopen(filename,"r");
    if(fp==NULL)
    {
        printf("File not found!");
        exit(0);
    }

    fp1 = fopen("encrypted.txt","w");
    if(fp1==NULL)
    {
        printf("File not created!");
        exit(0);
    }

    while((ch=fgetc(fp))!=EOF)
    {
        if(isalpha(ch))
        {
            ch1 = tolower(ch);
            i = ch1 - 'a';

            j = i + count;

            if(isupper(ch))
            {
                k = 1;
            }
            else
            {
                k = 0;
            }

            if(k==1)
            {
                l = 65;
            }
            else
            {
                l = 97;
            }

            ch1 = l + j % 26;

            if(isupper(ch))
            {
                ch1 = toupper(ch1);
            }

            fprintf(fp1,"%c",ch1);
        }
        else
        {
            fprintf(fp1,"%c",ch);
        }
        count++;
    }

    fclose(fp);
    fclose(fp1);

    printf("File encrypted successfully!");

    return 0;
}