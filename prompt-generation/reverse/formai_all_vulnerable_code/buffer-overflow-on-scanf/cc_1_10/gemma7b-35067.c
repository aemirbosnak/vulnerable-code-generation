//Gemma-7B DATASET v1.0 Category: System administration ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    system("banner 'WELCOME TO THE C-SYSTEM ADMINISTRATION STATION!'");
    printf("Please select an option:\n");
    printf("1. Create a new user\n");
    printf("2. Modify an existing user\n");
    printf("3. Delete a user\n");
    printf("4. View user list\n");

    int choice = 0;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            system("clear");
            system("banner 'CREATING A NEW USER...'");
            printf("Enter the new user's name: ");
            char name[20];
            scanf("%s", name);

            printf("Enter the new user's password: ");
            char password[20];
            scanf("%s", password);

            printf("Enter the new user's group: ");
            char group[20];
            scanf("%s", group);

            system("adduser -c $name -p $password -g $group");
            system("banner 'NEW USER CREATED!'");
            break;

        case 2:
            system("clear");
            system("banner 'MODIFYING AN EXISTING USER...'");
            printf("Enter the user's name: ");
            char old_name[20];
            scanf("%s", old_name);

            printf("Enter the new user's password: ");
            char new_password[20];
            scanf("%s", new_password);

            system("modifyuser -p $new_password -u $old_name");
            system("banner 'USER PASSWORD UPDATED!'");
            break;

        case 3:
            system("clear");
            system("banner 'DELETING A USER...'");
            printf("Enter the user's name: ");
            char del_name[20];
            scanf("%s", del_name);

            system("deluser -u $del_name");
            system("banner 'USER DELETED!'");
            break;

        case 4:
            system("clear");
            system("banner 'VIEWING USER LIST...'");
            system("userlist");
            break;

        default:
            system("banner 'Invalid choice!'");
    }

    return 0;
}