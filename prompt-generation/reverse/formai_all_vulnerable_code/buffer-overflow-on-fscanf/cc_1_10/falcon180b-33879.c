//Falcon-180B DATASET v1.0 Category: Password management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 50

typedef struct {
    char name[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];
} password_t;

int main() {
    int num_passwords = 0;
    password_t passwords[MAX_PASSWORDS];

    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("No passwords found.\n");
        return 1;
    }

    while (fscanf(file, "%s %s", passwords[num_passwords].name, passwords[num_passwords].password) == 2) {
        num_passwords++;
        if (num_passwords == MAX_PASSWORDS) {
            printf("Maximum number of passwords reached.\n");
            break;
        }
    }

    fclose(file);

    char *input_name;
    char *input_password;

    while (1) {
        printf("Enter a name: ");
        scanf("%s", input_name);

        int found = 0;
        for (int i = 0; i < num_passwords; i++) {
            if (strcmp(input_name, passwords[i].name) == 0) {
                printf("Enter password for %s: ", input_name);
                scanf("%s", input_password);

                if (strcmp(input_password, passwords[i].password) == 0) {
                    printf("Password correct!\n");
                } else {
                    printf("Password incorrect.\n");
                }
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Name not found.\n");
        }

        printf("\n");
    }

    return 0;
}