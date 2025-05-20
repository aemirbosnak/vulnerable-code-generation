//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PW_LEN 100
#define MAX_PWS 50
#define MAX_SITE_LEN 50

typedef struct {
    char site[MAX_SITE_LEN];
    char password[MAX_PW_LEN];
} Entry;

Entry vault[MAX_PWS];
int count = 0;

void add_password();
void view_passwords();
void delete_password();
void clear_buffer();

int main() {
    int choice;
    do {
        printf("\n==================\n");
        printf("  Password Manager  \n");
        printf("==================\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        
        scanf("%d", &choice);
        clear_buffer(); // Clear stdin buffer

        switch (choice) {
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
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

void add_password() {
    if (count >= MAX_PWS) {
        printf("Vault full! Cannot add more passwords.\n");
        return;
    }
    printf("Enter site: ");
    fgets(vault[count].site, MAX_SITE_LEN, stdin);
    vault[count].site[strcspn(vault[count].site, "\n")] = 0; // Remove newline

    printf("Enter password: ");
    fgets(vault[count].password, MAX_PW_LEN, stdin);
    vault[count].password[strcspn(vault[count].password, "\n")] = 0; // Remove newline

    count++;
    printf("Password for '%s' added successfully!\n", vault[count - 1].site);
}

void view_passwords() {
    if (count == 0) {
        printf("No passwords stored!\n");
        return;
    }
    printf("\nStored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s : %s\n", i + 1, vault[i].site, vault[i].password);
    }
}

void delete_password() {
    int idx;
    if (count == 0) {
        printf("No passwords to delete!\n");
        return;
    }
    printf("Enter the number of the password to delete: ");
    scanf("%d", &idx);
    clear_buffer(); // Clear stdin buffer

    if (idx < 1 || idx > count) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = idx - 1; i < count - 1; i++) {
        vault[i] = vault[i + 1];
    }
    count--;
    printf("Password deleted successfully!\n");
}

void clear_buffer() {
    while (getchar() != '\n'); // Flush input buffer
}