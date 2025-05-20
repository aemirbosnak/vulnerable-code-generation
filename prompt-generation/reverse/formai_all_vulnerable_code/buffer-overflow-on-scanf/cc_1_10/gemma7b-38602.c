//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: happy
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

    int choice = 0;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            system("clear");
            printf("Please provide your name:\n");
            char name[20];
            scanf("%s", name);

            printf("Please provide your email address:\n");
            char email[50];
            scanf("%s", email);

            printf("Please provide your phone number:\n");
            int phone = 0;
            scanf("%d", &phone);

            FILE *fp = fopen("users.txt", "a");
            fprintf(fp, "%s, %s, %d\n", name, email, phone);
            fclose(fp);

            system("clear");
            printf("Thank you for registering! Please login to continue.\n");
            break;

        case 2:
            system("clear");
            printf("Please provide your email address:\n");
            char email2[50];
            scanf("%s", email2);

            printf("Please provide your password:\n");
            char password[20];
            scanf("%s", password);

            FILE *fp2 = fopen("users.txt", "r");
            char username[20];
            char user_email[50];
            int user_phone = 0;
            int i = 0;

            while (fscanf(fp2, "%s, %s, %d\n", username, user_email, &user_phone) != EOF)
            {
                if (strcmp(email2, user_email) == 0)
                {
                    i = 1;
                    break;
                }
            }

            fclose(fp2);

            if (i == 1)
            {
                system("clear");
                printf("Welcome, %s!\n", username);
                printf("Please select an option:\n");
                printf("1. View your profile\n");
                printf("2. Take a quiz\n");
                printf("3. Logout\n");

                int option = 0;
                scanf("%d", &option);

                switch (option)
                {
                    case 1:
                        system("clear");
                        printf("Your name: %s\n", username);
                        printf("Your email address: %s\n", user_email);
                        printf("Your phone number: %d\n", user_phone);
                        break;

                    case 2:
                        system("clear");
                        printf("Sorry, there are no quizzes available yet.\n");
                        break;

                    case 3:
                        system("clear");
                        printf("Thank you for using the C Online Examination System, %s. See you next time!\n", username);
                        break;
                }
            }
            else
            {
                system("clear");
                printf("Invalid email address or password.\n");
            }

            break;

        case 3:
            system("clear");
            printf("Thank you for using the C Online Examination System. See you next time!\n");
            break;
    }

    return 0;
}