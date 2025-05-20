//Falcon-180B DATASET v1.0 Category: Database querying ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct
{
    char name[20];
    int age;
    char address[50];
    int phone;
}Person;

void addRecord(Person *p)
{
    FILE *fp;
    fp=fopen("database.txt","ab");
    if(fp==NULL)
    {
        printf("Error in opening file\n");
        exit(0);
    }
    fprintf(fp,"%s %d %s %d\n",p->name,p->age,p->address,p->phone);
    fclose(fp);
}

void displayRecord(Person p)
{
    printf("%s %d %s %d\n",p.name,p.age,p.address,p.phone);
}

void searchRecord(Person *p,char key[20])
{
    FILE *fp;
    char ch;
    fp=fopen("database.txt","r");
    if(fp==NULL)
    {
        printf("Error in opening file\n");
        exit(0);
    }
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='\n')
        {
            fseek(fp,-1,SEEK_CUR);
            if(fgetc(fp)==' ')
            {
                fseek(fp,-1,SEEK_CUR);
                if(fgetc(fp)==key[0])
                {
                    fseek(fp,-2,SEEK_CUR);
                    if(strcmp(&ch,key)==0)
                    {
                        displayRecord(*p);
                    }
                }
            }
        }
    }
    fclose(fp);
}

int main()
{
    Person p;
    char ch;
    int i=0;
    while(i<MAX)
    {
        printf("Enter name:");
        scanf("%s",p.name);
        printf("Enter age:");
        scanf("%d",&p.age);
        printf("Enter address:");
        scanf("%s",p.address);
        printf("Enter phone no.:");
        scanf("%d",&p.phone);
        addRecord(&p);
        printf("\nDo you want to continue? (y/n):");
        scanf(" %c",&ch);
        if(ch=='n')
        {
            break;
        }
    }
    printf("\nEnter the key to search:");
    scanf("%s",p.name);
    searchRecord(&p,p.name);
    return 0;
}