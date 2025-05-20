//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 100

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry entries[MAX_ENTRIES];
int count = 0;

void add_password() {
    if (count >= MAX_ENTRIES) {
        printf("Password storage full. Cannot add more passwords.\n");
        return;
    }
    
    PasswordEntry new_entry;
    printf("Enter website: ");
    scanf("%s", new_entry.website);
    printf("Enter username: ");
    scanf("%s", new_entry.username);
    printf("Enter password: ");
    scanf("%s", new_entry.password);
    
    entries[count++] = new_entry;
    printf("Password added successfully!\n");
}

void view_passwords() {
    if (count == 0) {
        printf("No passwords stored.\n");
        return;
    }
    
    printf("Stored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("Website: %s, Username: %s, Password: %s\n", entries[i].website, entries[i].username, entries[i].password);
    }
}

void delete_password() {
    if (count == 0) {
        printf("No passwords stored to delete.\n");
        return;
    }
    
    char website[MAX_LENGTH];
    printf("Enter website to delete: ");
    scanf("%s", website);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].website, website) == 0) {
            for (int j = i; j < count - 1; j++) {
                entries[j] = entries[j + 1];
            }
            count--;
            printf("Password for %s deleted successfully!\n", website);
            return;
        }
    }
    printf("No entry found for website: %s\n", website);
}

void save_to_file() {
    FILE *file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %s\n", entries[i].website, entries[i].username, entries[i].password);
    }
    fclose(file);
    printf("Passwords saved successfully!\n");
}

void load_from_file() {
    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("No saved passwords found.\n");
        return;
    }
    
    while (fscanf(file, "%s %s %s", entries[count].website, entries[count].username, entries[count].password) != EOF && count < MAX_ENTRIES) {
        count++;
    }
    fclose(file);
    printf("Passwords loaded successfully!\n");
}

void show_menu() {
    printf("\nPassword Manager\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Save to File\n");
    printf("5. Load from File\n");
    printf("6. Exit\n");
}

int main() {
    load_from_file();
    int choice;

    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                save_to_file();
                break;
            case 5:
                load_from_file();
                break;
            case 6:
                save_to_file();
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}