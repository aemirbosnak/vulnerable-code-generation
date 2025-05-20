//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<math.h>

#define MAX 1000000
#define PI 3.14159265358979323846

int main()
{
    int i,j,k,l,count=0;
    char file_name[20],ch,key[20];
    FILE *fp,*fq;
    time_t t;
    
    printf("\nEnter the file name: ");
    scanf("%s",file_name);
    
    printf("\nEnter the key: ");
    scanf("%s",key);
    
    fp=fopen(file_name,"r");
    if(fp==NULL)
    {
        printf("\nFile does not exist");
        exit(0);
    }
    fclose(fp);
    
    fp=fopen(file_name,"r");
    fq=fopen("enc.txt","w");
    
    if(fp==NULL || fq==NULL)
    {
        printf("\nUnable to open file");
        exit(0);
    }
    
    srand(time(&t));
    for(i=0;i<strlen(key);i++)
    {
        if(isalpha(key[i]))
        {
            key[i]=tolower(key[i]);
        }
    }
    
    while((ch=fgetc(fp))!=EOF)
    {
        if(isalpha(ch))
        {
            ch=tolower(ch);
            j=0;
            while(key[j]!='\0')
            {
                if(ch==key[j])
                {
                    count++;
                    break;
                }
                j++;
            }
        }
        else
        {
            count=0;
        }
        if(count%2==0)
        {
            fprintf(fq,"%c",ch);
        }
        else
        {
            fprintf(fq,"%c",ch+32);
        }
    }
    
    fclose(fp);
    fclose(fq);
    
    printf("\nFile encrypted successfully");
    
    return 0;
}