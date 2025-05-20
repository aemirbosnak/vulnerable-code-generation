//Falcon-180B DATASET v1.0 Category: Password management ; Style: puzzling
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

#define MAX 100

int main()
{
    int choice;
    char username[30], password[50];
    FILE *fp;
    struct user
    {
        char username[30];
        char password[50];
    }user[MAX];
    int count=0;

    printf("Enter choice:\n1. Signup\n2. Login\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        {
            printf("Enter username: ");
            scanf("%s",username);

            fp=fopen("user.txt","a");

            if(fp==NULL)
            {
                printf("Error in opening file\n");
                exit(0);
            }

            rewind(fp);

            while(fscanf(fp,"%s %s",user[count].username,user[count].password)!=EOF)
            {
                count++;
            }

            if(count==MAX)
            {
                printf("Maximum number of users reached\n");
                exit(0);
            }

            strcpy(user[count].username,username);

            printf("Enter password: ");
            scanf("%s",user[count].password);

            fprintf(fp,"%s %s\n",user[count].username,user[count].password);

            fclose(fp);

            printf("Signup successful\n");
            break;
        }

        case 2:
        {
            printf("Enter username: ");
            scanf("%s",username);

            fp=fopen("user.txt","r");

            if(fp==NULL)
            {
                printf("Error in opening file\n");
                exit(0);
            }

            while(fscanf(fp,"%s %s",user[count].username,user[count].password)!=EOF)
            {
                if(strcmp(user[count].username,username)==0)
                {
                    printf("Enter password: ");
                    scanf("%s",password);

                    if(strcmp(user[count].password,password)==0)
                    {
                        printf("Login successful\n");
                        exit(0);
                    }
                    else
                    {
                        printf("Incorrect password\n");
                        exit(0);
                    }
                }
                count++;
            }

            printf("User not found\n");
            exit(0);
        }

        default:
        {
            printf("Invalid choice\n");
            exit(0);
        }
    }

    return 0;
}