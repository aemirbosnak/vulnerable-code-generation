//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_RECORDS 100

typedef struct {
    char site[50];
    char username[50];
    char password[50];
} Record;

void add_record(Record *records, int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Record limit reached. Cannot add more records.\n");
        return;
    }
    
    printf("Enter the site name: ");
    scanf("%s", records[*count].site);
    
    printf("Enter the username: ");
    scanf("%s", records[*count].username);
    
    printf("Enter the password: ");
    scanf("%s", records[*count].password);
    
    (*count)++;
    printf("Record added successfully!\n");
}

void view_records(Record *records, int count) {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\n--- Password Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Site: %s, Username: %s, Password: %s\n", records[i].site, records[i].username, records[i].password);
    }
    printf("------------------------\n");
}

void generate_strong_password(char *password, size_t length) {
    const char *charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
    
    for (size_t i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

void change_password(Record *records, int count) {
    char site[50];
    printf("Enter the site name for which you want to change the password: ");
    scanf("%s", site);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].site, site) == 0) {
            printf("Enter new password: ");
            scanf("%s", records[i].password);
            printf("Password changed successfully!\n");
            return;
        }
    }
    
    printf("No record found for the site %s.\n", site);
}

void delete_record(Record *records, int *count) {
    char site[50];
    printf("Enter the site name to delete: ");
    scanf("%s", site);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(records[i].site, site) == 0) {
            for (int j = i; j < *count - 1; j++) {
                records[j] = records[j + 1];
            }
            (*count)--;
            printf("Record for %s deleted successfully!\n", site);
            return;
        }
    }
    
    printf("No record found for the site %s.\n", site);
}

void save_records_to_file(Record *records, int count) {
    FILE *file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %s\n", records[i].site, records[i].username, records[i].password);
    }
    
    fclose(file);
    printf("Records saved to passwords.txt.\n");
}

void load_records_from_file(Record *records, int *count) {
    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("No saved records found.\n");
        return;
    }
    
    while (fscanf(file, "%s %s %s", records[*count].site, records[*count].username, records[*count].password) != EOF) {
        (*count)++;
    }
    
    fclose(file);
    printf("Records loaded successfully!\n");
}

int main() {
    Record records[MAX_RECORDS];
    int count = 0;
    int choice;

    load_records_from_file(records, &count);

    do {
        printf("\n--- Password Manager ---\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Change Password\n");
        printf("4. Delete Record\n");
        printf("5. Generate Strong Password\n");
        printf("6. Save Records\n");
        printf("7. Load Records\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_record(records, &count); break;
            case 2: view_records(records, count); break;
            case 3: change_password(records, count); break;
            case 4: delete_record(records, &count); break;
            case 5: {
                char password[20];
                generate_strong_password(password, 12);
                printf("Generated strong password: %s\n", password);
                break;
            }
            case 6: save_records_to_file(records, count); break;
            case 7: load_records_from_file(records, &count); break;
            case 0: printf("Exiting the password manager. Stay secure!\n"); break;
            default: printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);

    return 0;
}