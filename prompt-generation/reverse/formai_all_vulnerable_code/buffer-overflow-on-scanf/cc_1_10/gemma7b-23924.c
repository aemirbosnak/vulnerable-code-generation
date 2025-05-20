//Gemma-7B DATASET v1.0 Category: System administration ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void manage_users(int *users)
{
    int i, new_user, old_user, found = 0;
    char username[MAX];

    printf("Enter 'add' to add a user, 'search' to search for a user, or 'delete' to delete a user: ");
    scanf("%s", username);

    switch (username[0])
    {
        case 'a':
            printf("Enter the new user's name: ");
            scanf("%d", &new_user);
            users[new_user] = 1;
            printf("User added successfully.\n");
            break;
        case 's':
            printf("Enter the user's name: ");
            scanf("%d", &old_user);
            for (i = 0; i < MAX; i++)
            {
                if (users[i] == old_user)
                {
                    found = 1;
                    break;
                }
            }
            if (found)
            {
                users[old_user] = 0;
                printf("User deleted successfully.\n");
            }
            else
            {
                printf("User not found.\n");
            }
            break;
        case 'd':
            printf("Enter the user's name: ");
            scanf("%d", &old_user);
            for (i = 0; i < MAX; i++)
            {
                if (users[i] == old_user)
                {
                    found = 1;
                    break;
                }
            }
            if (found)
            {
                users[old_user] = 0;
                printf("User deleted successfully.\n");
            }
            else
            {
                printf("User not found.\n");
            }
            break;
        default:
            printf("Invalid command.\n");
    }
}

int main()
{
    int users[MAX] = {0};

    manage_users(users);

    return 0;
}