//Falcon2-11B DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct password_entry
{
    char username[50];
    char password[50];
} password_entry;

int main()
{
    password_entry passwords[MAX_PASSWORDS];
    int n, i;

    printf("Enter number of passwords to add: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Username: ");
        scanf("%s", passwords[i].username);

        printf("Password: ");
        scanf("%s", passwords[i].password);
    }

    printf("\n");

    printf("Select an option:\n");
    printf("1. Add password\n");
    printf("2. Retrieve password\n");
    printf("3. Update password\n");
    printf("4. Delete password\n");
    printf("5. Exit\n");

    int choice;

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Username: ");
                scanf("%s", passwords[choice].username);
                printf("Password: ");
                scanf("%s", passwords[choice].password);
                break;

            case 2:
                printf("Username: ");
                scanf("%s", passwords[choice].username);
                printf("%s\n", passwords[choice].password);
                break;

            case 3:
                printf("Username: ");
                scanf("%s", passwords[choice].username);
                printf("Password: ");
                scanf("%s", passwords[choice].password);
                break;

            case 4:
                printf("Username: ");
                scanf("%s", passwords[choice].username);
                printf("\n");
                break;

            case 5:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}