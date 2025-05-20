//FormAI DATASET v1.0 Category: Password management ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct Password {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwordList[MAX_PASSWORDS];

void printPasswords() {
    printf("\nWEBSITE\tUSERNAME\tPASSWORD\n");
    for(int i=0;i<MAX_PASSWORDS;i++) {
        if(strcmp(passwordList[i].website,"")!=0)
            printf("%s\t%s\t%s\n",passwordList[i].website,passwordList[i].username,passwordList[i].password);
    }
}

int isInputValid(char* input, int minLength, int maxLength) {
    int inputLength = strlen(input);
    if(inputLength < minLength || inputLength > maxLength)
        return 0;
    for(int i=0;i<inputLength;i++) {
        if(!isalnum(input[i]))
            return 0;
    }
    return 1;
}

int getPasswordIndex(char* website) {
    for(int i=0;i<MAX_PASSWORDS;i++) {
        if(strcmp(passwordList[i].website,website)==0)
            return i;
    }
    return -1;
}

void addPassword() {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("\nEnter website: ");
    scanf("%s",website);
    if(getPasswordIndex(website) != -1) {
        printf("\nA password already exists for %s\n",website);
        return;
    }
    printf("\nEnter username: ");
    scanf("%s",username);
    printf("\nEnter password: ");
    scanf("%s",password);
    Password new_password;
    strcpy(new_password.website, website);
    strcpy(new_password.username, username);
    strcpy(new_password.password, password);
    for(int i=0;i<MAX_PASSWORDS;i++) {
        if(strcmp(passwordList[i].website,"")==0) {
            passwordList[i] = new_password;
            printf("\nPassword added successfully\n");
            return;
        }
    }
    printf("\nPassword limit reached, cannot add more passwords\n");
}

void deletePassword() {
    char website[MAX_PASSWORD_LENGTH];
    printf("\nEnter website: ");
    scanf("%s",website);
    int passwordIndex = getPasswordIndex(website);
    if(passwordIndex == -1) {
        printf("\nNo password found for %s\n",website);
        return;
    }
    passwordList[passwordIndex].website[0] = '\0';
    printf("\nPassword deleted successfully\n");
}

void updatePassword() {
    char website[MAX_PASSWORD_LENGTH];
    printf("\nEnter website: ");
    scanf("%s",website);
    int passwordIndex = getPasswordIndex(website);
    if(passwordIndex == -1) {
        printf("\nNo password found for %s\n",website);
        return;
    }
    printf("\nEnter new username: ");
    scanf("%s",passwordList[passwordIndex].username);
    printf("\nEnter new password: ");
    scanf("%s",passwordList[passwordIndex].password);
    printf("\nPassword updated successfully\n");
}

int main() {
    int choice;
    while(1) {
        printf("\n\nChoose an option:\n1. View all passwords\n2. Add a password\n3. Delete a password\n4. Update a password\n5. Exit\n\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printPasswords();
                break;
            case 2:
                addPassword();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                updatePassword();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice\n");
                break;
        }
    }
    return 0;
}