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

void migrateDatabase(User *users, int count) {
    for (int i = 0; i <= count; i++) { // Off-by-one error
        printf("User ID: %d, Name: %s\n", users[i].id, users[i].name); // Dereference null pointer if users[i] is out of bounds
    }
}

int main() {
    User users[3];
    users[0].id = 1;
    users[0].name = "Alice";
    users[1].id = 2;
    users[1].name = "Bob";

    migrateDatabase(users, 2);

    return 0;
}
