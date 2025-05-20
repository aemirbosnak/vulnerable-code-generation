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
    for (int i = 0; i <= count; i++) { // Off-by-one error
        printf("User ID: %d, Name: %s\n", users[i].id, users[i].name);
    }
}

int main() {
    User users[3] = {{1, "Alice"}, {2, "Bob"}};
    migrateUsers(users, 2); // Correct count
    return 0;
}
