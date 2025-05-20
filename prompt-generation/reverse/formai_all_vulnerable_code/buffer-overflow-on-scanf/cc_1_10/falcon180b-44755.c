//Falcon-180B DATASET v1.0 Category: Password management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 32

struct password {
    char name[64];
    char password[PASSWORD_LENGTH];
};

void generate_password(char password[PASSWORD_LENGTH]) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[PASSWORD_LENGTH - 1] = '\0';
}

int main() {
    FILE *passwords_file;
    struct password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    passwords_file = fopen("passwords.txt", "r");
    if (passwords_file!= NULL) {
        while (fscanf(passwords_file, "%s %s\n", passwords[num_passwords].name, passwords[num_passwords].password)!= EOF) {
            num_passwords++;
        }
        fclose(passwords_file);
    }

    int choice;
    while (1) {
        printf("1. Add a password\n");
        printf("2. Generate a password\n");
        printf("3. Save passwords to file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_passwords >= MAX_PASSWORDS) {
                printf("Maximum number of passwords reached.\n");
            } else {
                printf("Enter the name of the website/service: ");
                scanf("%s", passwords[num_passwords].name);
                generate_password(passwords[num_passwords].password);
                num_passwords++;
                printf("Password generated and saved.\n");
            }
            break;

        case 2:
            printf("Enter the name of the website/service: ");
            scanf("%s", passwords[0].name);
            generate_password(passwords[0].password);
            printf("Password generated and saved.\n");
            break;

        case 3:
            passwords_file = fopen("passwords.txt", "w");
            if (passwords_file!= NULL) {
                for (int i = 0; i < num_passwords; i++) {
                    fprintf(passwords_file, "%s %s\n", passwords[i].name, passwords[i].password);
                }
                fclose(passwords_file);
                printf("Passwords saved to file.\n");
            } else {
                printf("Error saving passwords to file.\n");
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}