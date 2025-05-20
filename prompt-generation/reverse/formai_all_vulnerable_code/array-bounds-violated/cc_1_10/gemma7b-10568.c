//Gemma-7B DATASET v1.0 Category: Password management ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    int used;
} Password;

Password passwords[MAX_PASSWORDS];

void generate_password(char *password) {
    int i, length = rand() % 10 + 1;
    for (i = 0; i < length; i++) {
        password[i] = 'a' + rand() % 26;
    }
    password[length] = '\0';
}

int main() {
    int i, password_count = 0;
    char input[20];
    system("clear");

    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].name = NULL;
        passwords[i].password = NULL;
        passwords[i].used = 0;
    }

    while (1) {
        printf("Enter a command (add/list/exit): ");
        scanf("%s", input);

        switch (input[0]) {
            case 'a':
                generate_password(passwords[password_count].password);
                passwords[password_count].name = malloc(20);
                printf("Enter a name for the password: ");
                scanf("%s", passwords[password_count].name);
                passwords[password_count].used = 1;
                password_count++;
                break;
            case 'l':
                for (i = 0; i < password_count; i++) {
                    if (passwords[i].used) {
                        printf("%s: %s\n", passwords[i].name, passwords[i].password);
                    }
                }
                break;
            case 'e':
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}