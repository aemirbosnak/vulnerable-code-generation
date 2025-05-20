//FormAI DATASET v1.0 Category: Password management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 128

typedef struct {
    char website[50];
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

void add_password_entry(PasswordEntry *entries, int *num_entries) {
    char website[50], username[50], password[MAX_PASSWORD_LENGTH];
    printf("Enter website: ");
    scanf("%s", website);
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    strcpy(entries[*num_entries].website, website);
    strcpy(entries[*num_entries].username, username);
    strcpy(entries[*num_entries].password, password);
    *num_entries = *num_entries + 1;
}

void generate_random_password(char *password) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/";
    int charset_size = sizeof(charset) - 1;
    srand(time(NULL));
    for (int i = 0; i < MAX_PASSWORD_LENGTH - 1; i++) {
        password[i] = charset[rand() % charset_size];
    }
    password[MAX_PASSWORD_LENGTH - 1] = '\0';
}

void generate_password(PasswordEntry *entries, int num_entries) {
    int index;
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter website: ");
    char website[50];
    scanf("%s", website);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].website, website) == 0) {
            index = i;
            break;
        }
    }
    generate_random_password(password);
    printf("Generated password: %s\n", password);
    strcpy(entries[index].password, password);
}

void print_passwords(PasswordEntry *entries, int num_entries) {
    printf("Website\t\tUsername\t\tPassword\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t\t%s\t\t%s\n", entries[i].website, entries[i].username, entries[i].password);
    }
}

int main() {
    PasswordEntry entries[MAX_PASSWORDS];
    int num_entries = 0;
    int choice;
    do {
        printf("\n");
        printf("1. Add password entry\n");
        printf("2. Generate password\n");
        printf("3. Print passwords\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                add_password_entry(entries, &num_entries);
                break;
            case 2:
                generate_password(entries, num_entries);
                break;
            case 3:
                print_passwords(entries, num_entries);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}