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
    for (int i = 0; i <= count; i++) { // Deliberate off-by-one error
        printf("User ID: %d, Name: %s\n", users[i].id, users[i].name); // Dereference failure if users is NULL or count is too large
    }
}

int main() {
    User users[] = {{1, "Alice"}, {2, "Bob"}};
    int userCount = sizeof(users) / sizeof(users[0]);

    migrateUsers(NULL, userCount); // Passing NULL to simulate a dereference failure

    return 0;
}
