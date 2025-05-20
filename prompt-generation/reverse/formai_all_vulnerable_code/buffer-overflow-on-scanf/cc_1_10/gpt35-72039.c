//FormAI DATASET v1.0 Category: Password management ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

void createPassword();
void viewPassword();
void modifyPassword();
void deletePassword();

struct password{
    char website[MAX];
    char userName[MAX];
    char pass[MAX];
};

struct password pData[MAX];
int pCount = 0;
char masterPass[MAX] = "mypassword";

int main()
{
    int choice;
    char password[MAX];

    printf("Enter Master Password: ");
    scanf("%s", password);

    while(strcmp(password, masterPass) != 0)
    {
        printf("\nWrong Password! Try Again.\n");
        printf("Enter Master Password: ");
        scanf("%s", password);
    }

    printf("\nWELCOME TO PASSWORD MANAGER\n");

    while(1)
    {
        printf("\n1. Create New Password\n");
        printf("2. View Passwords\n");
        printf("3. Modify Password\n");
        printf("4. Delete Password\n");
        printf("5. Exit\n");
        printf("\nEnter your Choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createPassword();
                break;

            case 2:
                viewPassword();
                break;

            case 3:
                modifyPassword();
                break;

            case 4:
                deletePassword();
                break;

            case 5:
                printf("\nThank You for using Password Manager\n");
                exit(0);

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }
    }

    return 0;
}

void createPassword()
{
    printf("\nEnter Website Name: ");
    scanf("%s", pData[pCount].website);

    printf("Enter User Name: ");
    scanf("%s", pData[pCount].userName);

    printf("Enter Password: ");
    scanf("%s", pData[pCount].pass);

    pCount++;

    printf("\nPassword Added Successfully!\n");
}

void viewPassword()
{
    if(pCount == 0)
    {
        printf("\nNo Passwords Found!\n");
        return;
    }

    int i;

    printf("\nWebsite Name\tUser Name\tPassword\n");

    for(i=0; i<pCount; i++)
    {
        printf("%s\t\t%s\t\t%s\n", pData[i].website, pData[i].userName, pData[i].pass);
    }
}

void modifyPassword()
{
    if(pCount == 0)
    {
        printf("\nNo Passwords Found!\n");
        return;
    }

    char website[MAX];
    int i, found = 0;

    printf("\nEnter Website Name: ");
    scanf("%s", website);

    for(i=0; i<pCount; i++)
    {
        if(strcmp(pData[i].website, website) == 0)
        {
            found = 1;

            printf("\nEnter New User Name: ");
            scanf("%s", pData[i].userName);

            printf("Enter New Password: ");
            scanf("%s", pData[i].pass);

            printf("\nPassword Modified Successfully!\n");
            break;
        }
    }

    if(found == 0)
    {
        printf("\nWebsite Not Found!\n");
    }
}

void deletePassword()
{
    if(pCount == 0)
    {
        printf("\nNo Passwords Found!\n");
        return;
    }

    char website[MAX];
    int i, j, found = 0;

    printf("\nEnter Website Name: ");
    scanf("%s", website);

    for(i=0; i<pCount; i++)
    {
        if(strcmp(pData[i].website, website) == 0)
        {
            found = 1;

            for(j=i; j<pCount-1; j++)
            {
                strcpy(pData[j].website, pData[j+1].website);
                strcpy(pData[j].userName, pData[j+1].userName);
                strcpy(pData[j].pass, pData[j+1].pass);
            }

            pCount--;

            printf("\nPassword Deleted Successfully!\n");
            break;
        }
    }

    if(found == 0)
    {
        printf("\nWebsite Not Found!\n");
    }
}