//FormAI DATASET v1.0 Category: Password management ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 50

struct password {
    char name[20];
    char password[20];
};

struct password password_list[MAX_PASSWORDS];
int num_passwords = 0;

void add_password();
void view_passwords();
void delete_password();

int main() {
    int choice;

    printf("Welcome to the Password Management System!\n");

    do {
        printf("\nEnter 1 to add a password\n");
        printf("Enter 2 to view all passwords\n");
        printf("Enter 3 to delete a password\n");
        printf("Enter 4 to quit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                printf("\nThank you for using the Password Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(1);

    return 0;
}

void add_password() {
    char name[20];
    char password[20];

    printf("\nEnter the name of the password: ");
    scanf("%s", name);

    printf("Enter the password: ");
    scanf("%s", password);

    struct password new_password;

    strcpy(new_password.name, name);
    strcpy(new_password.password, password);

    password_list[num_passwords++] = new_password;

    printf("\nPassword added successfully!\n");
}

void view_passwords() {
    if(num_passwords == 0) {
        printf("\nNo passwords found.\n");
        return;
    }

    printf("\nPasswords:\n");

    for(int i = 0; i < num_passwords; i++) {
        printf("%d. Name: %s, Password: %s\n", i + 1, password_list[i].name, password_list[i].password);
    }
}

void delete_password() {
    if(num_passwords == 0) {
        printf("\nNo passwords found.\n");
        return;
    }

    int password_num;

    printf("\nEnter the number of the password you want to delete: ");
    scanf("%d", &password_num);

    if(password_num > num_passwords || password_num < 1) {
        printf("\nInvalid password number.\n");
        return;
    }

    for(int i = password_num - 1; i < num_passwords - 1; i++) {
        password_list[i] = password_list[i + 1];
    }

    num_passwords--;

    printf("\nPassword deleted successfully!\n");
}