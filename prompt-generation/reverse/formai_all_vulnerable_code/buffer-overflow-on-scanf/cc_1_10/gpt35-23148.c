//FormAI DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 25
#define PASSWORD_FILE "passwords.dat"

struct password {
    char name[MAX_PASSWORD_LENGTH];
    char value[MAX_PASSWORD_LENGTH];
};

void add_password(struct password* passwords[], int* num_passwords);
void show_passwords(struct password* passwords[], int num_passwords);
void search_and_display_password(struct password* passwords[], int num_passwords);
void delete_password(struct password* passwords[], int* num_passwords);
void save_passwords(struct password* passwords[], int num_passwords);

int main() {
    struct password* passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    FILE* fp;
    fp = fopen(PASSWORD_FILE, "rb");

    if (fp != NULL) {
        fread(&num_passwords, sizeof(int), 1, fp);

        for (int i = 0; i < num_passwords; i++) {
            passwords[i] = (struct password*) malloc(sizeof(struct password));
            fread(passwords[i], sizeof(struct password), 1, fp);
        }

        fclose(fp);
    }

    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add Password\n");
        printf("2. Show Passwords\n");
        printf("3. Search and Display Password\n");
        printf("4. Delete Password\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password(passwords, &num_passwords);
                break;
            case 2:
                show_passwords(passwords, num_passwords);
                break;
            case 3:
                search_and_display_password(passwords, num_passwords);
                break;
            case 4:
                delete_password(passwords, &num_passwords);
                break;
            case 5:
                save_passwords(passwords, num_passwords);
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void add_password(struct password* passwords[], int* num_passwords) {
    if (*num_passwords >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    struct password* tmp = (struct password*) malloc(sizeof(struct password));

    printf("\nEnter the name of the password (max %d characters): ", MAX_PASSWORD_LENGTH);
    scanf("%s", tmp->name);
    printf("Enter the value of the password (max %d characters): ", MAX_PASSWORD_LENGTH);
    scanf("%s", tmp->value);

    passwords[*num_passwords] = tmp;
    (*num_passwords)++;

    printf("\nPassword added successfully!\n");
}

void show_passwords(struct password* passwords[], int num_passwords) {
    if (num_passwords == 0) {
        printf("\nThere are no passwords stored.\n");
        return;
    }

    printf("\nName\tValue\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t%s\n", passwords[i]->name, passwords[i]->value);
    }
}

void search_and_display_password(struct password* passwords[], int num_passwords) {
    if (num_passwords == 0) {
        printf("\nThere are no passwords stored.\n");
        return;
    }

    char name[MAX_PASSWORD_LENGTH];
    printf("\nEnter the name of the password to search for: ");
    scanf("%s", name);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i]->name, name) == 0) {
            printf("\nName\tValue\n");
            printf("%s\t%s\n", passwords[i]->name, passwords[i]->value);
            return;
        }
    }

    printf("\nPassword not found.\n");
}

void delete_password(struct password* passwords[], int* num_passwords) {
    if (*num_passwords == 0) {
        printf("\nThere are no passwords stored.\n");
        return;
    }

    char name[MAX_PASSWORD_LENGTH];
    printf("\nEnter the name of the password to delete: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < *num_passwords; i++) {
        if (strcmp(passwords[i]->name, name) == 0) {
            free(passwords[i]);
            break;
        }
    }

    if (i == *num_passwords) {
        printf("\nPassword not found.\n");
        return;
    }

    for (int j = i; j < *num_passwords - 1; j++) {
        passwords[j] = passwords[j + 1];
    }

    (*num_passwords)--;

    printf("\nPassword deleted successfully!\n");
}

void save_passwords(struct password* passwords[], int num_passwords) {
    FILE* fp;
    fp = fopen(PASSWORD_FILE, "wb");

    if (fp != NULL) {
        fwrite(&num_passwords, sizeof(int), 1, fp);

        for (int i = 0; i < num_passwords; i++) {
            fwrite(passwords[i], sizeof(struct password), 1, fp);
        }

        fclose(fp);
    }
}