//FormAI DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LEN 20

char passwords[MAX_PASSWORDS][MAX_PASSWORD_LEN]; // array of passwords
int num_passwords = 0; // keep track of how many passwords are stored

void add_password(char password[]) {
    if (num_passwords < MAX_PASSWORDS) { // check if we have room for another password
        strcpy(passwords[num_passwords], password); // copy the password into our array
        num_passwords++; // increment the count
        printf("Successfully added password.\n");
    } else {
        printf("Failed to add password: maximum number of passwords reached.\n");
    }
}

void remove_password(char password[]) {
    int i, j;
    for (i = 0; i < num_passwords; i++) { // loop through stored passwords
        if (strcmp(passwords[i], password) == 0) { // check if this is the password we want to remove
            for (j = i; j < num_passwords - 1; j++) { // shift all subsequent passwords down one position
                strcpy(passwords[j], passwords[j+1]);
            }
            num_passwords--; // decrement the count
            printf("Successfully removed password.\n");
            return; // we're done here
        }
    }
    printf("Failed to remove password: password not found.\n");
}

void list_passwords() {
    int i;
    printf("Stored Passwords:\n");
    for (i = 0; i < num_passwords; i++) { // loop through stored passwords
        printf("%s\n", passwords[i]); // print each password
    }
}

int main() {
    char command[10];
    char password[MAX_PASSWORD_LEN];
    while (1) { // loop until user types "exit"
        printf("Enter command (add, remove, list, exit): ");
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            printf("Enter password to add: ");
            scanf("%s", password);
            add_password(password);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter password to remove: ");
            scanf("%s", password);
            remove_password(password);
        } else if (strcmp(command, "list") == 0) {
            list_passwords();
        } else if (strcmp(command, "exit") == 0) {
            break; // exit the loop and end the program
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}