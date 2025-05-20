#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void copy_data(char *dest, char *src, int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

void print_help() {
    printf("Usage: migration_tool <database_name> <password>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_help();
        return 1;
    }

    char db_name[10];
    char password[50];

    scanf("%s%s", db_name, password);

    char db_data[256];
    copy_data(db_data, db_name, sizeof(db_name));
    copy_data(db_data + strlen(db_name), password, strlen(password));

    printf("Starting database migration for: %s\n", db_data);

    // Perform migration logic here...

    return 0;
}
