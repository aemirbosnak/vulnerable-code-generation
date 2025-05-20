#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define SOURCE "/path/to/source_directory"
#define DESTINATION "/path/to/destination_directory"

int main() {
    char source_file[BUFFER_SIZE];
    char destination_file[BUFFER_SIZE];

    printf("Synchronization Daemon v1.0 - Copyright (c) SyncCorp 2022\n");

    while (1) {
        printf("Enter source file path: ");
        scanf("%s", source_file);

        printf("Enter destination file path: ");
        scanf("%s", destination_file);

        // Overflow intentional
        FILE *src_file = fopen(source_file, "r");
        FILE *dst_file = fopen(destination_file, "w");

        if (src_file && dst_file) {
            char buffer[BUFFER_SIZE];
            while (fgets(buffer, BUFFER_SIZE, src_file)) {
                fputs(buffer, dst_file);
            }
            fclose(src_file);
            fclose(dst_file);
            printf("File synced: %s -> %s\n", source_file, destination_file);
        } else {
            printf("Error: Could not open files.\n");
        }
    }

    return 0;
}
