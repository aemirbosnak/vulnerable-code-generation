//FormAI DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 5
#define MAX_PASSWORD_LENGTH 20

int main()
{
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    char user_choice;
    int password_count = 0;

    while(user_choice != '3') // Loop until user selects to exit
    {
        printf("Please select an option:\n");
        printf("1. Add a password\n");
        printf("2. View all passwords\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf(" %c", &user_choice);

        switch(user_choice)
        {
            case '1':
            {
                if(password_count < MAX_PASSWORDS)
                {
                    printf("Please enter a password: ");
                    scanf("%s", passwords[password_count]);
                    password_count++;
                    printf("Password added!\n");
                }
                else
                {
                    printf("Maximum number of passwords reached.\n");
                }
                break;
            }
            case '2':
            {
                if(password_count == 0)
                {
                    printf("There are no passwords stored.\n");
                }
                else
                {
                    printf("Passwords:\n");
                    for(int i = 0; i < password_count; i++)
                    {
                        printf("%d. %s\n", i + 1, passwords[i]);
                    }
                }
                break;
            }
            case '3':
            {
                printf("Exiting program.\n");
                break;
            }
            default:
            {
                printf("Invalid input. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}