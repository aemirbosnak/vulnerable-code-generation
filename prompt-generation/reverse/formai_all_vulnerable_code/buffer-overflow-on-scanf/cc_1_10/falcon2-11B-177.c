//Falcon2-11B DATASET v1.0 Category: Password management ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* password_file = "password.txt";

void read_password() {
    char* password = malloc(256);
    printf("Enter password: ");
    scanf("%s", password);
    printf("Password: %s\n", password);
    free(password);
}

void create_password_file() {
    FILE* f = fopen(password_file, "w");
    if (f == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fclose(f);
}

void add_password() {
    char* password = malloc(256);
    printf("Enter new password: ");
    read_password();
    printf("Add password to file? (y/n): ");
    char c;
    scanf("%c", &c);
    if (c == 'y') {
        FILE* f = fopen(password_file, "a");
        if (f == NULL) {
            perror("Error opening file");
            exit(1);
        }
        fprintf(f, "%s\n", password);
        fclose(f);
    }
    free(password);
}

char* get_password() {
    char* password = NULL;
    FILE* f = fopen(password_file, "r");
    if (f == NULL) {
        perror("Error opening file");
        exit(1);
    }
    while (fgets(password, 256, f)!= NULL) {
        printf("Password: %s\n", password);
    }
    fclose(f);
    return password;
}

int main() {
    create_password_file();
    add_password();
    add_password();
    add_password();
    get_password();
    get_password();
    get_password();
    return 0;
}