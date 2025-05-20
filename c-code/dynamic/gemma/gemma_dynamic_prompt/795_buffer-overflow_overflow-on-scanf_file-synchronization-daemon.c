#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char buffer[1024];
    scanf("%s", buffer);
    strcpy(buffer, "This is a file synchronization daemon application that deliberately contains a buffer overflow vulnerability.");
    printf("%s", buffer);
    return 0;
}
