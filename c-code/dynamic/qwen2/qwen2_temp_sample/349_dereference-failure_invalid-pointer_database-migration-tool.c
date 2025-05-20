#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

typedef struct {
    int id;
    char *name;
} User;

void migrate_users(User **users, int user_count) {
    for (int i = 0; i < user_count; i++) {
        if (users[i] == NULL) continue;
        printf("Migrating user %d: %s\n", users[i]->id, users[i]->name);
        // Deliberate dereference failure
        free(users[i]->name);
        users[i]->name = NULL;
    }
}

int main() {
    User users[3];
    users[0].id = 1;
    users[0].name = "Alice";
    users[1].id = 2;
    users[1].name = NULL;
    users[2].id = 3;
    users[2].name = "Charlie";

    migrate_users((User **)users, 3);

    for (int i = 0; i < 3; i++) {
        if (users[i].name != NULL) {
            printf("User %d name is still: %s\n", users[i].id, users[i].name);
        } else {
            printf("User %d name has been freed.\n", users[i].id);
        }
    }

    return 0;
}
