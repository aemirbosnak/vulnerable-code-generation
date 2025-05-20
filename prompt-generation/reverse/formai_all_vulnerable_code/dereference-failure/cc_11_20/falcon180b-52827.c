//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct node
{
    char name[MAX];
    int size;
    int date;
    int time;
    char type;
};

void main()
{
    FILE *fp1,*fp2;
    struct node f1,f2;

    fp1=fopen("file1.txt","r");
    fp2=fopen("file2.txt","r");

    if(fp1==NULL || fp2==NULL)
    {
        printf("Error in opening file\n");
        exit(0);
    }

    while(fscanf(fp1,"%s %d %d %d %c",f1.name,&f1.size,&f1.date,&f1.time,&f1.type)!=EOF)
    {
        while(fscanf(fp2,"%s %d %d %d %c",f2.name,&f2.size,&f2.date,&f2.time,&f2.type)!=EOF)
        {
            if(strcmp(f1.name,f2.name)==0)
            {
                if(f1.date==f2.date && f1.time==f2.time)
                {
                    printf("Files are synchronized\n");
                    exit(0);
                }
                else if(f1.date>f2.date || (f1.date==f2.date && f1.time>f2.time))
                {
                    printf("Copy file1 to file2\n");
                    exit(0);
                }
                else
                {
                    printf("Copy file2 to file1\n");
                    exit(0);
                }
            }
            else if(strcmp(f1.name,f2.name)!=0 && f1.date>f2.date)
            {
                printf("Copy file1 to file2\n");
                exit(0);
            }
            else
            {
                f2=f1;
            }
        }
    }
    printf("File2 is updated\n");
    exit(0);
}