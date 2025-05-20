//FormAI DATASET v1.0 Category: Password management ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PASSWORD_LENGTH 20

char *encrypt_password(char *password) {
    int len = strlen(password);
    char *encrypted_password = malloc(len * sizeof(char));

    for (int i = 0; i < len; i++) {
        encrypted_password[i] = password[i] + 3; // Shift each character by 3
    }

    return encrypted_password;
}

void save_password(char *password) {
    char *encrypted_password = encrypt_password(password);
    FILE *fp;

    fp = fopen("passwords.txt", "a");
    if (fp) {
        fprintf(fp, "%s\n", encrypted_password);
        fclose(fp);
        printf("Password saved successfully!\n");
    } else {
        printf("Error: Could not save password\n");
    }

    free(encrypted_password);
}

int check_password(char *password) {
    char *encrypted_password = encrypt_password(password);
    FILE *fp;
    int found = 0;

    fp = fopen("passwords.txt", "r");
    if (fp) {
        char buffer[MAX_PASSWORD_LENGTH];

        while (fgets(buffer, MAX_PASSWORD_LENGTH, fp)) {
            if (strcmp(buffer, encrypted_password) == 0) {
                found = 1;
                break;
            }
        }

        fclose(fp);
    }

    free(encrypted_password);
    return found;
}

int main() {
    int choice;
    char password[MAX_PASSWORD_LENGTH];

    printf("Welcome to Password Manager!\n");

    do {
        printf("Please choose an option:\n1. Save password\n2. Check password\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter password to save: ");
                scanf("%s", password);

                save_password(password);
                break;

            case 2:
                printf("Enter password to check: ");
                scanf("%s", password);

                if (check_password(password)) {
                    printf("Password is valid!\n");
                } else {
                    printf("Invalid password\n");
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 3);

    return 0;
}