//Falcon-180B DATASET v1.0 Category: File handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

struct user {
    char name[64];
    char email[128];
    char password[128];
};

int main() {
    FILE *file;
    char filename[128] = "users.txt";
    char line[MAX_LINE_LENGTH];
    struct user user;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[--len] = '\0';
        }

        int name_len = 0;
        int email_len = 0;
        int password_len = 0;

        char *name_ptr = strtok(line, "|");
        while (name_ptr!= NULL) {
            if (name_len >= sizeof(user.name)) {
                printf("Error: Name field too long for user %s\n", line);
                exit(1);
            }
            strncat(user.name, name_ptr, sizeof(user.name) - name_len - 1);
            name_len += strlen(name_ptr);
            name_ptr = strtok(NULL, "|");
        }

        char *email_ptr = strtok(NULL, "|");
        while (email_ptr!= NULL) {
            if (email_len >= sizeof(user.email)) {
                printf("Error: Email field too long for user %s\n", line);
                exit(1);
            }
            strncat(user.email, email_ptr, sizeof(user.email) - email_len - 1);
            email_len += strlen(email_ptr);
            email_ptr = strtok(NULL, "|");
        }

        char *password_ptr = strtok(NULL, "|");
        while (password_ptr!= NULL) {
            if (password_len >= sizeof(user.password)) {
                printf("Error: Password field too long for user %s\n", line);
                exit(1);
            }
            strncat(user.password, password_ptr, sizeof(user.password) - password_len - 1);
            password_len += strlen(password_ptr);
            password_ptr = strtok(NULL, "|");
        }

        printf("Name: %s\nEmail: %s\nPassword: %s\n", user.name, user.email, user.password);
    }

    fclose(file);
    return 0;
}