//FormAI DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // Maximum size of the password array

int main()
{
    char passwords[MAX_SIZE][MAX_SIZE]; // Array to store passwords
    int count = 0; // Track the number of passwords stored
    int choice = 0;

    while(choice != 4) // Loop until user chooses to exit
    {
        printf("1. Add a password\n");
        printf("2. View all passwords\n");
        printf("3. Delete a password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                if(count == MAX_SIZE) // Check if array is already full
                {
                    printf("Password limit reached. Cannot add more.\n");
                    break;
                }

                char temp[MAX_SIZE];
                printf("Enter new password: ");
                scanf("%s", temp);

                // Check if password already exists
                for(int i=0;i<count;i++)
                {
                    if(strcmp(passwords[i], temp) == 0)
                    {
                        printf("Password already exists. Please enter a unique password.\n");
                        break;
                    }
                }

                strcpy(passwords[count++], temp); // Add new password to array
                printf("Password added successfully!\n");
                break;
            }
            case 2:
            {
                if(count == 0) // Check if array is empty
                {
                    printf("No passwords stored. Add a password first.\n");
                    break;
                }

                printf("List of all passwords:\n");
                for(int i=0;i<count;i++)
                {
                    printf("%d. %s\n", i+1, passwords[i]);
                }
                break;
            }
            case 3:
            {
                if(count == 0) // Check if array is empty
                {
                    printf("No passwords stored. Add a password first.\n");
                    break;
                }

                int index = -1;
                char temp[MAX_SIZE];
                printf("Enter the password to delete: ");
                scanf("%s", temp);

                // Search for the password to delete
                for(int i=0;i<count;i++)
                {
                    if(strcmp(passwords[i], temp) == 0)
                    {
                        index = i;
                        break;
                    }
                }

                if(index == -1) // Password not found
                {
                    printf("Password not found. Please enter a valid password.\n");
                    break;
                }

                // Shift all passwords after the deleted one by one index to the left
                for(int i=index;i<count-1;i++)
                {
                    strcpy(passwords[i], passwords[i+1]);
                }

                count--; // Decrease the count of passwords stored
                printf("Password deleted successfully!\n");
                break;
            }
            case 4:
            {
                printf("Exiting...\n");
                break;
            }
            default:
            {
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
            }
        }
    }

    return 0;
}