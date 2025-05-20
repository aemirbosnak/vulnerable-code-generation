//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program allows the user to manage a mailing list in a cryptic style.
// Only the user who knows the secret password can access the mailing list.

char *password = "password123";
char *mailing_list[100];
int mailing_list_size = 0;

int authenticate(char *input_password) {
    if (strcmp(password, input_password) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void print_menu() {
    printf("\nWelcome to the Mailing List Manager\n");
    printf("1. Add email to mailing list\n");
    printf("2. Remove email from mailing list\n");
    printf("3. View mailing list\n");
    printf("4. Exit\n");
    printf("Enter option: ");
}

void add_email() {
    char email[50];
    printf("Enter email: ");
    scanf("%s", email);
    mailing_list[mailing_list_size] = malloc(sizeof(email));
    strcpy(mailing_list[mailing_list_size], email);
    mailing_list_size++;
    printf("%s added to mailing list.\n", email);
}

void remove_email() {
    char email[50];
    printf("Enter email: ");
    scanf("%s", email);
    for (int i = 0; i < mailing_list_size; i++) {
        if (strcmp(mailing_list[i], email) == 0) {
            free(mailing_list[i]);
            for (int j = i; j < mailing_list_size-1; j++) {
                mailing_list[j] = mailing_list[j+1];
            }
            mailing_list_size--;
            printf("%s removed from mailing list.\n", email);
            return;
        }
    }
    printf("%s not found in mailing list.\n", email);
}

void view_mailing_list() {
    printf("\nMailing List:\n");
    for (int i = 0; i < mailing_list_size; i++) {
        printf("%s\n", mailing_list[i]);
    }
    printf("\n");
}

int main() {
    char input_password[20];
    printf("Enter password: ");
    scanf("%s", input_password);
    if (authenticate(input_password) == 0) {
        printf("Incorrect password. Access denied.\n");
        exit(0);
    }
    while (1) {
        print_menu();
        int option;
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_email();
                break;
            case 2:
                remove_email();
                break;
            case 3:
                view_mailing_list();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}