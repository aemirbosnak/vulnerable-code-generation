//Falcon-180B DATASET v1.0 Category: Password management ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 100

struct password {
    char *username;
    char *password;
};

void generatePassword(char *password, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int charset_length = strlen(charset);
    for(int i=0; i<length; i++) {
        password[i] = charset[rand() % charset_length];
    }
    password[length] = '\0';
}

int comparePasswords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    int length;
    int numPasswords = 0;
    struct password passwords[MAX_PASSWORDS];

    printf("Enter the desired length of the password: ");
    scanf("%d", &length);

    printf("Enter the number of passwords to generate: ");
    scanf("%d", &numPasswords);

    for(int i=0; i<numPasswords; i++) {
        printf("Enter the username for password #%d: ", i+1);
        scanf("%s", &(passwords[i].username));
        generatePassword(password, length);
        strcpy(passwords[i].password, password);
    }

    qsort(passwords, numPasswords, sizeof(struct password), comparePasswords);

    for(int i=0; i<numPasswords; i++) {
        printf("Username: %s\nPassword: %s\n\n", passwords[i].username, passwords[i].password);
    }

    return 0;
}