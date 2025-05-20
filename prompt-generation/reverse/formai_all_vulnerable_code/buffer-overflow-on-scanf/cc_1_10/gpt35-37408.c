//FormAI DATASET v1.0 Category: Password management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PASSWORDS 10

struct Password {
    char website[30];
    char username[30];
    char password[30];
};

void encrypt(char s[]) {
    for(int i=0; i<strlen(s); i++) {
        s[i] = s[i] + 2;
    }
}

void decrypt(char s[]) {
    for(int i=0; i<strlen(s); i++) {
        s[i] = s[i] - 2;
    }
}

struct Password passwords[MAX_PASSWORDS];
int passwordCount = 0;

void addPassword() {
    if(passwordCount >= MAX_PASSWORDS) {
        printf("Maximum password limit reached!\n");
        return;
    }
    
    printf("Enter website name: ");
    scanf("%s", passwords[passwordCount].website);
    printf("Enter username: ");
    scanf("%s", passwords[passwordCount].username);
    printf("Enter password: ");
    scanf("%s", passwords[passwordCount].password);
    encrypt(passwords[passwordCount].password);
    
    printf("Password added successfully!\n\n");
    passwordCount++;
}

void viewPasswords() {
    if(passwordCount == 0) {
        printf("No passwords available!\n\n");
        return;
    }
    
    printf("Website\t\tUsername\t\tPassword\n");
    printf("--------------------------------------------------------------\n");
    for(int i=0; i<passwordCount; i++) {
        printf("%s\t\t%s\t\t", passwords[i].website, passwords[i].username);
        decrypt(passwords[i].password);
        printf("%s\n", passwords[i].password);
        encrypt(passwords[i].password);
    }
    printf("\n");
}

void searchPassword() {
    if(passwordCount == 0) {
        printf("No passwords available!\n\n");
        return;
    }
    
    char keyword[30];
    printf("Enter website name or username: ");
    scanf("%s", keyword);
    
    for(int i=0; i<passwordCount; i++) {
        if(strcmp(passwords[i].website, keyword) == 0 || strcmp(passwords[i].username, keyword) == 0) {
            printf("Website: %s\n", passwords[i].website);
            printf("Username: %s\n", passwords[i].username);
            decrypt(passwords[i].password);
            printf("Password: %s\n\n", passwords[i].password);
            encrypt(passwords[i].password);
            return;
        }
    }
    
    printf("No passwords found matching the search keyword!\n\n");
}

int main() {
    int choice;
    
    while(1) {
        printf("Password Manager\n");
        printf("--------------------------------------------------------------\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Search password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                searchPassword();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please enter a valid choice.\n\n");
        }
    }
    
    return 0;
}