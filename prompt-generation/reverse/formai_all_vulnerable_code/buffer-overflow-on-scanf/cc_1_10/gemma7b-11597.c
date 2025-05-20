//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the C Online Examination System!\n");
    printf("Please select an option:\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter your first name:");
            char firstName[20];
            scanf("%s", firstName);

            printf("Enter your last name:");
            char lastName[20];
            scanf("%s", lastName);

            printf("Enter your email address:");
            char email[50];
            scanf("%s", email);

            // Insert code to register user here
            break;
        case 2:
            printf("Enter your email address:");
            char email2[50];
            scanf("%s", email2);

            printf("Enter your password:");
            char password[20];

            // Insert code to login user here
            break;
        case 3:
            printf("Thank you for using the C Online Examination System. Goodbye!\n");
            exit(0);
            break;
        default:
            printf("Invalid selection.\n");
            break;
    }

    return 0;
}