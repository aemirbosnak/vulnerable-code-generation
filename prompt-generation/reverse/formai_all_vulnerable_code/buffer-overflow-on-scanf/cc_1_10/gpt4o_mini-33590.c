//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 50

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwordList[MAX_ENTRIES];
int count = 0;

// Function declarations
void addPassword();
void viewPasswords();
void deletePassword();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    
    do {
        printf("🎉 Welcome to the Cheerful Password Manager! 🎉\n");
        printf("Please choose an option:\n");
        printf("1. Add a new password\n");
        printf("2. View all passwords\n");
        printf("3. Delete a password\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                printf("🎈 Thank you for using the Cheerful Password Manager! Goodbye! 🎈\n");
                break;
            default:
                printf("🚫 Oops! Please enter a valid choice (1-4).\n");
        }
        
        printf("\n");
    } while (choice != 4);
}

void addPassword() {
    if (count >= MAX_ENTRIES) {
        printf("🚫 Sorry! The password list is full. Can't add more passwords!\n");
        return;
    }
    
    printf("✨ Let's add a new password! ✨\n");
    printf("Enter website name: ");
    scanf("%s", passwordList[count].website);
    
    printf("Enter username: ");
    scanf("%s", passwordList[count].username);

    printf("Enter password: ");
    scanf("%s", passwordList[count].password);

    count++;
    printf("✅ Password added successfully! 💾\n");
}

void viewPasswords() {
    if (count == 0) {
        printf("🚫 No passwords saved yet! Please add some.\n");
        return;
    }
    
    printf("📜 Here are your saved passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Website: %s\n", passwordList[i].website);
        printf("Username: %s\n", passwordList[i].username);
        printf("Password: %s\n", passwordList[i].password);
        printf("-------------------------------\n");
    }
}

void deletePassword() {
    if (count == 0) {
        printf("🚫 No passwords to delete! Please add some first.\n");
        return;
    }
    
    int idx;
    printf("Enter the entry number you want to delete (1 to %d): ", count);
    scanf("%d", &idx);
    
    if (idx < 1 || idx > count) {
        printf("🚫 Invalid entry number! Please try again.\n");
        return;
    }

    for (int i = idx - 1; i < count - 1; i++) {
        passwordList[i] = passwordList[i + 1];
    }
    
    count--;
    printf("✅ Password deleted successfully! 🌟 Keep smiling! 😊\n");
}