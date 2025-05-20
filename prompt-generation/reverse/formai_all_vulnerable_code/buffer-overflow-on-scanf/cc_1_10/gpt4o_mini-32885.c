//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 50

typedef struct {
    char name[50];
    char password[PASSWORD_LENGTH];
} PasswordEntry;

PasswordEntry passwordList[MAX_PASSWORDS];
int passwordCount = 0;

// Function prototypes
void addPassword();
void viewPasswords();
void deletePassword();
void getch();
void mainMenu();

void getch() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    char ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    putchar('\n');
}

void addPassword() {
    if (passwordCount >= MAX_PASSWORDS) {
        printf("Maximum password limit reached!\n");
        return;
    }

    printf("Enter name for the password entry: ");
    scanf("%s", passwordList[passwordCount].name);

    printf("Enter password (it won't be displayed): ");
    getch(); // Call to getch function to hide password input
    scanf("%s", passwordList[passwordCount].password);
    passwordCount++;

    printf("Password entry added!\n");
}

void viewPasswords() {
    if (passwordCount == 0) {
        printf("No passwords stored!\n");
        return;
    }

    printf("\nStored Password Entries:\n");
    for (int i = 0; i < passwordCount; i++) {
        printf("%d: %s\n", i + 1, passwordList[i].name);
    }
}

void deletePassword() {
    if (passwordCount == 0) {
        printf("No passwords to delete!\n");
        return;
    }

    int index;
    printf("Enter the index of the password to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > passwordCount) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index - 1; i < passwordCount - 1; i++) {
        passwordList[i] = passwordList[i + 1];
    }
    
    passwordCount--;
    printf("Password entry deleted!\n");
}

void mainMenu() {
    int choice;
    do {
        printf("\n--- Password Manager ---\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
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
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    mainMenu();
    return 0;
}