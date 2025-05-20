//FormAI DATASET v1.0 Category: Password management ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to validate password
int validatePassword(char *password) {
    
    int length = strlen(password);
    
    if(length < 8) {
        printf("\n\nPassword must contain atleast 8 characters.\n");
        return 0;
    }
    
    int i, upper = 0, lower = 0, special = 0, number = 0;
    
    for(i = 0; i < length; i++) {
        
        // Check for uppercase letters (A-Z)
        if(password[i] >= 'A' && password[i] <= 'Z') {
            upper = 1;
        }
        
        // Check for lowercase letters (a-z)
        else if(password[i] >= 'a' && password[i] <= 'z') {
            lower = 1;
        }
        
        // Check for special characters
        else if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
            special = 1;
        }
        
        // Check for numbers (0-9)
        else if(password[i] >= '0' && password[i] <= '9') {
            number = 1;
        }
    }
    
    // Check the criteria for a strong password
    if(upper == 1 && lower == 1 && special == 1 && number == 1) {
        return 1;
    }
    
    else {
        printf("\n\nPassword must contain at least one uppercase letter, one lowercase letter, one special character (!, @, #, $, %), and one number.\n");
        return 0;
    }
}


int main() {
    
    printf("\n\nWelcome to Password Management Program\n\n");
    
    // File pointer for password file
    FILE *fp;
    
    // Password file path
    char *filePath = "password.txt";
    
    // Password for this program
    char *password = "Password123#";
    
    // Open the file for reading
    fp = fopen(filePath, "r");
    
    // Check whether file exists or not
    if(fp == NULL) {
        printf("Passwords file does not exist. Creating a new file.\n");
        
        // Create a new file for storing password
        fp = fopen(filePath, "w");
        
        // Check if file creation failed
        if(fp == NULL) {
            printf("Error creating passwords file. Terminating program.\n");
            return 0;
        }
        
        // Write the default password to file
        fprintf(fp, "%s\n", password);
        printf("Password successfully stored.\n");
    }
    
    else {
        printf("Decrypting passwords file.\n");
        
        char storedPassword[50];
        fscanf(fp, "%s", storedPassword);
        
        // Compare the stored password to the actual password
        if(strcmp(storedPassword, password) == 0) {
            printf("Authentication complete.\n");
        }
        
        else {
            printf("Authentication failed. Terminating program.\n");
            fclose(fp);
            return 0;
        }
        
        fclose(fp);
        
        // File operation menu
        while(1) {
            
            // Display menu options
            printf("\n\nPassword Management Menu\n");
            printf("========================================================\n");
            printf("1. View Password\n");
            printf("2. Update Password\n");
            printf("3. Exit\n");
            printf("========================================================\n");
            
            // User input for menu selection
            char choice[5];
            printf("\nEnter your choice: ");
            fgets(choice, 5, stdin);
            
            // Remove newline character from choice
            strtok(choice, "\n");
            
            // Convert choice to integer
            int menuChoice = atoi(choice);
            
            // View password operation
            if(menuChoice == 1) {
                printf("The current password is: %s\n", password);
            }
            
            // Update password operation
            else if(menuChoice == 2) {
                
                printf("\nEnter the new Password: ");
                char newPassword[50];
                fgets(newPassword, 50, stdin);
                
                // Remove newline character from password
                strtok(newPassword, "\n");
                
                // Check for valid password
                int validationResult = validatePassword(newPassword);
                
                if(validationResult == 1) {
                    fp = fopen(filePath, "w");
                    fprintf(fp, "%s\n", newPassword);
                    printf("Password successfully updated.\n");
                    password = newPassword;
                }
                
                fclose(fp);
            }
            
            // Exit program
            else if(menuChoice == 3) {
                printf("Terminating program...\n");
                break;
            }
            
            // Invalid menu input
            else {
                printf("Invalid choice. Please try again.\n");
            }
        }
    }
    
    return 0;
}