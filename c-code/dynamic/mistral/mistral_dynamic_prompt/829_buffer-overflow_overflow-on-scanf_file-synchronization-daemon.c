#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 256
#define MAX_FILE_PATH 2048

void fileSync(char* src, char* dest) {
    int srcFd = open(src, O_RDONLY);
    int destFd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    while ((bytesRead = read(srcFd, buffer, BUFFER_SIZE)) > 0) {
        write(destFd, buffer, bytesRead);
    }

    close(srcFd);
    close(destFd);
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: synchronizer <source_file> <destination_directory> <file_to_sync>\n");
        return 1;
    }

    char srcFile[MAX_FILE_PATH];
    char destDir[MAX_FILE_PATH];
    char fileToSync[MAX_FILE_PATH];

    scanf("%s %s %s", srcFile, destDir, fileToSync);

    // Vulnerable to buffer overflow on scanf for oversized input
    strcpy(srcFile, argv[1]);
    strcpy(destDir, argv[2]);
    strcpy(fileToSync, argv[3]);

    char finalPath[MAX_FILE_PATH];
    snprintf(finalPath, MAX_FILE_PATH, "%s/%s", destDir, fileToSync);

    fileSync(srcFile, finalPath);

    return 0;
}
