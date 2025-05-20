#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

typedef struct {
    char name[50];
    char email[100];
} User;

void read_user(User* user) {
    char buffer[MAX_BUFFER];
    printf("Enter user details:\nName: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%s", user->name);
    printf("Email: ");
    fgets(buffer, sizeof(buffer), stdin);
    strcpy(user->email, buffer);
}

int main() {
    User users[100];
    int user_count = 0;

    printf("Database Migration Tool\n");

    while (1) {
        read_user(&users[user_count]);
        user_count++;
        printf("Add another user? (y/n): ");
        char choice[2];
        fgets(choice, sizeof(choice), stdin);
        if (choice[0] == 'n') break;
    }

    printf("\nMigrating data...\n");

    // Oversized format write
    char sql[MAX_BUFFER];
    for (int i = 0; i < user_count; i++) {
        sprintf(sql, "INSERT INTO users(name, email) VALUES('%s', '%s');\n", users[i].name, users[i].email);
        printf("%s", sql);
    }

    return 0;
}
