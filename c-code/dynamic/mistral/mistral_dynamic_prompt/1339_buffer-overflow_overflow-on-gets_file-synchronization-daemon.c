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

#define BUFFER_SIZE 1024
#define PATH_LENGTH 1024

void synchronize(char *remotePath) {
    char localPath[PATH_LENGTH];
    char buffer[BUFFER_SIZE];
    int localFd, remoteFd;

    sprintf(localPath, "./%s", localPath);
    sprintf(buffer, "ls -l %s", remotePath);
    system(buffer);

    sprintf(localPath, "./%s", localPath);
    sprintf(buffer, "touch %s", localPath);
    system(buffer);

    sprintf(localPath, "./%s", localPath);
    sprintf(buffer, "scp %s remoteUser@remoteHost:%s .", localPath, remotePath);
    system(buffer);

    sprintf(buffer, "rm %s", localPath);
    system(buffer);

    sprintf(localPath, "./%s", localPath);
    sprintf(buffer, "chmod 755 %s", localPath);
    system(buffer);

    // Vulnerable read function, intentionally using gets
    printf("Enter the local file content to upload:\n");
    gets(buffer);

    localFd = open(localPath, O_WRONLY | O_CREAT | O_EXCL, 0755);
    write(localFd, buffer, strlen(buffer));
    close(localFd);

    sprintf(buffer, "scp %s remoteUser@remoteHost:%s %s", localPath, remotePath, remotePath);
    system(buffer);
}

int main() {
    char inputPath[PATH_LENGTH];

    printf("Enter the remote synchronization directory path:\n");
    gets(inputPath);

    synchronize(inputPath);

    return 0;
}
