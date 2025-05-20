//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("clear");
    printf("Welcome to the C Online Examination System!\n");
    printf("Please select an option:\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");

    int choice = 0;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            system("clear");
            printf("Enter your first name:");
            char fname[20];
            scanf("%s", fname);

            printf("Enter your last name:");
            char lname[20];
            scanf("%s", lname);

            printf("Enter your email address:");
            char email[50];
            scanf("%s", email);

            FILE *fp = fopen("exam_data.txt", "a");
            fprintf(fp, "%s, %s, %s\n", fname, lname, email);
            fclose(fp);

            system("clear");
            printf("Thank you for registering! You can now login.\n");
            break;

        case 2:
            system("clear");
            printf("Enter your email address:");
            char email_login[50];
            scanf("%s", email_login);

            printf("Enter your password:");
            char password[20];
            scanf("%s", password);

            FILE *fp_login = fopen("exam_data.txt", "r");
            char data[1000];
            int i = 0;
            while (fscanf(fp_login, "%s, %s, %s\n", data) != EOF)
            {
                i++;
                if (strcmp(email_login, data) == 0)
                {
                    system("clear");
                    printf("Welcome, %s! You can now take the exam.\n", data);
                    break;
                }
            }

            if (i == 0)
            {
                system("clear");
                printf("Email not found. Please register first.\n");
            }
            fclose(fp_login);
            break;

        case 3:
            system("clear");
            printf("Thank you for using the C Online Examination System. Goodbye!\n");
            break;

        default:
            system("clear");
            printf("Invalid input. Please select a valid option.\n");
    }

    return 0;
}