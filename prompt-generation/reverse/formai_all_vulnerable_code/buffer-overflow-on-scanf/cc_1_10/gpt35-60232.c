//FormAI DATASET v1.0 Category: Password management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct password_entry {
    char service[30];
    char username[30];
    char password[30];
};

void add_entry(struct password_entry *entries, int *n) {
    if (*n >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }
    
    struct password_entry new_entry;
    printf("Enter service name:");
    scanf("%s", new_entry.service);
    printf("Enter username:");
    scanf("%s", new_entry.username);
    printf("Enter password:");
    scanf("%s", new_entry.password);
    
    // Add new entry to end of array
    entries[*n] = new_entry;
    (*n)++;
    
    printf("New entry added successfully.\n");
}

void list_entries(struct password_entry *entries, int n) {
    if (n == 0) {
        printf("No entries found.\n");
        return;
    }
    
    printf("Service\t\tUsername\tPassword\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t\t%s\t\t%s\n", entries[i].service, entries[i].username, entries[i].password);
    }
    printf("---------------------------------------------------\n");
}

void delete_entry(struct password_entry *entries, int *n) {
    if (*n == 0) {
        printf("No entries found.\n");
        return;
    }
    
    char service[30];
    printf("Enter service name of entry to delete: ");
    scanf("%s", service);
    
    int index = -1;
    for (int i = 0; i < *n; i++) {
        if (strcmp(entries[i].service, service) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Error: Entry with service name %s not found.\n", service);
        return;
    }
    
    // Shift entries to the left
    for (int i = index; i < *n - 1; i++) {
        entries[i] = entries[i+1];
    }
    
    (*n)--;
    
    printf("Entry with service name %s deleted successfully.\n", service);
}

void save_entries(struct password_entry *entries, int n) {
    FILE *file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("Error: Failed to open file for writing.\n");
        return;
    }
    
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s %s %s\n", entries[i].service, entries[i].username, entries[i].password);
    }
    
    fclose(file);
    printf("Entries saved to file successfully.\n");
}

void load_entries(struct password_entry *entries, int *n) {
    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("File does not exist. Creating new file.\n");
        return;
    }
    
    char service[30];
    char username[30];
    char password[30];
    
    while (fscanf(file, "%s %s %s", service, username, password) == 3) {
        struct password_entry new_entry;
        strcpy(new_entry.service, service);
        strcpy(new_entry.username, username);
        strcpy(new_entry.password, password);
        
        // Add new entry to end of array
        entries[*n] = new_entry;
        (*n)++;
        
        // Break if maximum number of entries reached
        if (*n >= MAX_ENTRIES) {
            break;
        }
    }
    
    fclose(file);
    printf("Entries loaded from file successfully.\n");
}

int main() {
    struct password_entry entries[MAX_ENTRIES];
    int n = 0;
    
    printf("Password Manager\n");
    printf("=======================================\n");
    
    // Load entries from file if it exists
    load_entries(entries, &n);
    
    while (1) {
        printf("1. Add entry\n");
        printf("2. List entries\n");
        printf("3. Delete entry\n");
        printf("4. Save entries\n");
        printf("5. Exit\n");
        
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_entry(entries, &n);
                break;
            case 2:
                list_entries(entries, n);
                break;
            case 3:
                delete_entry(entries, &n);
                break;
            case 4:
                save_entries(entries, n);
                break;
            case 5:
                // Save entries to file before exiting
                save_entries(entries, n);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}