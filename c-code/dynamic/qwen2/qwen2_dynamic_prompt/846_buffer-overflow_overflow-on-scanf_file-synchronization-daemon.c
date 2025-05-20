#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 16

void sync_files(const char *source, const char *destination) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, source);
    strcat(buffer, destination);
}

int main() {
    char src[256], dest[256];

    printf("Enter source file path: ");
    scanf("%s", src);

    printf("Enter destination file path: ");
    scanf("%s", dest);

    sync_files(src, dest);

    return 0;
}
