//FormAI DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
// Romeo and Juliet Password Manager

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Declaration of global variables
int passwordLength = 0;

// Declaration of functions
void generatePassword();
void storePassword();
void getPassword();
void deletePassword();

int main()
{
    int choice = 0;
    
    // Introduction
    printf("\nRomeo and Juliet Password Manager\n");
    printf("----------------------------------\n");
    
    // Main menu
    while(choice != 5)
    {
        printf("\n1. Generate Password\n");
        printf("2. Store Password\n");
        printf("3. Get Password\n");
        printf("4. Delete Password\n");
        printf("5. Exit\n");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                generatePassword();
                break;
            case 2:
                storePassword();
                break;
            case 3:
                getPassword();
                break;
            case 4:
                deletePassword();
                break;
            case 5:
                printf("\nGoodbye my love!\n");
                break;
            default:
                printf("\nInvalid choice! Please choose again.\n");
                break;
        }
    }
    
    return 0;
}

// Function to generate password
void generatePassword()
{
    char password[16];
    
    // Romeo’s message and action
    printf("\nMy dear Juliet, let me create a password for thee!\n");
    
    // Calculation
    for(int i=0; i<16; i++)
    {
        int random = rand() % 74;
        while(random < 48 || (random > 57 && random < 65) || (random > 90 && random < 97) || random > 122)
        {
            random = rand() % 74;
        }
        password[i] = (char)random;
    }
    
    // Result and Juliet’s reaction
    printf("\nThe password is: %s\n", password);
    printf("\nOh Romeo, thou art clever indeed!\n");
    
    passwordLength = 16;
}

// Function to store password
void storePassword()
{
    if(passwordLength == 0)
    {
        // Juliet’s message and reaction
        printf("\nOh Romeo, I have no password to store!\n");
        printf("\nAlas, what shall we do?\n");
    }
    else
    {
        char password[16];
        
        // Romeo’s message
        printf("\nMy sweet Juliet, please enter the name of the service you want to store your password for: ");
        scanf("%s", password);
        
        // Password storage
        // This is just a simulation of saving password into a file
        FILE *fp;
        fp = fopen("passwords.txt", "a");
        fprintf(fp, "%s - %s\n", password, "password");
        fclose(fp);
        
        // Juliet’s reaction
        printf("\nThank you my love, now I can never forget my passwords again!\n");
    }
}

// Function to get password
void getPassword()
{
    if(passwordLength == 0)
    {
        // Juliet’s message and reaction
        printf("\nOh Romeo, I have no password to retrieve!\n");
        printf("\nWhat shall we do now?\n");
    }
    else
    {
        char password[16];
        char line[100];
        int found = 0;
        char *token;
        
        // Romeo’s message
        printf("\nPlease enter the name of the service you want to retrieve the password for: ");
        scanf("%s", password);
        
        // Password retrieval
        // This is just a simulation of getting passwords from a file
        FILE *fp;
        fp = fopen("passwords.txt", "r");
        
        while(fgets(line, 100, fp))
        {
            token = strtok(line, " -");
            if(strcmp(token, password) == 0)
            {
                token = strtok(NULL, " -");
                printf("\nThe password for %s is: %s\n", password, token);
                found = 1;
                break;
            }
        }
        
        if(found == 0)
        {
            // Juliet’s message and reaction
            printf("\nI am sorry my love, but I cannot find the password for that service!\n");
            printf("\nWhat shall we do now?\n");
        }
        
        fclose(fp);
    }
}

// Function to delete password
void deletePassword()
{
    if(passwordLength == 0)
    {
        // Juliet’s message and reaction
        printf("\nOh Romeo, I have no password to delete!\n");
        printf("\nWhat shall we do now?\n");
    }
    else
    {
        char password[16];
        char line[100];
        int found = 0;
        char *token;
        
        // Romeo’s message
        printf("\nPlease enter the name of the service you want to delete the password for: ");
        scanf("%s", password);
        
        // Password deletion
        // This is just a simulation of deleting passwords from a file
        FILE *fp, *fp_temp;
        fp = fopen("passwords.txt", "r");
        fp_temp = fopen("temp.txt", "w");
        
        while(fgets(line, 100, fp))
        {
            token = strtok(line, " -");
            if(strcmp(token, password) == 0)
            {
                found = 1;
                continue;
            }
            else
            {
                fputs(line, fp_temp);
            }
        }
        
        fclose(fp);
        fclose(fp_temp);
        
        remove("passwords.txt");
        rename("temp.txt", "passwords.txt");
        
        if(found == 0)
        {
            // Juliet’s message and reaction
            printf("\nI am sorry my love, but I cannot find the password for that service!\n");
            printf("\nWhat shall we do now?\n");
        }
        else
        {
            // Juliet’s reaction
            printf("\nThank you Romeo, you always take care of me!\n");
        }
    }
}