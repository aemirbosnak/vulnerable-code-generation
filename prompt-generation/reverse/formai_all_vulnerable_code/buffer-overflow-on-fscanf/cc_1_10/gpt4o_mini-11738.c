//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define BUFFER_SIZE 256

typedef struct {
    char website[BUFFER_SIZE];
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];
} Credential;

Credential passwordManager[MAX_PASSWORDS];
int credentialCount = 0;

// Function to add a new credential
void addCredential() {
    if (credentialCount >= MAX_PASSWORDS) {
        printf("Password manager is full, cannot add more credentials.\n");
        return;
    }
    
    Credential newCredential;
    printf("Enter website: ");
    scanf("%s", newCredential.website);
    printf("Enter username: ");
    scanf("%s", newCredential.username);
    printf("Enter password: ");
    // For security reasons, we should not echo input in a real application
    scanf("%s", newCredential.password);
    
    passwordManager[credentialCount++] = newCredential;
    printf("Credential added successfully!\n");
}

// Function to display all credentials
void displayCredentials() {
    if (credentialCount == 0) {
        printf("No credentials stored.\n");
        return;
    }
    
    printf("\nStored Credentials:\n");
    for (int i = 0; i < credentialCount; i++) {
        printf("Website: %s, Username: %s, Password: %s\n",
               passwordManager[i].website,
               passwordManager[i].username,
               passwordManager[i].password);
    }
}

// Function to find and display credentials for a specific website
void findCredential() {
    char website[BUFFER_SIZE];
    printf("Enter website to find credentials: ");
    scanf("%s", website);
    
    for (int i = 0; i < credentialCount; i++) {
        if (strcmp(passwordManager[i].website, website) == 0) {
            printf("Website: %s, Username: %s, Password: %s\n",
                   passwordManager[i].website,
                   passwordManager[i].username,
                   passwordManager[i].password);
            return;
        }
    }
    printf("No credentials found for the website: %s\n", website);
}

// Function to delete a credential
void deleteCredential() {
    char website[BUFFER_SIZE];
    printf("Enter website of the credential to delete: ");
    scanf("%s", website);
    
    for (int i = 0; i < credentialCount; i++) {
        if (strcmp(passwordManager[i].website, website) == 0) {
            for (int j = i; j < credentialCount - 1; j++) {
                passwordManager[j] = passwordManager[j + 1];
            }
            credentialCount--;
            printf("Credential for %s deleted successfully.\n", website);
            return;
        }
    }
    printf("No credentials found for the website: %s\n", website);
}

// Function to save credentials to a file
void saveCredentials() {
    FILE *file = fopen("credentials.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for (int i = 0; i < credentialCount; i++) {
        fprintf(file, "%s %s %s\n", passwordManager[i].website, 
                                    passwordManager[i].username, 
                                    passwordManager[i].password);
    }
    fclose(file);
    printf("Credentials saved successfully!\n");
}

// Function to load credentials from a file
void loadCredentials() {
    FILE *file = fopen("credentials.txt", "r");
    if (file == NULL) {
        printf("No saved credentials found.\n");
        return;
    }
    
    while (fscanf(file, "%s %s %s", passwordManager[credentialCount].website,
                                        passwordManager[credentialCount].username,
                                        passwordManager[credentialCount].password) != EOF) {
        credentialCount++;
        if (credentialCount >= MAX_PASSWORDS) {
            break;
        }
    }
    fclose(file);
    printf("Credentials loaded successfully!\n");
}

// Main function
int main() {
    int choice;

    loadCredentials();

    do {
        printf("\nPassword Manager\n");
        printf("1. Add Credential\n");
        printf("2. Display Credentials\n");
        printf("3. Find Credential\n");
        printf("4. Delete Credential\n");
        printf("5. Save Credentials\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCredential();
                break;
            case 2:
                displayCredentials();
                break;
            case 3:
                findCredential();
                break;
            case 4:
                deleteCredential();
                break;
            case 5:
                saveCredentials();
                break;
            case 6:
                printf("Exiting the Password Manager. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}