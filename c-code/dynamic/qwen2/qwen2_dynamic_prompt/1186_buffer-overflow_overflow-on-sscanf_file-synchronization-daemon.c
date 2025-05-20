#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void sync_files(const char *source, const char *destination) {
    char command[256];
    snprintf(command, sizeof(command), "cp -r %s %s", source, destination);
    system(command);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    const char *source = argv[1];
    const char *destination = argv[2];

    // Simulate receiving data from an untrusted source
    char buffer[10];
    printf("Enter source directory: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Vulnerability: No bounds checking on sscanf
    int num_files;
    sscanf(buffer, "%d", &num_files);

    printf("Number of files to sync: %d\n", num_files);

    for (int i = 0; i < num_files; i++) {
        printf("Syncing file %d...\n", i + 1);
        sync_files(source, destination);
    }

    return 0;
}
