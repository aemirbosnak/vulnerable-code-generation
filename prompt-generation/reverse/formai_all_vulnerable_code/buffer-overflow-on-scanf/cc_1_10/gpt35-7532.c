//FormAI DATASET v1.0 Category: Password management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int choice, i, n, len;
    char password[50], new_pass[50];
    FILE *fptr;
    fptr = fopen("password.txt", "w");
    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    do
    {
        printf("\nPassword Management System\n");
        printf("--------------------------\n");
        printf("1. Create Password\n");
        printf("2. Display Password\n");
        printf("3. Change Password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the password: ");
                scanf("%s", password);
                len = strlen(password);
                for (i = 0; i < len; i++)
                {
                    password[i] += 3;
                }
                fprintf(fptr, "%s\n", password);
                printf("Password saved successfully.\n");
                break;
            case 2:
                printf("Saved Passwords:\n");
                printf("------------------\n");
                rewind(fptr);
                while (fscanf(fptr, "%s", password) != EOF)
                {
                    len = strlen(password);
                    for (i = 0; i < len; i++)
                    {
                        password[i] -= 3;
                    }
                    printf("%s\n", password);
                }
                printf("------------------\n");
                break;
            case 3:
                printf("Enter the new password: ");
                scanf("%s", new_pass);
                len = strlen(new_pass);
                for (i = 0; i < len; i++)
                {
                    new_pass[i] += 3;
                }
                printf("Password changed successfully.\n");
                break;
        }

    } while (choice != 4);

    fclose(fptr);
}