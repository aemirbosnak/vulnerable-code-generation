//Falcon-180B DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

struct password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int used;
};

void generate_password(char password[], int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }

    password[length] = '\0';
}

void save_password(FILE *file, struct password *password) {
    fprintf(file, "%s %s %d\n", password->name, password->password, password->used);
}

void load_password(FILE *file, struct password *password) {
    fscanf(file, "%s %s %d", password->name, password->password, &password->used);
}

int main() {
    FILE *password_file;
    char filename[MAX_PASSWORD_LENGTH];
    int choice, i;
    struct password passwords[MAX_PASSWORDS];

    printf("Enter the name of the password file: ");
    scanf("%s", filename);

    password_file = fopen(filename, "r");

    if (password_file == NULL) {
        printf("Password file not found.\n");
        exit(1);
    }

    printf("\nChoose an option:\n");
    printf("1. Create a new password\n");
    printf("2. View saved passwords\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the name of the website/account: ");
            scanf("%s", passwords[0].name);

            generate_password(passwords[0].password, MAX_PASSWORD_LENGTH);

            passwords[0].used = 1;

            save_password(password_file, &passwords[0]);

            printf("Password created and saved.\n");
            break;

        case 2:
            rewind(password_file);

            while (fscanf(password_file, "%s %s %d", passwords[0].name, passwords[0].password, &passwords[0].used)!= EOF) {
                printf("%s %s %s\n", passwords[0].name, passwords[0].password, passwords[0].used? "Used" : "Not used");
            }

            break;

        case 3:
            fclose(password_file);
            exit(0);

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}