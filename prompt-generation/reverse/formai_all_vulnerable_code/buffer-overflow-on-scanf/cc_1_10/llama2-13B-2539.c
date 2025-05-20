//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define MAX_ATTEMPTS 3

struct password {
    char *name;
    char *password;
};

struct password passwords[MAX_PASSWORDS] = {
    {"Alice", "secret123"},
    {"Bob", "password1"},
    {"Charlie", "123456"},
    {"David", "mypassword"},
    {"Eve", "qwerty"}
};

int main() {
    int attempts = 0;

    printf("Welcome to the curious password manager!\n");

    while (1) {
        printf("Please enter the name of the password you want to access: ");
        char name[50];
        fgets(name, 50, stdin);

        for (int i = 0; i < MAX_PASSWORDS; i++) {
            if (strcmp(name, passwords[i].name) == 0) {
                printf("Enter the correct password for %s: ", name);
                char password[50];
                fgets(password, 50, stdin);

                if (strcmp(password, passwords[i].password) == 0) {
                    printf("Correct password! Access granted.\n");
                    break;
                } else {
                    printf("Incorrect password. Try again? (y/n): ");
                    char answer;
                    scanf("%c", &answer);

                    if (answer == 'y' || answer == 'Y') {
                        attempts++;
                        if (attempts >= MAX_ATTEMPTS) {
                            printf("Too many incorrect attempts. Access denied.\n");
                            break;
                        }
                        continue;
                    } else {
                        printf("Access denied. Goodbye.\n");
                        break;
                    }
                }
            }
        }
    }

    return 0;
}