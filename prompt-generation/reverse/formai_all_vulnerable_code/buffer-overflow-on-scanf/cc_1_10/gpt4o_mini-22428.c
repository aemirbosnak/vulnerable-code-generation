//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LEN 50

typedef struct {
    char website[MAX_LEN];
    char username[MAX_LEN];
    char password[MAX_LEN];
} PasswordEntry;

PasswordEntry passwordList[MAX_PASSWORDS];
int passwordCount = 0;

void addPassword();
void viewPasswords();
void deletePassword();
void displayMenu();

int main() {
    printf("\n\n🎉 Welcome to Happy Password Manager! 🎉\n\n");

    while (1) {
        displayMenu();
        
        int choice;
        printf("Please choose an option (1-4): ");
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
                printf("Exiting the Happy Password Manager! Have a great day! 🌈\n");
                exit(0);
            default:
                printf("Oops! That's not a valid choice. Please try again! 😊\n");
        }
    }
}

void displayMenu() {
    printf("\n😊 Menu Options 😊\n");
    printf("1. Add a new password\n");
    printf("2. View passwords\n");
    printf("3. Delete a password\n");
    printf("4. Exit\n");
}

void addPassword() {
    if (passwordCount >= MAX_PASSWORDS) {
        printf("🎈 Sorry! The password list is full. Please delete some passwords to add new ones! 🎈\n");
        return;
    }

    PasswordEntry newEntry;
    printf("Enter the website name: ");
    scanf("%s", newEntry.website);
    printf("Enter the username: ");
    scanf("%s", newEntry.username);
    printf("Enter the password: ");
    scanf("%s", newEntry.password);

    passwordList[passwordCount] = newEntry;
    passwordCount++;
    
    printf("👍 Password added successfully for %s! Enjoy your day! 🌼\n", newEntry.website);
}

void viewPasswords() {
    if (passwordCount == 0) {
        printf("😞 No passwords stored yet! Please add some passwords first! 🌟\n");
        return;
    }
    
    printf("\n🌟 Here are your stored passwords: 🌟\n");
    for (int i = 0; i < passwordCount; i++) {
        printf("Website: %s | Username: %s | Password: %s\n", passwordList[i].website, 
               passwordList[i].username, passwordList[i].password);
    }
}

void deletePassword() {
    if (passwordCount == 0) {
        printf("😞 No passwords available to delete! Add some first! 🌟\n");
        return;
    }

    char website[MAX_LEN];
    printf("Enter the website name you want to delete: ");
    scanf("%s", website);
    
    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordList[i].website, website) == 0) {
            // Shift the remaining entries to the left
            for (int j = i; j < passwordCount - 1; j++) {
                passwordList[j] = passwordList[j + 1];
            }
            passwordCount--;
            printf("🎉 Successfully deleted the password for %s! 😊\n", website);
            return;
        }
    }
    printf("😔 Sorry! No password found for %s. Please check the name! 💔\n", website);
}