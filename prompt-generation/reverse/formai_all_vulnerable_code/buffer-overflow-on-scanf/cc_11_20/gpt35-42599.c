//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    printf("\nWelcome to the C Secure Password Generator\n\n");

    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+/*-=[]\\;',./{}|:<>?";
    char password[20] = "";
    char choice[3] = "";
    int len = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;

    srand(time(NULL));

    printf("Please enter the length of your password: ");
    scanf("%d", &len);

    while (len < 6)
    {
        printf("\nPassword must be at least 6 characters long.\n");
        printf("Please enter the length of your password: ");
        scanf("%d", &len);
    }

    while (1)
    {
        printf("\nDo you want to include lowercase characters? (y/n): ");
        scanf("%s", choice);

        if (strcmp(choice, "y") == 0)
        {
            strcat(password, lowercase);
            break;
        }
        else if (strcmp(choice, "n") == 0)
        {
            break;
        }
        else
        {
            printf("Invalid choice, please enter y or n.\n");
        }
    }

    while (1)
    {
        printf("\nDo you want to include uppercase characters? (y/n): ");
        scanf("%s", choice);

        if (strcmp(choice, "y") == 0)
        {
            strcat(password, uppercase);
            break;
        }
        else if (strcmp(choice, "n") == 0)
        {
            break;
        }
        else
        {
            printf("Invalid choice, please enter y or n.\n");
        }
    }

    while (1)
    {
        printf("\nDo you want to include numbers? (y/n): ");
        scanf("%s", choice);

        if (strcmp(choice, "y") == 0)
        {
            strcat(password, numbers);
            break;
        }
        else if (strcmp(choice, "n") == 0)
        {
            break;
        }
        else
        {
            printf("Invalid choice, please enter y or n.\n");
        }
    }

    while (1)
    {
        printf("\nDo you want to include symbols? (y/n): ");
        scanf("%s", choice);

        if (strcmp(choice, "y") == 0)
        {
            strcat(password, symbols);
            break;
        }
        else if (strcmp(choice, "n") == 0)
        {
            break;
        }
        else
        {
            printf("Invalid choice, please enter y or n.\n");
        }
    }

    int password_len = strlen(password);

    for (i = 0; i < len; i++)
    {
        k = rand() % password_len;
        password[i] = password[k];
    }

    printf("\nYour secure password is: %s\n\n", password);

    return 0;
}