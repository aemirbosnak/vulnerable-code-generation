#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file_name> <file_size>\n", argv[0]);
        return 1;
    }

    char filename[BUFFER_SIZE];
    char *fileContent = malloc(atoi(argv[2]) + 1); // Allocate one extra byte for the null terminator
    if (!fileContent) {
        perror("malloc");
        return 1;
    }

    int bytesRead = recv(0, fileContent, atoi(argv[2]), 0); // Read from standard input
    if (bytesRead <= 0) {
        perror("recv");
        free(fileContent);
        return 1;
    }

    strcpy(filename, argv[1]);
    strcat(filename, ".uploaded");

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("fopen");
        free(fileContent);
        return 1;
    }

    fwrite(fileContent, 1, bytesRead, fp);
    fclose(fp);

    // Dereference forgotten memory
    free(fileContent[bytesRead]);

    printf("File saved as %s\n", filename);

    return 0;
}
