#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char response[10];
    int file_size;

    printf("Enter file size: ");
    fgets(response, sizeof(response), stdin);
    sscanf(response, "%d", &file_size);

    char buffer[file_size + 1];
    strcpy(buffer, "A");

    return 0;
}
