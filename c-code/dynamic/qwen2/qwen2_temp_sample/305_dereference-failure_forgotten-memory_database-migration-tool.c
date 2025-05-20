#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[256];
} User;

void migrateUsers(const char* sourceDbPath, const char* targetDbPath) {
    FILE *sourceFile = fopen(sourceDbPath, "rb");
    if (!sourceFile) {
        perror("Failed to open source database file");
        return;
    }

    User* users = NULL;
    size_t numUsers = 0;
    size_t bufferSize = 1024;

    while (!feof(sourceFile)) {
        User user;
        size_t bytesRead = fread(&user, sizeof(User), 1, sourceFile);
        if (bytesRead != 1) break;

        // Grow buffer
        if (numUsers >= bufferSize) {
            bufferSize *= 2;
            users = realloc(users, bufferSize * sizeof(User));
            if (!users) {
                perror("Memory allocation failed");
                fclose(sourceFile);
                return;
            }
        }

        // Add user to list
        users[numUsers++] = user;
    }

    fclose(sourceFile);

    // Simulate migration logic
    for (size_t i = 0; i < numUsers; i++) {
        User* user = &users[i];
        printf("Migrating user: %d - %s\n", user->id, user->name);
        // Deliberate dereference failure: forgot to free memory allocated by realloc
    }

    // Uncommenting the next line will fix the issue
    // free(users);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_db_path> <target_db_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    migrateUsers(argv[1], argv[2]);

    return EXIT_SUCCESS;
}
