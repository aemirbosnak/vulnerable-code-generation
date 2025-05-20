//FormAI DATASET v1.0 Category: Password management ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

// Structure for Password Data
struct PasswordData{
    char accountName[MAX_SIZE];
    char username[MAX_SIZE];
    char password[MAX_SIZE];
};

// Function to create a Password data
void createPwdData(struct PasswordData *pwdData){
    printf("Enter Account Name: ");
    scanf("%s", pwdData->accountName);

    printf("Enter Username: ");
    scanf("%s", pwdData->username);

    printf("Enter Password: ");
    scanf("%s", pwdData->password);
}

// Function to display a Password data
void displayPwdData(struct PasswordData pwdData){
    printf("---------------------------------------\n");
    printf("Account: %s\n", pwdData.accountName);
    printf("Username: %s\n", pwdData.username);
    printf("Password: %s\n", pwdData.password);
    printf("---------------------------------------\n");
}

// Main function
int main(){

    struct PasswordData *passwords;
    int i, numPasswords;

    printf("Enter the number of Passwords to Store: ");
    scanf("%d", &numPasswords);

    // Allocating Memory for Password Data
    passwords = (struct PasswordData *)malloc(numPasswords * sizeof(struct PasswordData));

    // Taking Input for Password Data
    for(i = 0; i < numPasswords; i++){
        printf("\nEnter the Details for Password No. %d\n", (i+1));
        createPwdData(&passwords[i]);
    }

    // Displaying Password Data
    printf("\nHere are the Passwords Stored:\n");
    for(i = 0; i < numPasswords; i++){
        displayPwdData(passwords[i]);
    }

    // Freeing Memory Allocated for Password Data
    free(passwords);

    return 0;
}