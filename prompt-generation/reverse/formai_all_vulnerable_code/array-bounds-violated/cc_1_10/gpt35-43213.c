//FormAI DATASET v1.0 Category: Password management ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// define the maximum characters of the password
#define MAX_LENGTH 50

// function prototypes
void menu();
void generate_password();
void save_password();
void view_password();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    printf("\n\tPASSWORD MANAGEMENT SYSTEM\n");
    printf("\t1. Generate a password\n");
    printf("\t2. Save a password\n");
    printf("\t3. View saved passwords\n");
    printf("\t4. Exit\n");
    printf("\tEnter your choice (1-4): ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            generate_password();
            break;
        case 2:
            save_password();
            break;
        case 3:
            view_password();
            break;
        case 4:
            printf("\tGoodbye!\n");
            exit(0);
        default:
            printf("\tInvalid choice. Try again.\n");
            menu();
            break;
    }
}

void generate_password() {
    char password[MAX_LENGTH + 1];
    int length;
    printf("\tEnter the length of the password (1-%d): ", MAX_LENGTH);
    scanf("%d", &length);
    for (int i = 0; i < length; i++) {
        password[i] = rand() % 94 + 33; // ASCII code for printable characters
    }
    password[length] = '\0';
    printf("\tGenerated password: %s\n", password);
    menu();
}

void save_password() {
    char website[MAX_LENGTH + 1];
    char password[MAX_LENGTH + 1];
    FILE *fptr;
    fptr = fopen("passwords.txt", "a");
    if (fptr == NULL) {
        printf("\tError: Cannot open file.\n");
        menu();
    }
    printf("\tEnter the website or account name: ");
    scanf("%s", website);
    printf("\tEnter the password: ");
    scanf("%s", password);
    fprintf(fptr, "%s: %s\n", website, password);
    fclose(fptr);
    printf("\tPassword has been saved!\n");
    menu();
}

void view_password() {
    char line[MAX_LENGTH + MAX_LENGTH + 4]; // website + colon + space + password + newline
    FILE *fptr;
    fptr = fopen("passwords.txt", "r");
    if (fptr == NULL) {
        printf("\tNo saved passwords yet.\n");
        menu();
    }
    printf("\tSaved passwords:\n");
    while (fgets(line, sizeof(line), fptr)) {
        printf("\t%s", line);
    }
    fclose(fptr);
    menu();
}