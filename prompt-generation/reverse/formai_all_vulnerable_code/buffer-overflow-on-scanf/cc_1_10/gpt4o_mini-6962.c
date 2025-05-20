//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256
#define PASSWORD_FILE "passwords.dat"

typedef struct {
    char site[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Entry;

void encrypt(char *data) {
    for (int i = 0; data[i] != '\0'; ++i) {
        data[i] += 1; // Simple encryption by shifting ASCII values
    }
}

void decrypt(char *data) {
    for (int i = 0; data[i] != '\0'; ++i) {
        data[i] -= 1; // Decrypt by shifting back ASCII values
    }
}

void clear_buffer() {
    while (getchar() != '\n');
}

char *get_password(const char *prompt) {
    struct termios oldt, newt;
    char *password = malloc(MAX_LENGTH);
    
    printf("%s", prompt);
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO); // Disable echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    fgets(password, MAX_LENGTH, stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline character

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    printf("\n");
    
    return password;
}

void add_entry(Entry *entries, int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Maximum entries reached. Cannot add more passwords.\n");
        return;
    }
    
    Entry entry;
    printf("Enter site name: ");
    fgets(entry.site, MAX_LENGTH, stdin);
    entry.site[strcspn(entry.site, "\n")] = 0; // Remove newline
    
    printf("Enter username: ");
    fgets(entry.username, MAX_LENGTH, stdin);
    entry.username[strcspn(entry.username, "\n")] = 0; // Remove newline
    
    char *password = get_password("Enter password: ");
    strncpy(entry.password, password, MAX_LENGTH);
    encrypt(entry.password); // Encrypt password before saving

    entries[*count] = entry;
    (*count)++;
    
    free(password);
    printf("Entry added successfully!\n");
}

void view_entries(Entry *entries, int count) {
    printf("\nStored Passwords:\n");
    for (int i = 0; i < count; i++) {
        Entry entry = entries[i];
        decrypt(entry.password); // Decrypt password for viewing
        printf("Site: %s | Username: %s | Password: %s\n", entry.site, entry.username, entry.password);
        encrypt(entry.password); // Re-encrypt after viewing
    }
}

void save_to_file(Entry *entries, int count) {
    FILE *file = fopen(PASSWORD_FILE, "wb");
    if (file == NULL) {
        perror("Failed to open file for writing");
        return;
    }
    fwrite(entries, sizeof(Entry), count, file);
    fclose(file);
    printf("Entries saved to file: %s\n", PASSWORD_FILE);
}

void load_from_file(Entry *entries, int *count) {
    FILE *file = fopen(PASSWORD_FILE, "rb");
    if (file == NULL) {
        printf("No saved passwords found. Starting fresh.\n");
        return;
    }
    *count = fread(entries, sizeof(Entry), MAX_ENTRIES, file);
    fclose(file);
    printf("%d entries loaded from file: %s\n", *count, PASSWORD_FILE);
}

int main() {
    Entry *entries = malloc(sizeof(Entry) * MAX_ENTRIES);
    int count = 0;
    
    load_from_file(entries, &count);

    int choice;
    do {
        printf("\nPassword Management System\n");
        printf("1. Add Password Entry\n");
        printf("2. View Password Entries\n");
        printf("3. Save Password Entries\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clear_buffer(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                add_entry(entries, &count);
                break;
            case 2:
                view_entries(entries, count);
                break;
            case 3:
                save_to_file(entries, count);
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    free(entries);
    return 0;
}