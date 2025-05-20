//Falcon-180B DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int is_used;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void generate_password(char* password) {
    int length = rand() % MAX_PASSWORD_LENGTH + 8;
    for (int i = 0; i < length; i++) {
        int rand_char = rand() % 3;
        if (rand_char == 0) {
            password[i] = 'a' + rand() % 26;
        } else if (rand_char == 1) {
            password[i] = 'A' + rand() % 26;
        } else {
            password[i] = '0' + rand() % 10;
        }
    }
    password[length] = '\0';
}

void print_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("%s - %s\n", passwords[i].password, passwords[i].is_used? "Used" : "Available");
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX_PASSWORDS; i++) {
        generate_password(passwords[i].password);
        passwords[i].is_used = 0;
        num_passwords++;
    }

    int choice;
    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Generate a new password\n");
        printf("2. View available passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            generate_password(passwords[num_passwords - 1].password);
            num_passwords++;
            break;
        case 2:
            print_passwords();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}