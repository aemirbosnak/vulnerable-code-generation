//FormAI DATASET v1.0 Category: Password management ; Style: protected
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_PASSWORDS 50 // Maximum number of passwords that can be stored

typedef struct {
    char username[30];
    char password[30];
} Password;

Password passwordArray[MAX_PASSWORDS]; // Password array to store all the usernames and passwords
int passwordIndex = 0; // Index to keep track of the number of passwords stored

void addPassword() {
    if (passwordIndex == MAX_PASSWORDS) {
        printf("Maximum number of passwords reached!\n");
        return;
    }

    Password newPass;
    printf("Enter username:\n");
    scanf("%s", newPass.username);
    printf("Enter password:\n");
    scanf("%s", newPass.password);

    passwordArray[passwordIndex++] = newPass;
    printf("Password added successfully!\n");
}

void removePassword() {
    if (passwordIndex == 0) {
        printf("No passwords to remove!\n");
        return;
    }

    char username[30];
    printf("Enter username to remove:\n");
    scanf("%s", username);

    int index = -1;
    for (int i = 0; i < passwordIndex; i++) {
        if (strcmp(passwordArray[i].username, username) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Username not found!\n");
    } else {
        for (int i = index; i < passwordIndex - 1; i++) {
            passwordArray[i] = passwordArray[i+1];
        }
        passwordIndex--;
        printf("Password removed successfully!\n");
    }
}

void printPasswords() {
    if (passwordIndex == 0) {
        printf("No passwords stored!\n");
        return;
    }

    printf("Username\tPassword\n");
    printf("=============================\n");
    for (int i = 0; i < passwordIndex; i++) {
        printf("%s\t\t%s\n", passwordArray[i].username, passwordArray[i].password);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nPassword Manager\n");
        printf("=============================\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. Print all passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice:\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;

            case 2:
                removePassword();
                break;

            case 3:
                printPasswords();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }

    return 0;
}