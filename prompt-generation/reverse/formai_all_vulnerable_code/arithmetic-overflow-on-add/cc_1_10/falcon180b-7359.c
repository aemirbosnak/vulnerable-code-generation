//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    FILE *fp,*fp1;
    char ch,filename[100],filename1[100],cipher[100];
    int i,j,k,n,choice;

    printf("Enter the name of the file to be encrypted: ");
    scanf("%s",filename);

    fp=fopen(filename,"r");

    if(fp==NULL)
    {
        printf("File does not exist!!\n");
        exit(0);
    }

    printf("Enter the name of the encrypted file: ");
    scanf("%s",filename1);

    fp1=fopen(filename1,"w");

    if(fp1==NULL)
    {
        printf("Cannot create file!!\n");
        exit(0);
    }

    printf("Enter the encryption key: ");
    scanf("%d",&n);

    while((ch=fgetc(fp))!=EOF)
    {
        if(isalpha(ch))
        {
            if(isupper(ch))
            {
                cipher[0]=ch+n;
                if(cipher[0]>'Z')
                {
                    cipher[0]='A'+cipher[0]-('Z'+1);
                }
            }
            else
            {
                cipher[0]=ch+n;
                if(cipher[0]>'z')
                {
                    cipher[0]='a'+cipher[0]-('z'+1);
                }
            }
        }
        else
        {
            cipher[0]=ch;
        }
        fputc(cipher[0],fp1);
    }

    fclose(fp);
    fclose(fp1);

    printf("File encrypted successfully!!\n");

    return 0;
}