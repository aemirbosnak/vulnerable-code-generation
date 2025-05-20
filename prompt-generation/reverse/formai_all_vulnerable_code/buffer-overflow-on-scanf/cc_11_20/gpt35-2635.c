//FormAI DATASET v1.0 Category: Password management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info
{
    char username[20];
    char password[20];
};

int main()
{
    struct info accounts[10];  // Database of up to 10 accounts
    
    int choice = 0;
    
    printf("*** Password Management System ***\n\n");

    while(choice != 4)
    {
        printf("1. Add Account\n");
        printf("2. View Account\n");
        printf("3. Delete Account\n");
        printf("4. Quit\n");
        
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int index = -1;
                for(int i=0; i<10; i++)   // Loop through database to find an empty index
                {
                    if(strcmp(accounts[i].username, "") == 0 && strcmp(accounts[i].password, "") == 0)
                    {
                        index = i;
                        break;
                    }
                }
                
                if(index != -1)     // Empty index was found
                {
                    printf("\nEnter username: ");
                    scanf("%s", accounts[index].username);
                    printf("Enter password: ");
                    scanf("%s", accounts[index].password);
                    printf("\nAccount created successfully!\n\n");
                }
                else    // Database is full
                {
                    printf("\nDatabase is full. Cannot create new account.\n\n");
                }
                
                break;
            }
            case 2:
            {
                char username[20];
                char password[20];
                int index = -1;
                int found = 0;
                
                printf("\nEnter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                
                for(int i=0; i<10; i++)   // Loop through database to find matching account
                {
                    if(strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0)
                    {
                        index = i;
                        found = 1;
                        break;
                    }
                }
                
                if(found)   // Matching account found
                {
                    printf("\n");
                    printf("Username: %s\n", accounts[index].username);
                    printf("Password: %s\n\n", accounts[index].password);
                }
                else    // Matching account not found
                {
                    printf("\n");
                    printf("Account not found.\n\n");
                }
                
                break;
            }
            case 3:
            {
                char username[20];
                char password[20];
                int index = -1;
                int found = 0;
                
                printf("\nEnter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                
                for(int i=0; i<10; i++)   // Loop through database to find matching account
                {
                    if(strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0)
                    {
                        index = i;
                        found = 1;
                        break;
                    }
                }
                
                if(found)   // Matching account found
                {
                    strcpy(accounts[index].username, "");
                    strcpy(accounts[index].password, "");
                    printf("\nAccount deleted successfully!\n\n");
                }
                else    // Matching account not found
                {
                    printf("\nAccount not found.\n\n");
                }
                
                break;
            }
            case 4:
            {
                printf("\nExiting program...\n\n");
                break;
            }
            default:
            {
                printf("\nInvalid choice. Try again.\n\n");
                break;
            }
        }
    }

    return 0;
}