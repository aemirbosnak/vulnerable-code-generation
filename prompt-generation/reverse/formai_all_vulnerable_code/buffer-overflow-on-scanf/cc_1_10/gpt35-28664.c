//FormAI DATASET v1.0 Category: Password management ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to hold username and password
struct Credentials {
    char un[50];
    char pw[50];
};

// Function to add new credentials
void addCredential(struct Credentials *cred, int *n) {
    printf("\nEnter the username: ");
    scanf("%s", cred[*n].un);
    printf("Enter the password: ");
    scanf("%s", cred[*n].pw);
    (*n)++;
    printf("\nCredential added successfully!\n");
}

// Function to delete existing credential
void deleteCredential(struct Credentials *cred, int *n) {
    printf("\nEnter the username to delete: ");
    char un[50];
    scanf("%s", un);
    for(int i=0; i<*n; i++) {
        if(strcmp(cred[i].un, un) == 0) {
            for(int j=i; j<*n-1; j++) {
                cred[j] = cred[j+1];
            }
            (*n)--;
            printf("\nCredential has been deleted!\n");
            return;
        }
    }
    printf("\nUnable to delete the credential. Username not found!\n");
}

// Function to update existing credential
void updateCredential(struct Credentials *cred, int n) {
    printf("\nEnter the username to update: ");
    char un[50];
    scanf("%s", un);
    for(int i=0; i<n; i++) {
        if(strcmp(cred[i].un, un) == 0) {
            printf("Enter the new password: ");
            scanf("%s", cred[i].pw);
            printf("\nCredential has been updated!\n");
            return;
        }
    }
    printf("\nUnable to update the credential. Username not found!\n");
}

// Function to display all credentials
void displayCredentials(struct Credentials *cred, int n) {
    printf("\nTotal credentials: %d\n", n);
    for(int i=0; i<n; i++) {
        printf("Username: %s\n", cred[i].un);
        printf("Password: %s\n\n", cred[i].pw);
    }
}

int main() {
    int choice, n=0;
    struct Credentials cred[100];
    do{
        printf("\n1. Add new credential");
        printf("\n2. Delete existing credential");
        printf("\n3. Update existing credential");
        printf("\n4. Display all credentials");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addCredential(cred, &n); break;
            case 2: deleteCredential(cred, &n); break;
            case 3: updateCredential(cred, n); break;
            case 4: displayCredentials(cred, n); break;
            case 5: exit(0); break;
            default: printf("\nInvalid choice. Try again!\n"); break;
        }
    }while(1);

    return 0;
}