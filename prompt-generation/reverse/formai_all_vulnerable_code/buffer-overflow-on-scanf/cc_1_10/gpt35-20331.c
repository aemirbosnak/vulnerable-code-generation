//FormAI DATASET v1.0 Category: Password management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50
#define MAX_ATTEMPTS 3

struct Password {
    char account[MAX_LEN];
    char username[MAX_LEN];
    char password[MAX_LEN];
};

void display_menu();
void add_password();
void find_password();
void delete_password();
void list_passwords();
void encrypt_password(char*);
void decrypt_password(char*);

int main() {
    int choice;
    
    while(1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consumes the newline character
        
        switch(choice) {
            case 1:
                add_password();
                break;
            case 2:
                find_password();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                list_passwords();
                break;
            case 5:
                printf("Thank you for using the Password Manager\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

void display_menu() {
    printf("\n==== Password Manager ====\n");
    printf("1. Add Password\n");
    printf("2. Find Password\n");
    printf("3. Delete Password\n");
    printf("4. List Passwords\n");
    printf("5. Exit\n");
}

void add_password() {
    struct Password pwd;
    FILE* fp;
    
    printf("\nEnter the account name: ");
    fgets(pwd.account, MAX_LEN, stdin);
    pwd.account[strcspn(pwd.account, "\n")] = 0; // remove the newline character
    
    printf("Enter the username: ");
    fgets(pwd.username, MAX_LEN, stdin);
    pwd.username[strcspn(pwd.username, "\n")] = 0;
    
    printf("Enter the password: ");
    fgets(pwd.password, MAX_LEN, stdin);
    pwd.password[strcspn(pwd.password, "\n")] = 0;

    // encrypt the password before saving it to the file
    encrypt_password(pwd.password);

    fp = fopen("passwords.dat", "ab");
    if (fp == NULL) {
        printf("Error: Could not open the file.\n");
        return;
    }
    fwrite(&pwd, sizeof(struct Password), 1, fp);
    fclose(fp);
    
    printf("\nPassword saved successfully!\n");
}

void find_password() {
    char account[MAX_LEN];
    struct Password pwd;
    int found = 0;
    FILE* fp;
    
    printf("\nEnter the account name: ");
    fgets(account, MAX_LEN, stdin);
    account[strcspn(account, "\n")] = 0;
    
    fp = fopen("passwords.dat", "rb");
    if (fp == NULL) {
        printf("Error: Could not open the file.\n");
        return;
    }
    
    while(fread(&pwd, sizeof(struct Password), 1, fp)) {
        if (strcmp(pwd.account, account) == 0) {
            // decrypt the password before displaying it
            decrypt_password(pwd.password);
            
            printf("\nAccount Name: %s\n", pwd.account);
            printf("Username: %s\n", pwd.username);
            printf("Password: %s\n", pwd.password);
            found = 1;
            break;
        }
    }
    
    fclose(fp);
    
    if (!found) {
        printf("\nAccount not found!\n");
    }
}

void delete_password() {
    char account[MAX_LEN];
    struct Password pwd;
    int found = 0;
    int attempts = 0;
    FILE* fp, *temp;
    
    printf("\nEnter the account name: ");
    fgets(account, MAX_LEN, stdin);
    account[strcspn(account, "\n")] = 0;
    
    fp = fopen("passwords.dat", "rb");
    if (fp == NULL) {
        printf("Error: Could not open the file.\n");
        return;
    }
    
    temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        printf("Error: Could not create the temp file.\n");
        return;
    }
    
    while(fread(&pwd, sizeof(struct Password), 1, fp)) {
        if (strcmp(pwd.account, account) == 0) {
            found = 1;
            if (attempts >= MAX_ATTEMPTS) {
                printf("\nMax attempts reached! Aborting deletion.\n");
                fclose(fp);
                fclose(temp);
                remove("temp.dat");
                return;
            } else {
                printf("\nEnter the password to confirm deletion: ");
                char confirm[MAX_LEN];
                fgets(confirm, MAX_LEN, stdin);
                confirm[strcspn(confirm, "\n")] = 0;
                decrypt_password(pwd.password);
                if (strcmp(confirm, pwd.password) == 0) {
                    attempts = 0;
                    printf("\nPassword deleted successfully!\n");
                } else {
                    attempts++;
                    printf("\nIncorrect password! %d attempts left.\n", MAX_ATTEMPTS - attempts);
                    fwrite(&pwd, sizeof(struct Password), 1, temp);
                }
            }
        } else {
            fwrite(&pwd, sizeof(struct Password), 1, temp);
        }
    }
    
    fclose(fp);
    fclose(temp);
    remove("passwords.dat");
    rename("temp.dat", "passwords.dat");
    
    if (!found) {
        printf("\nAccount not found!\n");
    }
}

void list_passwords() {
    struct Password pwd;
    FILE* fp;
    
    fp = fopen("passwords.dat", "rb");
    if (fp == NULL) {
        printf("Error: Could not open the file.\n");
        return;
    }
    
    printf("\nList of Passwords:\n");
    while(fread(&pwd, sizeof(struct Password), 1, fp)) {
        // decrypt the password before displaying it
        decrypt_password(pwd.password);
        
        printf("\nAccount Name: %s\n", pwd.account);
        printf("Username: %s\n", pwd.username);
        printf("Password: %s\n", pwd.password);
    }
    
    fclose(fp);
}

void encrypt_password(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        password[i] = password[i] + 1; // just a simple encryption technique, adds one to each character
    }
}

void decrypt_password(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        password[i] = password[i] - 1; // reverse the encryption by subtracting one from each character
    }
}