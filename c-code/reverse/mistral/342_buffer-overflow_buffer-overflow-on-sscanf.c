#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void query_database(char *query) {
    char record[BUFFER_SIZE];
    char key[BUFFER_SIZE];
    char value[BUFFER_SIZE];

    sscanf(query, "key=%s value=%s", key, value);

    // Simulate database query and response
    sprintf(record, "Record for %s: %s", key, value);
    printf("%s\n", record);
}

int main() {
    char query[BUFFER_SIZE];

    printf("Enter query: ");
    fgets(query, BUFFER_SIZE, stdin);

    query_database(query);

    return 0;
}
