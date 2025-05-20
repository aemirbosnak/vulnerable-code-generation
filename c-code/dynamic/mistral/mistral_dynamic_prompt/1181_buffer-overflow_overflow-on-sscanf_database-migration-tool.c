#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void parse_command(char *buffer) {
    char input[10];
    char database[100];
    char query[200];

    sscanf(buffer, "%s %s %s", input, database, query);

    // Dangerous function call with no bounds checking
    strcat(database, query);
}

int main() {
    char buffer[1000];

    printf("Enter command: database_name CREATE TABLE users (id INT, name VARCHAR(255));\n");
    fgets(buffer, sizeof(buffer), stdin);
    parse_command(buffer);

    printf("Database modified: %s\n", buffer);

    return 0;
}
