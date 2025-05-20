//FormAI DATASET v1.0 Category: Password management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PASSWORDS 50
#define MAX_LENGTH 20

struct password_manager {
    int num_passwords;
    char passwords[MAX_PASSWORDS][MAX_LENGTH+1];
};

void add_password(struct password_manager *pm) {
    char password[MAX_LENGTH+1];
    if (pm->num_passwords == MAX_PASSWORDS) {
        printf("Error: password manager is full\n");
        return;
    }
    printf("Enter new password (max length %d): ", MAX_LENGTH);
    scanf("%s", password);
    strcpy(pm->passwords[pm->num_passwords], password);
    pm->num_passwords++;
    printf("Password added successfully\n");
}

void list_passwords(struct password_manager *pm) {
    printf("Number of passwords: %d\n", pm->num_passwords);
    printf("Passwords:\n");
    for (int i=0; i<pm->num_passwords; i++) {
        printf("%s\n", pm->passwords[i]);
    }
}

void remove_password(struct password_manager *pm) {
    int index;
    printf("Enter index of password to remove (0-%d): ", pm->num_passwords-1);
    scanf("%d", &index);
    if (index < 0 || index >= pm->num_passwords) {
        printf("Error: invalid index\n");
        return;
    }
    for (int i=index; i<pm->num_passwords-1; i++) {
        strcpy(pm->passwords[i], pm->passwords[i+1]);
    }
    pm->num_passwords--;
    printf("Password removed successfully\n");
}

int main() {
    struct password_manager pm;
    pm.num_passwords = 0;
    while (1) {
        printf("Password Manager\n");
        printf("------------------------------------\n");
        printf("1. Add Password\n");
        printf("2. List Passwords\n");
        printf("3. Remove Password\n");
        printf("4. Exit\n");
        printf("------------------------------------\n");
        printf("Enter choice (1-4): ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_password(&pm);
                break;
            case 2:
                list_passwords(&pm);
                break;
            case 3:
                remove_password(&pm);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Error: invalid choice\n");
                break;
        }
    }
    return 0;
}