//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 50
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    char password[MAX_LENGTH];
} PasswordEntry;

typedef struct {
    PasswordEntry entries[MAX_PASSWORDS];
    int count;
} PasswordManager;

void initManager(PasswordManager* mgr) {
    mgr->count = 0;
}

void addPassword(PasswordManager* mgr) {
    if (mgr->count >= MAX_PASSWORDS) {
        printf("Our love has grown too large! Can't handle more secrets.\n");
        return;
    }

    PasswordEntry entry;
    printf("Whisper sweetly, what is the name of your beloved?\n");
    scanf("%s", entry.name);
    printf("And what is the secret password to that heart?\n");
    scanf("%s", entry.password);

    mgr->entries[mgr->count++] = entry;
    printf("Ah, a new love has been secured! %s's heart is locked away.\n", entry.name);
}

void viewPasswords(PasswordManager* mgr) {
    if (mgr->count == 0) {
        printf("Your heart longs for more secrets to keep.\n");
        return;
    }
    
    printf("Let's open the vault of secrets:\n");
    for (int i = 0; i < mgr->count; i++) {
        printf("Beloved: %s | Password: %s\n", mgr->entries[i].name, mgr->entries[i].password);
    }
}

void deletePassword(PasswordManager* mgr) {
    if (mgr->count == 0) {
        printf("There are no memories to erase, my dear.\n");
        return;
    }

    char name[MAX_NAME];
    printf("Whose memory would you like to erase from your heart?\n");
    scanf("%s", name);

    for (int i = 0; i < mgr->count; i++) {
        if (strcmp(mgr->entries[i].name, name) == 0) {
            printf("Goodbye, sweet memory of %s.\n", mgr->entries[i].name);
            for (int j = i; j < mgr->count - 1; j++) {
                mgr->entries[j] = mgr->entries[j + 1];
            }
            mgr->count--;
            return;
        }
    }
    printf("Oh, it seems %s was never part of our love story.\n", name);
}

void showMenu() {
    printf("\nWelcome to the garden of love and secrets!\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Exit\n");
    printf("Choose your romantic path: ");
}

int main() {
    PasswordManager manager;
    initManager(&manager);
    int choice;

    do {
        showMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPassword(&manager);
                break;
            case 2:
                viewPasswords(&manager);
                break;
            case 3:
                deletePassword(&manager);
                break;
            case 4:
                printf("May your heart always hold its secrets close!\n");
                break;
            default:
                printf("Ah, a misstep on this romantic journey. Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}