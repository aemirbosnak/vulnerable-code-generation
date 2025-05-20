#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase() {
    int *data = NULL;
    data[0] = 1; // Dereference failure: using uninitialized pointer
}

int main() {
    migrateDatabase();
    return 0;
}
