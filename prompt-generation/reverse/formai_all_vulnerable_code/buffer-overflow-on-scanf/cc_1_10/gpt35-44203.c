//FormAI DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

// function declarations
void menu();
void add_password();
void view_password();
void delete_password();
void update_password();
void print_all();
void store_password();

// struct for password entry
typedef struct {
    char name[MAX];
    char password[MAX];
} Entry;

Entry entries[MAX];
int count = 0;

int main() {
    // read previously stored passwords
    store_password();

    // print menu
    menu();

    return 0;
}

void menu() {
    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Add a new password\n");
        printf("2. View a password\n");
        printf("3. Delete a password\n");
        printf("4. Update a password\n");
        printf("5. Print all passwords\n");
        printf("6. Exit program\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // to clear input buffer

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_password();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                update_password();
                break;
            case 5:
                print_all();
                break;
            case 6:
                printf("Exiting program...\n");
                // store passwords before exiting
                store_password();
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);
}

void add_password() {
    if (count == MAX) {
        printf("Max number of passwords reached.\n");
        return;
    }

    printf("Enter name for password (max %d characters): ", MAX-1);
    scanf("%s", entries[count].name);
    getchar(); // to clear input buffer

    printf("Enter password for %s (max %d characters): ", entries[count].name, MAX-1);
    scanf("%s", entries[count].password);
    getchar(); // to clear input buffer

    count++;
    printf("Password added successfully.\n");
}

void view_password() {
    if (count == 0) {
        printf("No passwords to view.\n");
        return;
    }

    char name[MAX];
    printf("Enter name of password to view: ");
    scanf("%s", name);
    getchar(); // to clear input buffer

    for (int i = 0; i < count; i++) {
        if (strcmp(name, entries[i].name) == 0) {
            printf("Password for %s: %s\n", entries[i].name, entries[i].password);
            return;
        }
    }

    printf("No password found with name %s.\n", name);
}

void delete_password() {
    if (count == 0) {
        printf("No passwords to delete.\n");
        return;
    }

    char name[MAX];
    printf("Enter name of password to delete: ");
    scanf("%s", name);
    getchar(); // to clear input buffer

    for (int i = 0; i < count; i++) {
        if (strcmp(name, entries[i].name) == 0) {
            for (int j = i; j < count - 1; j++) {
                strcpy(entries[j].name, entries[j+1].name);
                strcpy(entries[j].password, entries[j+1].password);
            }
            count--;
            printf("Password deleted successfully.\n");
            return;
        }
    }

    printf("No password found with name %s.\n", name);
}

void update_password() {
    if (count == 0) {
        printf("No passwords to update.\n");
        return;
    }

    char name[MAX];
    printf("Enter name of password to update: ");
    scanf("%s", name);
    getchar(); // to clear input buffer

    for (int i = 0; i < count; i++) {
        if (strcmp(name, entries[i].name) == 0) {
            char password[MAX];
            printf("Enter new password for %s (max %d characters): ", entries[i].name, MAX-1);
            scanf("%s", password);
            getchar(); // to clear input buffer

            strcpy(entries[i].password, password);
            printf("Password updated successfully.\n");
            return;
        }
    }

    printf("No password found with name %s.\n", name);
}

void print_all() {
    if (count == 0) {
        printf("No passwords to print.\n");
        return;
    }

    printf("Printing all passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].password);
    }
}

void store_password() {
    FILE *fp = fopen("passwords.dat", "w");
    if (!fp) {
        printf("Failed to open file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %s\n", entries[i].name, entries[i].password);
    }

    fclose(fp);
}