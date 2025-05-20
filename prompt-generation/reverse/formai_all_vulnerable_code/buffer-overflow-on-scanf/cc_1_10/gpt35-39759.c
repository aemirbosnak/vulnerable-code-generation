//FormAI DATASET v1.0 Category: Password management ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_PASSWORDS 5
#define MAX_LENGTH 20

int main()
{
    char passwords[MAX_PASSWORDS][MAX_LENGTH];
    char input[MAX_LENGTH];
    int password_count = 0;
    printf("Welcome to Password Manager!\n\n");
    printf("Enter 'list' to view saved passwords or 'exit' to quit.\n\n");

    while(1)
    {   
        printf("Enter a password: ");
        scanf("%s", input);
        if(strcmp(input, "exit") == 0)
        {
            printf("Goodbye!\n");
            break;
        }
        else if(strcmp(input, "list") == 0)
        {
            if(password_count == 0)
            {
                printf("No passwords saved yet.\n\n");
                continue;
            }
            printf("Saved Passwords:\n");
            for(int i = 0; i < password_count; i++)
                printf("%s\n", passwords[i]);
            printf("\n");
            continue;
        }
        else if(strlen(input) > MAX_LENGTH)
        {
            printf("Password length cannot exceed %d characters.\n\n", MAX_LENGTH);
            continue;
        }
        else if(password_count == MAX_PASSWORDS)
        {
            printf("Maximum password limit reached.\n\n");
            continue;
        }
        else
        {
            printf("Password saved successfully.\n\n");
            strcpy(passwords[password_count], input);
            password_count++;
            continue;
        }
    }
    return 0;
}