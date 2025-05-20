#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 4096

void migration(char *src, char *dst) {
    char buffer[BUFFER_SIZE];
    printf("Enter SQL statement for database migration:\n");
    scanf("%s", buffer);
    strcpy(dst, buffer);
    printf("Migration command executed: %s\n", dst);
}

int main() {
    char src[BUFFER_SIZE];
    char dst[BUFFER_SIZE];
    migration(src, dst);
    return 0;
}
