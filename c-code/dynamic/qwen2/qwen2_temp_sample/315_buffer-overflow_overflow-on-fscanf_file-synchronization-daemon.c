#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 16

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} User;

void sync_users() {
    User user;
    FILE *file = fopen("users.txt", "r");
    if (!file) {
        printf("Failed to open users.txt\n");
        return;
    }

    while (fscanf(file, "%16s %d", user.name, &user.age) == 2) {
        printf("User: %s, Age: %d\n", user.name, user.age);
    }
    fclose(file);
}

int main() {
    printf("Starting file synchronization daemon...\n");
    sync_users();
    printf("Daemon shutting down.\n");
    return 0;
}
