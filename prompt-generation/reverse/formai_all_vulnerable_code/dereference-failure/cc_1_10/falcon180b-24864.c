//Falcon-180B DATASET v1.0 Category: Password management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 16
#define SALT_LENGTH 16

typedef struct {
    char password[PASSWORD_LENGTH];
    char salt[SALT_LENGTH];
    time_t created_at;
} Password;

void generate_password(Password *password) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+={}[]|\\:;\"',.<>/?";
    time_t now = time(NULL);
    srand(now);
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password->password[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    for (int i = 0; i < SALT_LENGTH; i++) {
        password->salt[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    password->created_at = now;
}

int compare_password(Password *password, char *input_password) {
    return strcmp(password->password, input_password) == 0;
}

void save_password(Password *password, FILE *file) {
    fwrite(password, sizeof(Password), 1, file);
}

Password load_password(FILE *file) {
    Password password;
    fread(&password, sizeof(Password), 1, file);
    return password;
}

int main() {
    FILE *file = fopen("passwords.dat", "a+");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    Password password;
    generate_password(&password);
    password.created_at = time(NULL);
    save_password(&password, file);
    fclose(file);

    char input_password[PASSWORD_LENGTH];
    while (1) {
        printf("Enter your password: ");
        scanf("%s", input_password);
        if (compare_password(&password, input_password)) {
            printf("Password correct!\n");
            break;
        } else {
            printf("Password incorrect!\n");
        }
    }

    return 0;
}