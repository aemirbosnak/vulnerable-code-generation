//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_SERVICE_LENGTH 50
#define MAX_PASSWORD_LENGTH 100
#define FILE_NAME "passwords.txt"

typedef struct {
    char service[MAX_SERVICE_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Entry;

void encrypt(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] = password[i] ^ 0xAA;  // Simple XOR encryption
    }
}

void decrypt(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] = password[i] ^ 0xAA;  // Simple XOR decryption
    }
}

void add_entry() {
    Entry entry;
    FILE *file = fopen(FILE_NAME, "a");

    if (!file) {
        fprintf(stderr, "Could not open file for writing.\n");
        return;
    }
    
    printf("Enter service name: ");
    scanf("%s", entry.service);
    printf("Enter password: ");
    scanf("%s", entry.password);
    
    encrypt(entry.password);
    
    fprintf(file, "%s %s\n", entry.service, entry.password);
    fclose(file);
    printf("Entry added successfully!\n");
}

void view_entries() {
    Entry entry;
    FILE *file = fopen(FILE_NAME, "r");
    
    if (!file) {
        fprintf(stderr, "Could not open file for reading.\n");
        return;
    }
    
    printf("\nSaved Entries:\n");
    while (fscanf(file, "%s %s", entry.service, entry.password) != EOF) {
        decrypt(entry.password);
        printf("Service: %s | Password: %s\n", entry.service, entry.password);
    }
    
    fclose(file);
}

void delete_entry() {
    char service[MAX_SERVICE_LENGTH];
    Entry entries[MAX_ENTRIES];
    int count = 0;
    
    printf("Enter service name to delete: ");
    scanf("%s", service);

    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        fprintf(stderr, "Could not open file for reading.\n");
        return;
    }

    while (fscanf(file, "%s %s", entries[count].service, entries[count].password) != EOF) {
        count++;
    }
    fclose(file);
    
    file = fopen(FILE_NAME, "w");
    if (!file) {
        fprintf(stderr, "Could not open file for writing.\n");
        return;
    }

    int deleted = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].service, service) != 0) {
            fprintf(file, "%s %s\n", entries[i].service, entries[i].password);
        } else {
            deleted = 1;
        }
    }
    fclose(file);
    
    if (deleted) {
        printf("Entry deleted successfully!\n");
    } else {
        printf("No entry found for service: %s\n", service);
    }
}

void display_menu() {
    printf("\nPassword Manager\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    do {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 4);
    
    return 0;
}