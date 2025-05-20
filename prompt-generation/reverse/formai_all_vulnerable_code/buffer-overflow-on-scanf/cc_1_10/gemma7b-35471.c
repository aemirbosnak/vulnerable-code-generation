//Gemma-7B DATASET v1.0 Category: Password management ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char name[20];
    char password[20];
    int used;
} Password;

void create_password(Password *passwords, int index) {
    printf("Enter the name of the password:");
    scanf("%s", passwords[index].name);

    printf("Enter the password:");
    scanf("%s", passwords[index].password);

    passwords[index].used = 0;
}

void use_password(Password *passwords, int index) {
    printf("Enter the name of the password:");
    scanf("%s", passwords[index].name);

    if (strcmp(passwords[index].name, passwords[index].name) == 0) {
        printf("Enter the password:");
        scanf("%s", passwords[index].password);

        if (strcmp(passwords[index].password, passwords[index].password) == 0) {
            passwords[index].used = 1;
            printf("Access granted.\n");
        } else {
            printf("Incorrect password.\n");
        }
    } else {
        printf("Incorrect password name.\n");
    }
}

int main() {
    Password passwords[MAX_PASSWORDS];

    for (int i = 0; i < MAX_PASSWORDS; i++) {
        create_password(passwords, i);
    }

    for (int i = 0; i < MAX_PASSWORDS; i++) {
        use_password(passwords, i);
    }

    return 0;
}