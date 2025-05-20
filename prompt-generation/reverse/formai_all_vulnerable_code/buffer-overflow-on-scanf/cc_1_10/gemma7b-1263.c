//Gemma-7B DATASET v1.0 Category: Password management ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    int strength;
} Password;

Password passwords[MAX_PASSWORDS];

int main() {
    int i = 0;
    char choice;

    system("clear");

    while (i < MAX_PASSWORDS) {
        passwords[i].name = malloc(20);
        passwords[i].password = malloc(20);
        printf("Enter password name: ");
        scanf("%s", passwords[i].name);

        printf("Enter password: ");
        scanf("%s", passwords[i].password);

        passwords[i].strength = rand() % 5 + 1;

        printf("Password strength: %d\n", passwords[i].strength);

        i++;
    }

    printf("Press 'S' to save, 'C' to cancel: ");
    scanf(" %c", &choice);

    if (choice == 'S') {
        system("clear");
        printf("Saved passwords:\n");
        for (i = 0; i < MAX_PASSWORDS; i++) {
            printf("Name: %s, Password: %s, Strength: %d\n", passwords[i].name, passwords[i].password, passwords[i].strength);
        }
    } else if (choice == 'C') {
        system("clear");
        printf("Cancelled.\n");
    } else {
        system("clear");
        printf("Invalid input.\n");
    }

    return 0;
}