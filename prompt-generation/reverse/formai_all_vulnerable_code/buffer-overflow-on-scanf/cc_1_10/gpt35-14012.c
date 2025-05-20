//FormAI DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char name[MAX];
    char username[MAX];
    char password[MAX];
} Account;

void clear_buffer()
{
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int validate(char *username, char *password)
{
    Account account;
    FILE *fp = fopen("passwords.dat", "rb");

    while (fread(&account, sizeof(Account), 1, fp) == 1)
    {
        if (strcmp(username, account.username) == 0)
        {
            if (strcmp(password, account.password) == 0)
            {
                printf("\n\nWelcome %s!\n\n", account.name);
                fclose(fp);
                return 1;
            }
            else
            {
                printf("\n\nInvalid Password!\n\n");
                fclose(fp);
                return 0;
            }
        }
    }

    printf("\n\nInvalid Username!\n\n");
    fclose(fp);
    return 0;
}

void create_account()
{
    Account account;
    FILE *fp = fopen("passwords.dat", "ab");

    printf("Enter your Full Name: ");
    fgets(account.name, MAX, stdin);
    printf("Enter your Username: ");
    fgets(account.username, MAX, stdin);
    printf("Enter your Password: ");
    fgets(account.password, MAX, stdin);

    fwrite(&account, sizeof(Account), 1, fp);
    fclose(fp);

    printf("\n\nAccount created successfully!\n\n");
}

int main()
{
    int choice;
    char username[MAX], password[MAX];

    printf("1. Login\n");
    printf("2. Create Account\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    clear_buffer();

    switch (choice)
    {
    case 1:
        printf("Enter your Username: ");
        fgets(username, MAX, stdin);
        printf("Enter your Password: ");
        fgets(password, MAX, stdin);

        validate(username, password);
        break;

    case 2:
        create_account();
        break;

    case 3:
        printf("\n\nGoodbye!\n\n");
        exit(0);
        break;

    default:
        printf("\n\nInvalid Choice!\n\n");
        break;
    }

    return 0;
}