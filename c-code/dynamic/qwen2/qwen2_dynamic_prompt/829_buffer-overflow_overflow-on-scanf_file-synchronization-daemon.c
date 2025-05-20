#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void sync_files(const char *source, const char *destination) {
    char buffer[BUFFER_SIZE];
    printf("Synchronizing files from %s to %s\n", source, destination);
    printf("Enter the path of the source file: ");
    scanf("%s", buffer); // Vulnerability here
    printf("Source file path: %s\n", buffer);
}

int main() {
    const char *source = "/path/to/source";
    const char *destination = "/path/to/destination";
    sync_files(source, destination);
    return 0;
}
