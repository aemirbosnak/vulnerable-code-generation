//FormAI DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct password_s {
    char* name;
    char* site;
    char* username;
    char* password;
} password_t;

password_t* create_password(char* name, char* site, char* username, char* password) {
    password_t* password_entry = malloc(sizeof(password_t));
    password_entry->name = strdup(name);
    password_entry->site = strdup(site);
    password_entry->username = strdup(username);
    password_entry->password = strdup(password);
    return password_entry;
}

void destroy_password(password_t* password_entry) {
    free(password_entry->name);
    free(password_entry->site);
    free(password_entry->username);
    free(password_entry->password);
    free(password_entry);
}

void print_password(password_t* password_entry) {
    printf("%s:\n", password_entry->name);
    printf("  Site: %s\n", password_entry->site);
    printf("  Username: %s\n", password_entry->username);
    printf("  Password: %s\n", password_entry->password);
}

void print_password_list(password_t** password_list, size_t count) {
    for (size_t i = 0; i < count; i++) {
        print_password(password_list[i]);
    }
}

int main(int argc, char** argv) {
    password_t** password_list = NULL;
    size_t password_count = 0;
    char name[256], site[256], username[256], password[256], confirmation[256];

    printf("Welcome to password manager!\n");
    while (1) {
        printf("What would you like to do?\n");
        printf("  1. Add a password\n");
        printf("  2. View all passwords\n");
        printf("  3. Exit\n");

        int choice;
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            continue;
        }

        if (choice == 1) {
            printf("Name: ");
            scanf("%255s", name);

            printf("Site: ");
            scanf("%255s", site);

            printf("Username: ");
            scanf("%255s", username);

            printf("Password: ");
            scanf("%255s", password);

            printf("Confirm password: ");
            scanf("%255s", confirmation);

            if (strcmp(password, confirmation) != 0) {
                printf("Confirmation password does not match\n");
                continue;
            }

            if (strlen(password) < 8) {
                printf("Password must be at least 8 characters long\n");
                continue;
            }

            if (!isalnum(password[0])) {
                printf("Password must start with an alphanumeric character\n");
                continue;
            }

            if (!strpbrk(password, " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~")) {
                printf("Password must contain at least one special character\n");
                continue;
            }

            password_t* password_entry = create_password(name, site, username, password);
            password_list = realloc(password_list, (password_count + 1) * sizeof(password_t*));
            password_list[password_count++] = password_entry;

            printf("Password added successfully!\n");
        } else if (choice == 2) {
            if (password_count == 0) {
                printf("No passwords added yet\n");
                continue;
            }

            printf("All passwords:\n");
            print_password_list(password_list, password_count);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    for (size_t i = 0; i < password_count; i++) {
        destroy_password(password_list[i]);
    }
    free(password_list);

    printf("Goodbye!\n");
    return 0;
}