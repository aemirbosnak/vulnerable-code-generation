//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_PASSWORD_LENGTH 128
#define MAX_RECORDS 100

typedef struct {
    char website[50];
    char username[50];
    unsigned char hashed_password[SHA256_DIGEST_LENGTH];
} PasswordRecord;

void hash_password(const char *password, unsigned char *hashed_password) {
    SHA256((unsigned char*)password, strlen(password), hashed_password);
}

void save_password(PasswordRecord *record, int index) {
    FILE *file = fopen("passwords.dat", "ab");
    if (file == NULL) {
        perror("Unable to open file!");
        exit(EXIT_FAILURE);
    }
    fwrite(record, sizeof(PasswordRecord), 1, file);
    fclose(file);
}

void list_passwords() {
    PasswordRecord record;
    FILE *file = fopen("passwords.dat", "rb");
    if (file == NULL) {
        perror("Unable to open file!");
        exit(EXIT_FAILURE);
    }
    printf("\nStored Passwords:\n");
    printf("%-25s %-25s %-40s\n", "Website", "Username", "Hashed Password");
    while (fread(&record, sizeof(PasswordRecord), 1, file)) {
        printf("%-25s %-25s ", record.website, record.username);
        for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            printf("%02x", record.hashed_password[i]);
        }
        printf("\n");
    }
    fclose(file);
}

void create_password() {
    PasswordRecord record;
    char password[MAX_PASSWORD_LENGTH];
    
    printf("Enter website: ");
    scanf("%49s", record.website);
    printf("Enter username: ");
    scanf("%49s", record.username);
    
    printf("Enter password: ");
    scanf("%127s", password);
    
    hash_password(password, record.hashed_password);
    save_password(&record, 0);
    
    printf("Password saved successfully!\n");
}

void delete_password() {
    PasswordRecord records[MAX_RECORDS];
    PasswordRecord record;
    int count = 0;
    char website[50];
    
    FILE *file = fopen("passwords.dat", "rb");
    if (file == NULL) {
        perror("Unable to open file for reading!");
        exit(EXIT_FAILURE);
    }
    
    while (fread(&record, sizeof(PasswordRecord), 1, file)) {
        records[count++] = record;
    }
    fclose(file);
    
    printf("Enter the website to delete: ");
    scanf("%49s", website);
    
    file = fopen("passwords.dat", "wb");
    if (file == NULL) {
        perror("Unable to open file for writing!");
        exit(EXIT_FAILURE);
    }
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].website, website) == 0) {
            found = 1;
            continue; // Skip adding this record back
        }
        fwrite(&records[i], sizeof(PasswordRecord), 1, file);
    }
    
    fclose(file);

    if (found) {
        printf("Password entry for %s deleted successfully!\n", website);
    } else {
        printf("No password entry found for %s.\n", website);
    }
}

void menu() {
    int choice;
    do {
        printf("\nPassword Manager\n");
        printf("1. Create a new password record\n");
        printf("2. List all password records\n");
        printf("3. Delete a password record\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create_password();
                break;
            case 2:
                list_passwords();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}