//Gemma-7B DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char password[20];
    char new_password[20];
    char confirm_password[20];
    int i, j, k, l;

    system("clear");
    printf("#####################################\n");
    printf("C Password Management System Version 0.1\n");
    printf("#####################################\n\n");

    printf("Enter your current password: ");
    scanf("%s", password);

    printf("Enter your new password: ");
    scanf("%s", new_password);

    printf("Confirm your new password: ");
    scanf("%s", confirm_password);

    for (i = 0; password[i] != '\0'; i++)
    {
        for (j = 0; new_password[j] != '\0'; j++)
        {
            if (password[i] == new_password[j])
            {
                printf("Error: The new password is not unique.\n");
                system("clear");
                main();
            }
        }
    }

    if (strcmp(new_password, confirm_password) != 0)
    {
        printf("Error: The new password and confirm password do not match.\n");
        system("clear");
        main();
    }

    printf("Password changed successfully.\n");
    system("clear");
    main();
}