//FormAI DATASET v1.0 Category: Password management ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

// Struct to store username and password
struct Credential {
    char username[MAX_SIZE];
    char password[MAX_SIZE];
};

// Function prototypes
void encrypt(char* str);
void decrypt(char* str);
void writeToFile(struct Credential* credential, int count);
void readFromFile(struct Credential** credentials, int* count);
void addCredential(struct Credential** credentials, int* count);
void printCredentials(struct Credential* credentials, int count);
void updateCredential(struct Credential** credentials, int count);
void deleteCredential(struct Credential** credentials, int* count);
void searchCredential(struct Credential* credentials, int count);

int main() {
    struct Credential* credentials;
    int count = 0;
    int choice = 0;

    readFromFile(&credentials, &count);

    while(1) {
        printf("Password Manager\n");
        printf("1. Add Credential\n");
        printf("2. Show All Credentials\n");
        printf("3. Update Credential\n");
        printf("4. Delete Credential\n");
        printf("5. Search Credential\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addCredential(&credentials, &count);
                break;

            case 2:
                printCredentials(credentials, count);
                break;

            case 3:
                updateCredential(&credentials, count);
                break;

            case 4:
                deleteCredential(&credentials, &count);
                break;

            case 5:
                searchCredential(credentials, count);
                break;

            case 6:
                writeToFile(credentials, count);
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to encrypt a string
void encrypt(char* str) {
    for(int i = 0; i < strlen(str); i++) {
        str[i] += 3;    // Shift each character by 3 places
    }
}

// Function to decrypt a string
void decrypt(char* str) {
    for(int i = 0; i < strlen(str); i++) {
        str[i] -= 3;    // Shift each character back by 3 places
    }
}

// Function to write the credentials to a file
void writeToFile(struct Credential* credentials, int count) {
    FILE* file = fopen("credentials.txt", "w");

    for(int i = 0; i < count; i++) {
        fprintf(file, "%s,%s\n", credentials[i].username, credentials[i].password);
    }

    fclose(file);
}

// Function to read the credentials from a file
void readFromFile(struct Credential** credentials, int* count) {
    FILE* file = fopen("credentials.txt", "r");

    if(file == NULL) {
        *credentials = (struct Credential*) malloc(0);
        return;
    }

    struct Credential* tempCredentials = *credentials;
    int tempCount = *count;
    char line[MAX_SIZE];
    char* username;
    char* password;

    while(fgets(line, MAX_SIZE, file) != NULL) {
        username = strtok(line, ",");
        password = strtok(NULL, "\n");

        tempCount++;
        tempCredentials = (struct Credential*) realloc(tempCredentials, tempCount * sizeof(struct Credential));
        strcpy(tempCredentials[tempCount-1].username, username);
        decrypt(password);  // Decrypt the password before storing
        strcpy(tempCredentials[tempCount-1].password, password);
    }

    *credentials = tempCredentials;
    *count = tempCount;

    fclose(file);
}

// Function to add a new credential
void addCredential(struct Credential** credentials, int* count) {
    printf("Enter the details below:\n");

    *count = *count + 1;
    *credentials = (struct Credential*) realloc(*credentials, *count * sizeof(struct Credential));

    printf("Username: ");
    scanf("%s", (*credentials)[*count-1].username);

    printf("Password: ");
    scanf("%s", (*credentials)[*count-1].password);
    encrypt((*credentials)[*count-1].password);   // Encrypt the password before storing

    printf("Credential added successfully!\n");
}

// Function to print all credentials
void printCredentials(struct Credential* credentials, int count) {
    printf("%-20s %-20s\n", "Username", "Password");
    for(int i = 0; i < count; i++) {
        printf("%-20s %-20s\n", credentials[i].username, credentials[i].password);
    }
}

// Function to update a credential
void updateCredential(struct Credential** credentials, int count) {
    char username[MAX_SIZE];
    char password[MAX_SIZE];

    printf("Enter the username of the credential you want to update: ");
    scanf("%s", username);

    for(int i = 0; i < count; i++) {
        if(strcmp((*credentials)[i].username, username) == 0) {
            printf("Enter the new password: ");
            scanf("%s", password);
            encrypt(password);  // Encrypt the new password before storing
            strcpy((*credentials)[i].password, password);
            printf("Credential updated successfully!\n");
            return;
        }
    }

    printf("Credential not found!\n");
}

// Function to delete a credential
void deleteCredential(struct Credential** credentials, int* count) {
    char username[MAX_SIZE];

    printf("Enter the username of the credential you want to delete: ");
    scanf("%s", username);

    struct Credential* tempCredentials = *credentials;
    int tempCount = *count;

    for(int i = 0; i < tempCount; i++) {
        if(strcmp(tempCredentials[i].username, username) == 0) {
            for(int j = i; j < tempCount - 1; j++) {
                tempCredentials[j] = tempCredentials[j+1];
            }
            tempCount--;
            tempCredentials = (struct Credential*) realloc(tempCredentials, tempCount * sizeof(struct Credential));
            printf("Credential deleted successfully!\n");
            *credentials = tempCredentials;
            *count = tempCount;
            return;
        }
    }

    printf("Credential not found!\n");
}

// Function to search for a credential
void searchCredential(struct Credential* credentials, int count) {
    char username[MAX_SIZE];

    printf("Enter the username of the credential you want to search: ");
    scanf("%s", username);

    for(int i = 0; i < count; i++) {
        if(strcmp(credentials[i].username, username) == 0) {
            printf("%-20s %-20s\n", "Username", "Password");
            printf("%-20s %-20s\n", credentials[i].username, credentials[i].password);
            return;
        }
    }

    printf("Credential not found!\n");
}