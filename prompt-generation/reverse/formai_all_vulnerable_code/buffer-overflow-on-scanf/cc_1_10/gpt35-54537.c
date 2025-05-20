//FormAI DATASET v1.0 Category: Password management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct password {
    char website[50];
    char username[50];
    char password[50];
};

void print_password(struct password p) {
    printf("Website: %s\n", p.website);
    printf("Username: %s\n", p.username);
    printf("Password: %s\n", p.password);
}

int main(void) {
    struct password passwords[10];
    int password_count = 0;

    int input = 0;
    while (input != 4) {
        printf("Choose an option below:\n");
        printf("1. Add a password\n");
        printf("2. View all passwords\n");
        printf("3. Search for a password\n");
        printf("4. Exit\n");
        scanf("%d", &input);

        if (input == 1) {
            printf("Enter website:\n");
            scanf("%s", passwords[password_count].website);
            printf("Enter username:\n");
            scanf("%s", passwords[password_count].username);
            printf("Enter password:\n");
            scanf("%s", passwords[password_count].password);
            printf("Password added!\n");
            password_count++;
        } else if (input == 2) {
            if (password_count == 0) {
                printf("No passwords found.\n");
            } else {
                printf("All passwords:\n");
                for (int i = 0; i < password_count; i++) {
                    print_password(passwords[i]);
                }
            }
        } else if (input == 3) {
            char search_website[50];
            printf("Enter website to search for:\n");
            scanf("%s", search_website);
            int found = 0;
            for (int i = 0; i < password_count; i++) {
                if (strcmp(passwords[i].website, search_website) == 0) {
                    printf("Password found!\n");
                    print_password(passwords[i]);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Password not found.\n");
            }
        } else if (input == 4) {
            printf("Goodbye!\n");
        } else {
            printf("Invalid input.\n");
        }
    }

    return 0;
}