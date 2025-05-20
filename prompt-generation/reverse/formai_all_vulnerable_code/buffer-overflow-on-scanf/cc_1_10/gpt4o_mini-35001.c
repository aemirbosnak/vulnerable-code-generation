//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_LENGTH 256
#define DATA_FILE "passwords.txt"

typedef struct {
    char account[MAX_LENGTH];
    char password[MAX_LENGTH];
} Credential;

void initializeCredentials(Credential *creds, int *count) {
    FILE *file = fopen(DATA_FILE, "r");
    if (file) {
        while (fscanf(file, "%s %s", creds[*count].account, creds[*count].password) != EOF) {
            (*count)++;
        }
        fclose(file);
    }
}

void saveCredentials(Credential *creds, int count) {
    FILE *file = fopen(DATA_FILE, "w");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s\n", creds[i].account, creds[i].password);
    }
    
    fclose(file);
}

void addCredential(Credential *creds, int *count) {
    if (*count >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached!\n");
        return;
    }
    
    printf("Enter account name: ");
    scanf("%s", creds[*count].account);
    printf("Enter password: ");
    scanf("%s", creds[*count].password);
    (*count)++;
    saveCredentials(creds, *count);
    printf("Credential added successfully.\n");
}

void viewCredentials(Credential *creds, int count) {
    if (count == 0) {
        printf("No credentials stored.\n");
        return;
    }
    
    printf("Stored Credentials:\n");
    for (int i = 0; i < count; i++) {
        printf("Account: %s, Password: %s\n", creds[i].account, creds[i].password);
    }
}

void deleteCredential(Credential *creds, int *count) {
    if (*count == 0) {
        printf("No credentials to delete.\n");
        return;
    }

    char account[MAX_LENGTH];
    printf("Enter account name to delete: ");
    scanf("%s", account);
    
    int i;
    for (i = 0; i < *count; i++) {
        if (strcmp(creds[i].account, account) == 0) {
            break;
        }
    }

    if (i < *count) {
        for (int j = i; j < *count - 1; j++) {
            creds[j] = creds[j + 1];
        }
        (*count)--;
        saveCredentials(creds, *count);
        printf("Credential deleted successfully.\n");
    } else {
        printf("No account found with the name: %s\n", account);
    }
}

void menu(Credential *creds, int *count) {
    int choice;

    do {
        printf("\nPassword Manager Menu:\n");
        printf("1. Add Credential\n");
        printf("2. View Credentials\n");
        printf("3. Delete Credential\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addCredential(creds, count);
                break;
            case 2:
                viewCredentials(creds, *count);
                break;
            case 3:
                deleteCredential(creds, count);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    Credential credentials[MAX_ACCOUNTS];
    int count = 0;

    initializeCredentials(credentials, &count);
    menu(credentials, &count);

    return 0;
}