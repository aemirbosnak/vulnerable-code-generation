//FormAI DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_NUM_PASSWORDS 10

struct Password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct Password password_list[MAX_NUM_PASSWORDS];
int num_passwords = 0;

void add_password() {
    if(num_passwords >= MAX_NUM_PASSWORDS) {
        printf("Maximum number of passwords reached!\n");
        return;
    }

    struct Password pw;
    printf("Enter name for password: ");
    scanf("%s", pw.name);
    printf("Enter password: ");
    scanf("%s", pw.password);

    password_list[num_passwords] = pw;
    num_passwords++;
    printf("Password added successfully!\n");
}

void delete_password() {
    if(num_passwords == 0) {
        printf("There are no passwords to delete!\n");
        return;
    }

    char name[MAX_PASSWORD_LENGTH];
    printf("Enter name of password to delete: ");
    scanf("%s", name);

    int i = 0;
    int found_password = 0;
    for(i=0; i<num_passwords; i++) {
        if(strcmp(password_list[i].name, name) == 0) {
            found_password = 1;
            break;
        }
    }

    if(found_password) {
        for(int j=i+1; j<num_passwords; j++) {
            password_list[j-1] = password_list[j];
        }
        num_passwords--;
        printf("Password deleted successfully!\n");
    } else {
        printf("Password not found!\n");
    }
}

void list_passwords() {
    if(num_passwords == 0) {
        printf("There are no passwords to display!\n");
        return;
    }

    printf("Passwords:\n");
    for(int i=0; i<num_passwords; i++) {
        printf("%s: %s\n", password_list[i].name, password_list[i].password);
    }
}

int main() {
    int choice;
    while(1) {
        printf("\nPassword Manager\n");
        printf("1. Add Password\n");
        printf("2. Delete Password\n");
        printf("3. List Passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_password();
                break;
            case 2:
                delete_password();
                break;
            case 3:
                list_passwords();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}