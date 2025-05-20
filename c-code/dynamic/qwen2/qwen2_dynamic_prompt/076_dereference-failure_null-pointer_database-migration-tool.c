#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char *name;
} User;

void migrateUsers(User *users, int count) {
    for (int i = 0; i <= count; i++) { // Deliberate off-by-one error
        printf("User ID: %d, Name: %s\n", users[i].id, users[i].name); // Dereference failure if users[i] is null
    }
}

int main() {
    User users[3];
    users[0].id = 1;
    users[0].name = "Alice";
    users[1].id = 2;
    users[1].name = "Bob";

    migrateUsers(users, 2);

    return 0;
}
