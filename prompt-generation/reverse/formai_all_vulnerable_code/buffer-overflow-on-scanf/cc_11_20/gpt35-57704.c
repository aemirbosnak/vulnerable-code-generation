//FormAI DATASET v1.0 Category: System administration ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char username[50],password[50],choice[5];
    int login_status=0;
    printf("Welcome to Multivariable System Administration!\n");
    while(1)
    {
        printf("Enter choice:\n");
        printf("1.Login\n2.Create New User\n3.Exit\n");
        scanf("%s",choice);
        if(strcmp(choice,"1")==0) //login
        {
            while(1)
            {
                printf("Enter username:\n");
                scanf("%s",username);
                printf("Enter password:\n");
                scanf("%s",password);
                FILE *fp;
                fp=fopen("users.txt","r");
                char file_username[50],file_password[50];
                while(fscanf(fp,"%s %s",file_username,file_password)!=EOF)
                {
                    if(strcmp(username,file_username)==0 && strcmp(password,file_password)==0)
                    {
                        printf("Login successful!\n");
                        login_status=1;
                        break;
                    }
                }
                fclose(fp);
                if(login_status==1)
                    break;
                printf("Invalid credentials. Try again.\n");
            }
        }
        else if(strcmp(choice,"2")==0) //create new user
        {
            while(1)
            {
                printf("Enter new username:\n");
                scanf("%s",username);
                printf("Enter new password:\n");
                scanf("%s",password);
                FILE *fp;
                fp=fopen("users.txt","r");
                char file_username[50],file_password[50];
                while(fscanf(fp,"%s %s",file_username,file_password)!=EOF)
                {
                    if(strcmp(username,file_username)==0)
                    {
                        printf("Username already exists. Try a different one.\n");
                        break;
                    }
                }
                fclose(fp);
                if(strcmp(username,file_username)!=0)
                    break;
            }
            FILE *fp;
            fp=fopen("users.txt","a");
            fprintf(fp,"%s %s\n",username,password);
            fclose(fp);
            printf("User created successfully!\n");
        }
        else if(strcmp(choice,"3")==0) //exit
        {
            printf("Exiting Multivariable System Administration..");
            exit(0);
        }
        else
        {
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}