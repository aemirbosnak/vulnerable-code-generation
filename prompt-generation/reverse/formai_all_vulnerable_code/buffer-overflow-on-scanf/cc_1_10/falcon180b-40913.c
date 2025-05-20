//Falcon-180B DATASET v1.0 Category: Password management ; Style: random
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100

struct password
{
    char name[50];
    char username[50];
    char password[50];
};

void main()
{
    int choice,i;
    char ch[50];
    FILE *fp;
    struct password p[MAX];

    fp=fopen("password.txt","ab");

    if(fp==NULL)
    {
        printf("File does not exist\n");
        exit(0);
    }

    while(1)
    {
        printf("\n\nPassword Manager\n");
        printf("1.Create Account\n2.Login\n3.Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter Name: ");
                scanf("%s",p[i].name);
                printf("Enter Username: ");
                scanf("%s",p[i].username);
                printf("Enter Password: ");
                scanf("%s",p[i].password);
                fwrite(&p[i],sizeof(p[i]),1,fp);
                printf("\nAccount Created Successfully\n");
                break;

            case 2:
                printf("Enter Username: ");
                scanf("%s",ch);
                fp=fopen("password.txt","rb");

                if(fp==NULL)
                {
                    printf("\nFile does not exist\n");
                    exit(0);
                }

                while(fread(&p[i],sizeof(p[i]),1,fp)==1)
                {
                    if(strcmp(p[i].username,ch)==0)
                    {
                        printf("\nEnter Password: ");
                        scanf("%s",ch);

                        if(strcmp(p[i].password,ch)==0)
                        {
                            printf("\nLogin Successful\n");
                            break;
                        }
                        else
                        {
                            printf("\nIncorrect Password\n");
                        }
                    }
                }

                fclose(fp);
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid Choice\n");
        }
    }
}