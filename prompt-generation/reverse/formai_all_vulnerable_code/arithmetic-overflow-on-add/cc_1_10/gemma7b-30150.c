//Gemma-7B DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORDS 10

struct Password {
    char name[20];
    char password[MAX_PASSWORDS][20];
    int index;
};

void storePassword(struct Password *passwords) {
    printf("Enter the name for the password:");
    scanf("%s", passwords->name);

    printf("Enter the password:");
    scanf("%s", passwords->password[passwords->index]);

    passwords->index++;
}

void displayPassword(struct Password *passwords) {
    int i = 0;
    for (i = 0; i < passwords->index; i++) {
        printf("Name: %s, Password: %s\n", passwords->name[i], passwords->password[i]);
    }
}

int main() {
    struct Password passwords;
    passwords.index = 0;

    while (1) {
        printf("Enter 1 to store a password, 2 to display passwords, or 3 to exit:");
        int choice = scanf(" %d ", "");

        switch (choice) {
            case 1:
                storePassword(&passwords);
                break;
            case 2:
                displayPassword(&passwords);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}