//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_ENTRIES 100

typedef struct {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Entry;

void encrypt(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] ^= 0xAA; // Simple XOR encryption
    }
}

void decrypt(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] ^= 0xAA; // Simple XOR decryption
    }
}

void addEntry(Entry *entries, int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Entry limit reached. Cannot add more entries.\n");
        return;
    }
    
    Entry *newEntry = &entries[*count];
    
    printf("Enter website: ");
    scanf("%s", newEntry->website);
    
    printf("Enter username: ");
    scanf("%s", newEntry->username);
    
    printf("Enter password: ");
    char password[MAX_PASSWORD_LENGTH];
    scanf("%s", password);
    
    encrypt(password);
    strcpy(newEntry->password, password);
    
    (*count)++;
    printf("Entry added successfully!\n");
}

void viewEntries(Entry *entries, int count) {
    if (count == 0) {
        printf("No entries available.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        char decryptedPassword[MAX_PASSWORD_LENGTH];
        strcpy(decryptedPassword, entries[i].password);
        decrypt(decryptedPassword);
        
        printf("Website: %s\n", entries[i].website);
        printf("Username: %s\n", entries[i].username);
        printf("Password: %s\n\n", decryptedPassword);
    }
}

void saveEntries(Entry *entries, int count) {
    FILE *file = fopen("passwords.dat", "wb");
    if (!file) {
        printf("Error saving entries.\n");
        return;
    }
    fwrite(entries, sizeof(Entry), count, file);
    fclose(file);
    printf("Entries saved successfully!\n");
}

void loadEntries(Entry *entries, int *count) {
    FILE *file = fopen("passwords.dat", "rb");
    if (!file) {
        printf("No saved entries found.\n");
        return;
    }
    *count = fread(entries, sizeof(Entry), MAX_ENTRIES, file);
    fclose(file);
    printf("%d entries loaded successfully!\n", *count);
}

int main() {
    Entry entries[MAX_ENTRIES];
    int count = 0;
    loadEntries(entries, &count);

    int choice;
    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Save Entries\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(entries, &count);
                break;
            case 2:
                viewEntries(entries, count);
                break;
            case 3:
                saveEntries(entries, count);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}