#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_BUFFER 1024

void sync_files(char *local_path, char *remote_path) {
    FILE *local_file, *remote_file;
    char buffer[MAX_BUFFER];

    local_file = fopen(local_path, "r");
    if (local_file == NULL) {
        perror("Error opening local file");
        return;
    }

    remote_file = fopen(remote_path, "w");
    if (remote_file == NULL) {
        perror("Error opening remote file");
        fclose(local_file);
        return;
    }

    printf("Syncing file...\n");

    while (fgets(buffer, MAX_BUFFER, local_file) != NULL) {
        fputs(buffer, remote_file);
    }

    fclose(local_file);
    fclose(remote_file);

    printf("File synchronization successful.\n");
}

int main(int argc, char *argv[]) {
    char local_path[256], remote_path[256];

    printf("SyncDaemon v1.0\n");
    printf("Usage: SyncDaemon <local_path> <remote_path>\n");

    if (argc != 3) {
        printf("Error: Incorrect arguments\n");
        return 1;
    }

    strcpy(local_path, argv[1]);
    strcpy(remote_path, argv[2]);

    sync_files(local_path, remote_path);

    return 0;
}
