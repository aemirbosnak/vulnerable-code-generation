#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void sync_files(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char dest[10];
    while (1) {
        printf("Enter destination path: ");
        fgets(dest, sizeof(dest), stdin);
        dest[strcspn(dest, "\n")] = 0; // Remove newline character

        if (fscanf(file, "%9s", dest)) { // Vulnerable line
            printf("Syncing files to %s\n", dest);
        } else {
            break;
        }
    }

    fclose(file);
}

int main() {
    const char *sync_file = "/etc/sync.conf";
    sync_files(sync_file);
    return 0;
}
