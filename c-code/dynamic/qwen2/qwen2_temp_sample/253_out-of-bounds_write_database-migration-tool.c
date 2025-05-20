#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define BUFFER_SIZE 10

void migrate_data(char *data) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, data);
}

int main() {
    char large_data[20] = "This is a very large string that will overflow the buffer.";
    migrate_data(large_data);
    printf("Data migrated successfully.\n");
    return 0;
}
