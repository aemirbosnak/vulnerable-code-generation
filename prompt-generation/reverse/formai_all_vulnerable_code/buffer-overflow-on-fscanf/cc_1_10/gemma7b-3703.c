//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("cls");
    printf("Welcome to the Montague-Capulet Online Examination System!\n");
    printf("Please select an option:\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");

    int choice = 0;
    scanf(" %d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter your first name:");
            char firstName[20];
            scanf(" %s", firstName);

            printf("Enter your last name:");
            char lastName[20];
            scanf(" %s", lastName);

            printf("Enter your email address:");
            char email[20];
            scanf(" %s", email);

            printf("Enter your password:");
            char password[20];
            scanf(" %s", password);

            FILE *fp = fopen("exam_data.txt", "a");
            fprintf(fp, "%s %s %s %s %s\n", firstName, lastName, email, password, "Montague");
            fclose(fp);

            printf("Thank you for registering, %s %s!\n", firstName, lastName);
            break;

        case 2:
            printf("Enter your email address:");
            char email2[20];
            scanf(" %s", email2);

            printf("Enter your password:");
            char password2[20];
            scanf(" %s", password2);

            FILE *fp2 = fopen("exam_data.txt", "r");
            char data[1000];
            fscanf(fp2, "%s", data);

            int found = 0;
            for (int i = 0; i < strlen(data); i++)
            {
                char email3[20];
                char password3[20];
                fscanf(fp2, "%s %s %s", email3, password3, data);

                if (strcmp(email, email3) == 0 && strcmp(password, password3) == 0)
                {
                    found = 1;
                    break;
                }
            }

            fclose(fp2);

            if (found)
            {
                printf("Welcome back, %s %s!\n", firstName, lastName);
            }
            else
            {
                printf("Email or password incorrect.\n");
            }
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("Invalid input.\n");
            break;
    }

    return 0;
}