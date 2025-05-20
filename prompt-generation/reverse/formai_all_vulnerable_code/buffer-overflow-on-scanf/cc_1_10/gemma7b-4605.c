//Gemma-7B DATASET v1.0 Category: System administration ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    system("clear");
    system("echo 'Welcome to the C System Administration Lab! Please select an option:'");

    printf("1. Create a new user\n");
    printf("2. Delete a user\n");
    printf("3. Modify a user's password\n");
    printf("4. View user information\n");

    int choice = 0;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            system("echo 'Enter the new user's name:");
            char username[255];
            scanf("%s", username);

            system("echo 'Enter the new user's password:");
            char password[255];
            scanf("%s", password);

            system("useradd -c \"$username\" -m $username -p $password");
            break;

        case 2:
            system("echo 'Enter the user's name:");
            char username2[255];
            scanf("%s", username2);

            system("userdel -r $username2");
            break;

        case 3:
            system("echo 'Enter the user's name:");
            char username3[255];
            scanf("%s", username3);

            system("echo 'Enter the new password:**");
            char newPassword[255];
            scanf("%s", newPassword);

            system("chage -m $username3 $newPassword");
            break;

        case 4:
            system("echo 'Enter the user's name:");
            char username4[255];
            scanf("%s", username4);

            system("cat /home/$username4/.profile");
            break;

        default:
            system("echo 'Invalid option. Please try again.'");
    }

    system("echo 'Thank you for using the C System Administration Lab. Please exit.'");

    return 0;
}