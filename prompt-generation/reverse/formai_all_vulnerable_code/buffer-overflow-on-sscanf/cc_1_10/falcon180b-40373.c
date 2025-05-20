//Falcon-180B DATASET v1.0 Category: Password management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100
#define MAX_USERNAME_LENGTH 50

struct password {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void generate_password(char *password, int length) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }
    password[length] = '\0';
}

int main() {
    struct password passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    char filename[MAX_PASSWORD_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }
    char line[MAX_PASSWORD_LENGTH];
    while (fgets(line, MAX_PASSWORD_LENGTH, file)!= NULL) {
        if (num_passwords >= MAX_PASSWORDS) {
            printf("Maximum number of passwords reached.\n");
            break;
        }
        char username[MAX_USERNAME_LENGTH];
        char password[MAX_PASSWORD_LENGTH];
        sscanf(line, "%s %s", username, password);
        strcpy(passwords[num_passwords].username, username);
        strcpy(passwords[num_passwords].password, password);
        num_passwords++;
    }
    fclose(file);
    printf("Number of passwords: %d\n", num_passwords);
    for (int i = 0; i < num_passwords; i++) {
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n", passwords[i].password);
    }
    return 0;
}