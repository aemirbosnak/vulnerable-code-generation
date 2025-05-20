//FormAI DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct password{
    char website[50];
    char username[50];
    char password[50];
}Password;

// Function to encrypt the password
char *encrypt(char *password){
    for(int i = 0; i < strlen(password); i++){
        password[i] = password[i] + 3; // Adding 3 to ASCII value
    }
    return password;
}

// Function to decrypt the password
char *decrypt(char *password){
    for(int i = 0; i < strlen(password); i++){
        password[i] = password[i] - 3; // Subtracting 3 from ASCII value
    }
    return password;
}

// Function to create a new password entry
void createPassword(){
    Password newPassword;
    printf("Enter website name: ");
    scanf("%s", newPassword.website);
    printf("Enter username: ");
    scanf("%s", newPassword.username);
    printf("Enter password: ");
    scanf("%s", newPassword.password);
    char *encryptedPassword = encrypt(newPassword.password);
    FILE *filePointer;
    filePointer = fopen("passwords.txt", "a");
    if(filePointer == NULL){
        printf("Error: Unable to open file");
    }else{
        fprintf(filePointer, "%s %s %s\n", newPassword.website, newPassword.username, encryptedPassword);
        printf("Password created successfully\n");
    }
    fclose(filePointer);
}

// Function to display all password entries
void displayPasswords(){
    FILE *filePointer;
    char website[50], username[50], password[50];
    filePointer = fopen("passwords.txt", "r");
    if(filePointer == NULL){
        printf("Error: Unable to open file");
    }else{
        printf("\nAll Passwords\n");
        printf("| Website | Username | Password |\n");
        while(fscanf(filePointer, "%s %s %s", website, username, password) != EOF){
            char *decryptedPassword = decrypt(password); // Decrypting the password
            printf("| %s | %s | %s |\n", website, username, decryptedPassword);
        }
    }
    fclose(filePointer);
}

// Function to search for a specific password entry
void searchPassword(){
    char website[50];
    printf("Enter the website: ");
    scanf("%s", website);
    FILE *filePointer;
    char currentWebsite[50], username[50], password[50];
    filePointer = fopen("passwords.txt", "r");
    if(filePointer == NULL){
        printf("Error: Unable to open file");
    }else{
        while(fscanf(filePointer, "%s %s %s", currentWebsite, username, password) != EOF){
            if(strcmp(currentWebsite, website) == 0){
                char *decryptedPassword = decrypt(password); // Decrypting the password
                printf("Website: %s\nUsername: %s\nPassword: %s\n", currentWebsite, username, decryptedPassword);
                fclose(filePointer);
                return; // Exiting the function
            }
        }
        printf("No password found for %s\n", website);
    }
    fclose(filePointer);
}

// Function to delete a specific password entry
void deletePassword(){
    char website[50];
    printf("Enter the website: ");
    scanf("%s", website);
    FILE *filePointer, *tempFilePointer;
    char currentWebsite[50], username[50], password[50];
    filePointer = fopen("passwords.txt", "r");
    tempFilePointer = fopen("temp.txt", "w"); // Creating a temporary file for copying
    if(filePointer == NULL || tempFilePointer == NULL){
        printf("Error: Unable to open file");
    }else{
        int found = 0; // Flag to keep track of whether the password is found or not
        while(fscanf(filePointer, "%s %s %s", currentWebsite, username, password) != EOF){
            if(strcmp(currentWebsite, website) != 0){ // Copying all passwords except the one to be deleted
                fprintf(tempFilePointer, "%s %s %s\n", currentWebsite, username, password);
            }else{
                found = 1;
            }
        }
        fclose(filePointer);
        fclose(tempFilePointer);
        if(found == 0){
            printf("No password found for %s\n", website);
        }else{
            remove("passwords.txt"); // Deleting the original file
            rename("temp.txt", "passwords.txt"); // Renaming the temporary file to the original file
            printf("Password deleted successfully\n");
        }
    }
}

int main(){
    int choice;
    while(1){ // Infinite loop to continuously show the menu
        printf("\nMENU\n");
        printf("1. Create New Password\n");
        printf("2. Display All Passwords\n");
        printf("3. Search Password\n");
        printf("4. Delete Password\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                createPassword();
                break;
            case 2:
                displayPasswords();
                break;
            case 3:
                searchPassword();
                break;
            case 4:
                deletePassword();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}