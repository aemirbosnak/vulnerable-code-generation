#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void sync_files(const char *source, const char *destination) {
    char command[256];
    snprintf(command, sizeof(command), "cp %s %s", source, destination);
    system(command);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    const char *source = argv[1];
    const char *destination = argv[2];

    // Vulnerable code that can lead to buffer overflow
    char buffer[10];
    sscanf(source, "%9s", buffer);

    printf("Synchronizing files from %s to %s\n", buffer, destination);
    sync_files(buffer, destination);

    return 0;
}
