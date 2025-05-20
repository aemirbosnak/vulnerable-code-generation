//FormAI DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A struct representing a password */
struct Password {
    int id;
    char website[100];
    char username[100];
    char password[100];
};

/* An array to hold all the passwords */
struct Password passwords[100];

/* The number of passwords currently stored */
int numPasswords = 0;

/* Function to add a password to the array */
void addPassword(char* website, char* username, char* password) {
    struct Password newPass;
    newPass.id = numPasswords;
    strcpy(newPass.website, website);
    strcpy(newPass.username, username);
    strcpy(newPass.password, password);
    passwords[numPasswords++] = newPass;
}

/* Function to print out a password */
void printPassword(struct Password pass) {
    printf("ID: %d\n", pass.id);
    printf("Website: %s\n", pass.website);
    printf("Username: %s\n", pass.username);
    printf("Password: %s\n", pass.password);
}

/* Function to find a password given its ID */
struct Password findPassword(int id) {
    int i;
    for(i = 0; i < numPasswords; i++) {
        if(passwords[i].id == id) {
            return passwords[i];
        }
    }
    struct Password blankPass;
    blankPass.id = -1;
    return blankPass;
}

/* Function to delete a password given its ID */
void deletePassword(int id) {
    int i;
    for(i = 0; i < numPasswords; i++) {
        if(passwords[i].id == id) {
            break;
        }
    }
    for(int j = i; j < numPasswords-1; j++) {
        passwords[j] = passwords[j+1];
        passwords[j].id--;
    }
    numPasswords--;
}

/* Function to update a password given its ID */
void updatePassword(int id, char* website, char* username, char* password) {
    struct Password updatePass = findPassword(id);
    if(updatePass.id != -1) {
        strcpy(updatePass.website, website);
        strcpy(updatePass.username, username);
        strcpy(updatePass.password, password);
        passwords[id] = updatePass;
    }
}

int main() {
    printf("Welcome to the Password Manager!\n");
    int choice;
    do {
        printf("\nPlease select an option:\n");
        printf("1. Add a password\n");
        printf("2. View a password\n");
        printf("3. Delete a password\n");
        printf("4. Update a password\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                char website[100];
                char username[100];
                char password[100];
                printf("Website: ");
                scanf("%s", website);
                printf("Username: ");
                scanf("%s", username);
                printf("Password: ");
                scanf("%s", password);
                addPassword(website, username, password);
                printf("Password added!\n");
                break;
            }
            case 2: {
                int id;
                printf("Which password would you like to view? (Enter ID): ");
                scanf("%d", &id);
                struct Password viewPass = findPassword(id);
                if(viewPass.id != -1) {
                    printPassword(viewPass);
                } else {
                    printf("Password not found.\n");
                }
                break;
            }
            case 3: {
                int id;
                printf("Which password would you like to delete? (Enter ID): ");
                scanf("%d", &id);
                struct Password deletePass = findPassword(id);
                if(deletePass.id != -1) {
                    deletePassword(id);
                    printf("Password deleted!\n");
                } else {
                    printf("Password not found.\n");
                }
                break;
            }
            case 4: {
                int id;
                char website[100];
                char username[100];
                char password[100];
                printf("Which password would you like to update? (Enter ID): ");
                scanf("%d", &id);
                struct Password updatePass = findPassword(id);
                if(updatePass.id != -1) {
                    printf("Website: ");
                    scanf("%s", website);
                    printf("Username: ");
                    scanf("%s", username);
                    printf("Password: ");
                    scanf("%s", password);
                    updatePassword(id, website, username, password);
                    printf("Password updated!\n");
                } else {
                    printf("Password not found.\n");
                }
                break;
            }
            case 5: {
                printf("Exiting program.\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
    } while(choice != 5);

    return 0;
}