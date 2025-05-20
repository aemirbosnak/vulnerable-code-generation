//FormAI DATASET v1.0 Category: Password management ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_SIZE 20

struct Password {
   char website[MAX_SIZE];
   char username[MAX_SIZE];
   char password[MAX_SIZE];
};

void addPassword(struct Password passwords[], int *counter);
void showPasswords(struct Password passwords[], int count);
void generatePassword(int length, char *password);

int main() {
    struct Password passwords[MAX_PASSWORDS];
    int counter = 0;

    char choice;
    do {
        printf("\n[1] Add password\n");
        printf("[2] Show passwords\n");
        printf("[3] Exit\n");
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                addPassword(passwords, &counter);
                break;
            case '2':
                showPasswords(passwords, counter);
                break;
            case '3':
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    } while (choice != '3');

    return 0;
}

void addPassword(struct Password passwords[], int *counter) {
    char website[MAX_SIZE], username[MAX_SIZE], password[MAX_SIZE];

    printf("\nEnter website name: ");
    scanf("%s", website);

    printf("Enter username: ");
    scanf("%s", username);

    generatePassword(8, password);

    strcpy(passwords[*counter].website, website);
    strcpy(passwords[*counter].username, username);
    strcpy(passwords[*counter].password, password);

    printf("\nPassword added successfully!\n");

    (*counter)++;
}

void showPasswords(struct Password passwords[], int count) {
    if (count == 0) {
        printf("\nThere are no passwords saved.\n");
        return;
    }

    printf("\n%-20s %-20s %-20s\n", "Website", "Username", "Password");
    printf("-----------------------------------\n");

    for(int i = 0; i < count; i++) {
        printf("%-20s %-20s %-20s\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }
}

void generatePassword(int length, char *password) {
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+{}:;<>,.?/~`";
    int charsetSize = strlen(charset);

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charsetSize];
    }

    password[length] = '\0';
}