//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 32

typedef struct {
    char name[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwordList[MAX_PASSWORDS];
int count = 0;

// Function declarations
void addPassword();
void viewPasswords();
void deletePassword();
void freeMemory();

int main() {
    printf("O, fair user! Welcome to the realm of password management,\n");
    printf("Wherein we shall protect thy secrets with the strength of our code.\n");

    int choice;
    while (1) {
        printf("\nChoose thy fate:\n");
        printf("1. Add a password\n");
        printf("2. View passwords\n");
        printf("3. Delete a password\n");
        printf("4. Exit\n");
        printf("> ");
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
                printf("Adieu, sweet user! May thy secrets remain safe.\n");
                freeMemory();
                exit(0);
            default:
                printf("Alas! I know not this choice. Try again.\n");
        }
    }
}

void addPassword() {
    if (count >= MAX_PASSWORDS) {
        printf("O! The bank of passwords is full, sweet user.\n");
        return;
    }
    
    printf("Enter the name of thy precious secret (label): ");
    scanf("%s", passwordList[count].name);
    printf("Enter the password for %s: ", passwordList[count].name);
    scanf("%s", passwordList[count].password);
    count++;
    printf("Thy password for %s hath been added to our sacred vault!\n", passwordList[count - 1].name);
}

void viewPasswords() {
    if (count == 0) {
        printf("O woe betide! No secrets reside in this vault.\n");
        return;
    }
    
    printf("Hearken to the passwords thou hast stored:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, passwordList[i].name);
    }
}

void deletePassword() {
    if (count == 0) {
        printf("Alas! No passwords to extract from the shadows.\n");
        return;
    }

    int index;
    printf("Choose the index of the password to be erased (1 to %d): ", count);
    scanf("%d", &index);
    
    if (index < 1 || index > count) {
        printf("O dearest user! Such an index exists not!\n");
        return;
    }

    index--; // Adjust for 0-based index
    printf("The password for %s hath been erased from our memory.\n", passwordList[index].name);
    
    // Shift remaining entries to fill the gap
    for (int i = index; i < count - 1; i++) {
        passwordList[i] = passwordList[i + 1];
    }
    count--;
}

void freeMemory() {
    printf("Releasing thy secrets back to the void...\n");
    // Explicit free (not freeing memory allocated dynamically in this case)
}