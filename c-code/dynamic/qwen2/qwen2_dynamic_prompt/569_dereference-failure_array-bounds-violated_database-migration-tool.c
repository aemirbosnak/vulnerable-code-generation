#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct {
    int id;
    char name[20];
} User;

void migrateDatabase(User *users, int size) {
    User newUsers[size + 1]; // Allocate memory for one more user than expected
    for (int i = 0; i <= size; i++) { // Dereference failure here: accessing out-of-bounds index
        newUsers[i].id = users[i].id;
        strcpy(newUsers[i].name, users[i].name);
    }
}

int main() {
    User users[TABLE_SIZE] = {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Charlie"}
    };

    migrateDatabase(users, TABLE_SIZE);

    return 0;
}
