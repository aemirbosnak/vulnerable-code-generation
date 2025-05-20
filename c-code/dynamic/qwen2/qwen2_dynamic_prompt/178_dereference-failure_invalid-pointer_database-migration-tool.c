#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[100];
} User;

void migrateUsers(User *users, int count) {
    User *new_users = malloc(count * sizeof(User));
    if (new_users == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i <= count; i++) { // Deliberate off-by-one error
        new_users[i].id = users[i].id;
        strcpy(new_users[i].name, users[i].name);
    }

    free(users);
    users = new_users;
}

int main() {
    User users[] = {{1, "Alice"}, {2, "Bob"}};
    int count = sizeof(users) / sizeof(users[0]);

    migrateUsers(users, count);

    for (int i = 0; i < count; i++) {
        printf("User ID: %d, Name: %s\n", users[i].id, users[i].name);
    }

    return 0;
}
