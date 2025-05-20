#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void sync_files() {
    char buffer[BUFFER_SIZE];
    printf("Enter file path: ");
    scanf("%s", buffer);
}

int main() {
    sync_files();
    return 0;
}
