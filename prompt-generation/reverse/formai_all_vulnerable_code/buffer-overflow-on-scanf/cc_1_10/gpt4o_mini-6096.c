//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define FILE_NAME "passwords.txt"

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Credential;

void addCredential(const Credential *cred);
void viewCredentials();
void deleteCredential(const char *website);
void searchCredential(const char *website);
void printInstructions();

int main() {
    int choice;
    Credential cred;
    char website[MAX_LENGTH];

    printInstructions();

    while (1) {
        printf("\nChoose an option (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter website: ");
                scanf("%s", cred.website);
                printf("Enter username: ");
                scanf("%s", cred.username);
                printf("Enter password: ");
                scanf("%s", cred.password);
                addCredential(&cred);
                break;
            case 2:
                viewCredentials();
                break;
            case 3:
                printf("Enter website to delete: ");
                scanf("%s", website);
                deleteCredential(website);
                break;
            case 4:
                printf("Enter website to search: ");
                scanf("%s", website);
                searchCredential(website);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}

void addCredential(const Credential *cred) {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }
    fprintf(file, "%s;%s;%s\n", cred->website, cred->username, cred->password);
    fclose(file);
    printf("Credential added successfully!\n");
}

void viewCredentials() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("No credentials found");
        return;
    }
    Credential cred;
    printf("\nStored Credentials:\n");
    printf("%-30s %-30s %-30s\n", "Website", "Username", "Password");
    printf("%-30s %-30s %-30s\n", "-------", "--------", "-------");
    while (fscanf(file, "%[^;];%[^;];%[^;\n]\n", cred.website, cred.username, cred.password) != EOF) {
        printf("%-30s %-30s %-30s\n", cred.website, cred.username, cred.password);
    }
    fclose(file);
}

void deleteCredential(const char *website) {
    FILE *file = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (file == NULL || temp == NULL) {
        perror("Error opening files");
        return;
    }

    Credential cred;
    int found = 0;
    while (fscanf(file, "%[^;];%[^;];%[^;\n]\n", cred.website, cred.username, cred.password) != EOF) {
        if (strcmp(cred.website, website) != 0) {
            fprintf(temp, "%s;%s;%s\n", cred.website, cred.username, cred.password);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
    
    if (found) {
        printf("Credential for %s deleted successfully!\n", website);
    } else {
        printf("No credential found for %s.\n", website);
    }
}

void searchCredential(const char *website) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("No credentials found");
        return;
    }

    Credential cred;
    int found = 0;
    while (fscanf(file, "%[^;];%[^;];%[^;\n]\n", cred.website, cred.username, cred.password) != EOF) {
        if (strcmp(cred.website, website) == 0) {
            printf("Website: %s\nUsername: %s\nPassword: %s\n", cred.website, cred.username, cred.password);
            found = 1;
            break;
        }
    }

    fclose(file);
    
    if (!found) {
        printf("No credential found for %s.\n", website);
    }
}

void printInstructions() {
    printf("Password Manager\n");
    printf("1. Add Credential\n");
    printf("2. View Credentials\n");
    printf("3. Delete Credential\n");
    printf("4. Search Credential\n");
    printf("5. Exit\n");
}