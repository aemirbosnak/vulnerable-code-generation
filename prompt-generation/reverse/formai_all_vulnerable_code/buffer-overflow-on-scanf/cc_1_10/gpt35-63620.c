//FormAI DATASET v1.0 Category: Password management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LEN 20
#define MAX_USERNAME_LEN 20

// The data structure to store the username and password
typedef struct UserCredential {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    struct UserCredential *next;
} UserCredential;

// The data structure to store the list of user credentials
typedef struct CredentialList {
    UserCredential *head;
    UserCredential *tail;
    int size;
} CredentialList;

// Function prototypes
void addCredential(CredentialList *credentialList);
void removeCredential(CredentialList *credentialList);
void printCredentialList(CredentialList *credentialList);
UserCredential *findCredential(CredentialList *credentialList, char *username);
void changePassword(UserCredential *credential);

int main() {
    CredentialList credentialList = {NULL, NULL, 0};

    printf("*** Password Manager ***\n\n");

    while (1) {
        int choice;

        printf("Please choose an option:\n");
        printf("1. Add new credential\n");
        printf("2. Remove a credential\n");
        printf("3. Change a password\n");
        printf("4. Print all credentials\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCredential(&credentialList);
                break;
            case 2:
                removeCredential(&credentialList);
                break;
            case 3:
                {
                    char username[MAX_USERNAME_LEN];
                    printf("Please enter your username: ");
                    scanf("%s", username);

                    UserCredential *credential = findCredential(&credentialList, username);
                    
                    if (credential == NULL) {
                        printf("Credential not found.\n");
                    } else {
                        changePassword(credential);
                    }
                }
                break;
            case 4:
                printCredentialList(&credentialList);
                break;
            case 5:
                printf("Thank you for using Password Manager!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void addCredential(CredentialList *credentialList) {
    UserCredential *credential = malloc(sizeof(UserCredential));
    printf("Please enter your username: ");
    scanf("%s", credential->username);
    printf("Please enter your password: ");
    scanf("%s", credential->password);

    credential->next = NULL;

    if (credentialList->head == NULL) {
        credentialList->head = credential;
        credentialList->tail = credential;
    } else {
        credentialList->tail->next = credential;
        credentialList->tail = credential;
    }
    credentialList->size++;

    printf("Credential added successfully.\n");
}

void removeCredential(CredentialList *credentialList) {
    char username[MAX_USERNAME_LEN];
    printf("Please enter your username: ");
    scanf("%s", username);

    UserCredential *curr = credentialList->head;
    UserCredential *prev = NULL;

    while (curr != NULL) {
        if (strcmp(curr->username, username) == 0) {
            if (prev == NULL) {
                credentialList->head = curr->next;
            } else {
                prev->next = curr->next;
            }
            if (curr == credentialList->tail) {
                credentialList->tail = prev;
            }

            free(curr);
            credentialList->size--;
            printf("Credential removed successfully.\n");
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    printf("Credential not found.\n");
}

void printCredentialList(CredentialList *credentialList) {
    UserCredential *curr = credentialList->head;

    if (curr == NULL) {
        printf("No credentials found.\n");
        return;
    }

    while (curr != NULL) {
        printf("Username: %s\n", curr->username);
        printf("Password: %s\n", curr->password);
        printf("\n");

        curr = curr->next;
    }
}

UserCredential *findCredential(CredentialList *credentialList, char *username) {
    UserCredential *curr = credentialList->head;

    while (curr != NULL) {
        if (strcmp(curr->username, username) == 0) {
            return curr;
        }

        curr = curr->next;
    }

    return NULL;
}

void changePassword(UserCredential *credential) {
    char oldPassword[MAX_PASSWORD_LEN];
    printf("Please enter your old password: ");
    scanf("%s", oldPassword);

    if (strcmp(credential->password, oldPassword) == 0) {
        char newPassword[MAX_PASSWORD_LEN];
        printf("Please enter your new password: ");
        scanf("%s", newPassword);

        strcpy(credential->password, newPassword);
        printf("Password changed successfully.\n");
    } else {
        printf("Incorrect password.\n");
    }
}