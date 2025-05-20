//FormAI DATASET v1.0 Category: Password management ; Style: expert-level
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char password[20] = "password"; // Initialize the master password
char username[20] = "admin"; // Initialize the master username

struct credentials // Define the credentials struct
{
    char username[20];
    char password[20];
};

void encryption(char password[]) // Define the encryption function
{
    int i;
    for(i=0; i<strlen(password); i++) // Encrypt each character in the password using ASCII values
    {
        password[i] = password[i] + 3;
    }
}

void decryption(char password[]) // Define the decryption function
{
    int i;
    for(i=0; i<strlen(password); i++) // Decrypt each character in the password using ASCII values
    {
        password[i] = password[i] - 3;
    }
}

int main()
{
    int choice, num_credentials=0, i;
    struct credentials all_credentials[100]; // Create an array of credentials, currently with capacity for 100 sets of credentials
    
    while(1) // Loop for the main menu
    {
        printf("\nWelcome to the Password Management System.\nPlease select an option:\n");
        printf("1. Add a new set of credentials\n");
        printf("2. View all existing sets of credentials\n");
        printf("3. Delete an existing set of credentials\n");
        printf("4. Change the master password\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        
        if(choice==1) // Option 1 - add new credentials
        {
            struct credentials new_credentials; // Create a new credentials struct to hold the new credentials
            getchar(); // Clear the input buffer
            
            printf("\nEnter the username:\n");
            fgets(new_credentials.username, 20, stdin); // Read in the new username
            
            printf("\nEnter the password:\n");
            fgets(new_credentials.password, 20, stdin); // Read in the new password
            
            encryption(new_credentials.password); // Encrypt the password using the encryption function
            
            all_credentials[num_credentials] = new_credentials; // Add the new credentials struct to the array of all credentials
            num_credentials++; // Increment the number of credentials counter
            
            printf("\nNew set of credentials added successfully!\n");
        }
        else if(choice==2) // Option 2 - view all credentials
        {
            if(num_credentials==0) // If there are no credentials in the array
            {
                printf("\nThere are currently no sets of credentials to display.\n");
            }
            else // If there are credentials in the array
            {
                printf("\nAll existing sets of credentials:\n");
                for(i=0; i<num_credentials; i++) // Loop through all the credentials in the array
                {
                    decryption(all_credentials[i].password); // Decrypt the password using the decryption function
                    
                    printf("\nUsername: %s", all_credentials[i].username); // Print out the username
                    printf("Password: %s", all_credentials[i].password); // Print out the password
                    
                    encryption(all_credentials[i].password); // Re-encrypt the password for security
                }
            }
        }
        else if(choice==3) // Option 3 - delete credentials
        {
            if(num_credentials==0) // If there are no credentials in the array
            {
                printf("\nThere are currently no sets of credentials to delete.\n");
            }
            else // If there are credentials in the array
            {
                int index_to_delete;
                printf("\nEnter the index of the set of credentials to delete:\n");
                scanf("%d", &index_to_delete); // Read in the index of the credentials to delete
                
                if(index_to_delete>=num_credentials || index_to_delete<0) // If the index is out of bounds
                {
                    printf("\nInvalid index. Please try again.\n");
                }
                else // If the index is within bounds
                {
                    for(i=index_to_delete; i<num_credentials-1; i++) // Shift all the credentials after the deleted one down by one index
                    {
                        all_credentials[i] = all_credentials[i+1];
                    }
                    num_credentials--; // Decrement the number of credentials counter
                    printf("\nSet of credentials deleted successfully.\n");
                }
            }
        }
        else if(choice==4) // Option 4 - change the master password
        {
            char current_password[20];
            printf("\nEnter the current master password:\n");
            scanf("%s", current_password); // Read in the current master password
            
            if(strcmp(current_password, password)==0) // If the current password matches the master password
            {
                char new_password[20];
                printf("\nEnter the new master password:\n");
                scanf("%s", new_password); // Read in the new master password
                
                strcpy(password, new_password); // Replace the current master password with the new one
                printf("\nMaster password changed successfully.\n");
            }
            else // If the current password does not match the master password
            {
                printf("\nIncorrect password. Cannot change master password.\n");
            }
        }
        else if(choice==5) // Option 5 - exit the program
        {
            printf("\nThank you for using the Password Management System.\n");
            break; // Exit the while loop
        }
        else // Invalid option
        {
            printf("\nInvalid option. Please try again.\n");
        }
    }
    
    return 0; // End the program
}