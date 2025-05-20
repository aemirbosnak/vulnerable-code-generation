//FormAI DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_PASSWORDS 100
#define PASSWORD_SIZE 20

struct Password {
    char site[50];
    char username[50];
    char password[PASSWORD_SIZE];
};

struct Passwords {
    int num_passwords;
    struct Password passwords[MAX_PASSWORDS];
};

void print_menu() {
    printf("1. Add new password\n");
    printf("2. View saved passwords\n");
    printf("3. Delete password\n");
    printf("4. Exit\n");
    printf("Enter option (1-4):");
}

void add_password(struct Passwords *passwords) {
    struct Password new_password;
    printf("Enter site name:");
    scanf("%s", new_password.site);
    printf("Enter username:");
    scanf("%s", new_password.username);
    printf("Enter password:");
    scanf("%s", new_password.password);
    passwords->passwords[passwords->num_passwords] = new_password;
    passwords->num_passwords++;
    printf("New password added!\n");
}

void view_passwords(struct Passwords passwords) {
    printf("Site\tUsername\tPassword\n");
    for(int i = 0; i < passwords.num_passwords; i++) {
        printf("%s\t%s\t%s\n", passwords.passwords[i].site, passwords.passwords[i].username, passwords.passwords[i].password);
    }
}

void delete_password(struct Passwords *passwords) {
    char site_name[50];
    printf("Enter site name for password to delete:");
    scanf("%s", site_name);
    int index = -1;
    for(int i = 0; i < passwords->num_passwords; i++) {
        if(strcmp(site_name, passwords->passwords[i].site) == 0) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("Site name not found!\n");
    } else {
        for(int i = index; i < passwords->num_passwords - 1; i++) {
            passwords->passwords[i] = passwords->passwords[i+1];
        }
        passwords->num_passwords--;
        printf("Password deleted!\n");
    }
}

int main() {
    struct Passwords passwords;
    passwords.num_passwords = 0;
    int option = 0;
    while(option != 4) {
        print_menu();
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_password(&passwords);
                break;
            case 2:
                view_passwords(passwords);
                break;
            case 3:
                delete_password(&passwords);
                break;
            case 4:
                printf("Goodbye my love, until we meet again...");
                break;
            default:
                printf("Not valid option, try again my dear.\n");
        }
    }
    return 0;
}