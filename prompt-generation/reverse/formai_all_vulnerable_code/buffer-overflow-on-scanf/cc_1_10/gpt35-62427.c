//FormAI DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 40

typedef struct password {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Password;

void add_password(Password *passwords, int *num_passwords);
void view_passwords(Password *passwords, int num_passwords);
void delete_password(Password *passwords, int *num_passwords);

int main() {
    Password *passwords = (Password*) malloc(sizeof(Password));
    int num_passwords = 0;
    char input;

    do {
        printf("------------------\n");
        printf("Password Manager\n");
        printf("------------------\n");
        printf("1. Add a password\n");
        printf("2. View saved passwords\n");
        printf("3. Delete a password\n");
        printf("4. Quit\n");

        printf("Enter selection: ");
        scanf(" %c", &input);

        switch(input) {
            case '1':
                add_password(passwords, &num_passwords);
                break;
            case '2':
                view_passwords(passwords, num_passwords);
                break;
            case '3':
                delete_password(passwords, &num_passwords);
                break;
            case '4':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid selection\n");
                break;
        }

    } while(input != '4');

    free(passwords);
    return 0;
}

void add_password(Password *passwords, int *num_passwords) {
    printf("---Add Password---\n");
    printf("Website name: ");
    scanf("%s", passwords[*num_passwords].website);
    printf("Username: ");
    scanf("%s", passwords[*num_passwords].username);
    printf("Password: ");
    scanf("%s", passwords[*num_passwords].password);
    *num_passwords = *num_passwords + 1;
    printf("Password saved!\n");
}

void view_passwords(Password *passwords, int num_passwords) {
    printf("---View Saved Passwords---\n");
    if(num_passwords == 0) {
        printf("No passwords saved\n");
        return;
    }
    for(int i = 0; i < num_passwords; i++) {
        printf("Website: %s\n", passwords[i].website);
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n", passwords[i].password);
    }
}

void delete_password(Password *passwords, int *num_passwords) {
    printf("---Delete a Password---\n");
    if(*num_passwords == 0) {
        printf("No passwords saved\n");
        return;
    }
    printf("Enter website name: ");
    char website_name[MAX_LENGTH];
    scanf("%s", website_name);

    for(int i = 0; i < *num_passwords; i++) {
        if(strcmp(passwords[i].website, website_name) == 0) {
            for(int j = i; j < *num_passwords-1; j++) {
                passwords[j] = passwords[j+1];
            }
            *num_passwords = *num_passwords - 1;
            printf("Password deleted!\n");
            return;
        }
    }
    printf("Website not found\n");
}