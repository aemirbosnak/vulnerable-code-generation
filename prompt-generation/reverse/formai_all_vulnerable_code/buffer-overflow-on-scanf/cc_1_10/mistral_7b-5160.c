//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_SIZE 1024
#define FILENAME "secretfile.txt"

int main() {
    int fd, ret;
    char password[20], buffer[MAX_SIZE];
    struct stat file_stat;

    printf("\n-----------------------------------\n");
    printf("|          Welcome to the vault   |\n");
    printf("|             v1.0              |\n");
    printf("|________________________________|\n\n");

    printf("Please enter your password: ");
    scanf("%s", password);

    if (strcmp(password, "Admin123$") != 0) {
        printf("\nAccess denied! Incorrect password.\n");
        exit(1);
    }

    fd = open(FILENAME, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }

    ret = fstat(fd, &file_stat);
    if (ret < 0) {
        perror("Error getting file stats");
        close(fd);
        exit(1);
    }

    printf("\nFile %s size: %ld bytes\n", FILENAME, file_stat.st_size);

    lseek(fd, 0, SEEK_SET);
    read(fd, buffer, file_stat.st_size);
    close(fd);

    printf("\nFile contents:\n");
    printf("%s", buffer);

    printf("\n-----------------------------------\n");

    return 0;
}