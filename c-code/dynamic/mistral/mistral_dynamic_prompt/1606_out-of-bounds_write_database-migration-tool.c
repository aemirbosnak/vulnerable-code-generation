#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

struct User {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
};

void migrate_data(char *filename) {
    FILE *file = fopen(filename, "r");
    struct User user;
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    while (fscanf(file, "%s %s", user.name, user.email) == 2) {
        // Vulnerable section: Write to fixed-size array without bounds check
        strcpy(user.name, "Migrated User");
        strcat(user.name, fgets(user.name + MAX_NAME_LEN, sizeof(user.name), file));

        printf("Name: %s\nEmail: %s\n", user.name, user.email);
    }

    fclose(file);
}

int main() {
    migrate_data("users.txt");
    return 0;
}
