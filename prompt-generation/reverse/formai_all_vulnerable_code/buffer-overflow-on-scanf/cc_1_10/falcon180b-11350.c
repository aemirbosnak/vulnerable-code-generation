//Falcon-180B DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 16

typedef struct {
    char password[PASSWORD_LENGTH];
    char site[64];
    char username[64];
    time_t creation_time;
} Password;

void generate_password(char* password) {
    const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+~`|}{[]\:;?><,./-=";
    int i = 0;
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }
    password[PASSWORD_LENGTH - 1] = '\0';
}

int compare_passwords(const void* a, const void* b) {
    const Password* passwordA = (const Password*)a;
    const Password* passwordB = (const Password*)b;
    return strcmp(passwordA->password, passwordB->password);
}

void print_password(const Password* password) {
    printf("Password: %s\n", password->password);
    printf("Site: %s\n", password->site);
    printf("Username: %s\n", password->username);
    printf("Creation Time: %s\n\n", ctime(&password->creation_time));
}

int main() {
    srand(time(NULL));
    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    while (num_passwords < MAX_PASSWORDS) {
        char site[64];
        printf("Enter site: ");
        scanf("%s", site);

        char username[64];
        printf("Enter username: ");
        scanf("%s", username);

        generate_password(passwords[num_passwords].password);
        strcpy(passwords[num_passwords].site, site);
        strcpy(passwords[num_passwords].username, username);
        passwords[num_passwords].creation_time = time(NULL);

        num_passwords++;
    }

    qsort(passwords, num_passwords, sizeof(Password), compare_passwords);

    for (int i = 0; i < num_passwords; i++) {
        print_password(&passwords[i]);
    }

    return 0;
}