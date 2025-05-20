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

void migrateUsers(User **users, int count) {
    for (int i = 0; i < count; i++) {
        if (users[i] != NULL) {
            free(users[i]->name);
            users[i]->name = NULL;
        }
    }
}

int main() {
    User *users[3];
    users[0] = malloc(sizeof(User));
    users[1] = malloc(sizeof(User));
    users[2] = NULL;

    users[0]->id = 1;
    users[0]->name = strdup("Alice");

    users[1]->id = 2;
    users[1]->name = strdup("Bob");

    migrateUsers(users, 3);

    // Dereference failure here: users[2] is NULL, but we try to access it
    printf("User %d: %s\n", users[2]->id, users[2]->name); // This line will cause a segmentation fault

    for (int i = 0; i < 3; i++) {
        if (users[i] != NULL) {
            free(users[i]);
        }
    }

    return 0;
}
