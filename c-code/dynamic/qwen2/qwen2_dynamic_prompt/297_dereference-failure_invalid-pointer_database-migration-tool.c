#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[256];
} User;

void migrateDatabase(User *users, int count) {
    User *newUsers = malloc(count * sizeof(User));
    if (!newUsers) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i <= count; i++) { // Dereference failure here
        newUsers[i].id = users[i].id;
        strcpy(newUsers[i].name, users[i].name);
    }

    free(users);
    users = newUsers;
}

int main() {
    User users[] = {{1, "Alice"}, {2, "Bob"}};
    int count = sizeof(users) / sizeof(users[0]);

    migrateDatabase(users, count);

    for (int i = 0; i < count; i++) {
        printf("User ID: %d, Name: %s\n", users[i].id, users[i].name);
    }

    return 0;
}
