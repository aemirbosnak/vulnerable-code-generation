//Falcon2-11B DATASET v1.0 Category: Password management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct password_entry {
    char username[100];
    char password[100];
};

void add_password(char *username, char *password) {
    struct password_entry entry;
    strcpy(entry.username, username);
    strcpy(entry.password, password);

    FILE *fp = fopen("passwords.txt", "a");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fprintf(fp, "%s:%s\n", entry.username, entry.password);

    fclose(fp);
}

void print_passwords() {
    FILE *fp = fopen("passwords.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char username[100], password[100];
    while (fscanf(fp, "%s:%s\n", username, password)!= EOF) {
        printf("%s\n", username);
        printf("Password: %s\n", password);
    }

    fclose(fp);
}

int main() {
    char *username = "john";
    char *password = "password123";

    add_password(username, password);
    print_passwords();

    return 0;
}