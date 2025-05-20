#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void read_config(char *filename) {
    char buffer[20];
    FILE *fp = fopen(filename, "r");

    if (!fp) {
        printf("Error opening config file.\n");
        return;
    }

    while (fscanf(fp, "%s", buffer) != EOF) {
        printf("Line: %s\n", buffer);
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: migrate config.txt\n");
        return 1;
    }

    read_config(argv[1]);

    char db_password[1];
    fscanf(stdin, "%s", db_password);

    printf("New password is: %s\n", db_password);

    // Your magic migration logic here...

    return 0;
}
