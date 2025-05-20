//Falcon-180B DATASET v1.0 Category: Password management ; Style: secure
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#define MAX_PASSWORDS 100
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32
#define PASSWORD_FILE "passwords.txt"

typedef struct {
    char username[64];
    char password[64];
    time_t last_modified;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void read_passwords() {
    FILE* fp = fopen(PASSWORD_FILE, "r");
    if (fp == NULL) {
        printf("Error: Password file not found.\n");
        return;
    }

    Password temp_password;
    while (fscanf(fp, "%s %s %ld\n", temp_password.username, temp_password.password, &temp_password.last_modified) == 3) {
        if (num_passwords >= MAX_PASSWORDS) {
            printf("Error: Maximum number of passwords reached.\n");
            fclose(fp);
            return;
        }

        strcpy(passwords[num_passwords].username, temp_password.username);
        strcpy(passwords[num_passwords].password, temp_password.password);
        passwords[num_passwords].last_modified = temp_password.last_modified;
        num_passwords++;
    }

    fclose(fp);
}

void write_passwords() {
    FILE* fp = fopen(PASSWORD_FILE, "w");
    if (fp == NULL) {
        printf("Error: Password file could not be written.\n");
        return;
    }

    for (int i = 0; i < num_passwords; i++) {
        fprintf(fp, "%s %s %ld\n", passwords[i].username, passwords[i].password, passwords[i].last_modified);
    }

    fclose(fp);
}

int compare_passwords(const void* a, const void* b) {
    const Password* p1 = (const Password*)a;
    const Password* p2 = (const Password*)b;

    return strcmp(p1->username, p2->username);
}

void sort_passwords() {
    qsort(passwords, num_passwords, sizeof(Password), compare_passwords);
}

int main() {
    read_passwords();
    sort_passwords();

    printf("Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }

    return 0;
}