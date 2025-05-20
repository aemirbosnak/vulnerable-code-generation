//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define KEY 3
#define FILE_NAME_LENGTH 100
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <encrypt|decrypt> <file>\n", argv[0]);
        return 1;
    }

    char mode = argv[1][0];
    char file_name[FILE_NAME_LENGTH];
    strcpy(file_name, argv[2]);

    int fd = open(file_name, O_RDWR);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    if (mode == 'e') { // Encrypt
        printf("Encrypting %s...\n", file_name);
        lseek(fd, 0, SEEK_SET); // Go to the beginning of the file

        while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
            for (int i = 0; buffer[i] != '\0'; i++) {
                if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                    buffer[i] = ((buffer[i] - 'A' + KEY) % 26) + 'A';
                } else if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                    buffer[i] = ((buffer[i] - 'a' + KEY) % 26) + 'a';
                }
            }
            write(fd, buffer, bytes_read);
        }

        printf("File encrypted successfully.\n");
    } else if (mode == 'd') { // Decrypt
        printf("Decrypting %s...\n", file_name);
        lseek(fd, 0, SEEK_SET); // Go to the beginning of the file

        char decrypted_buffer[BUFFER_SIZE];
        while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
            for (int i = 0; buffer[i] != '\0'; i++) {
                if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                    decrypted_buffer[i] = ((buffer[i] - 'A' - KEY + 26) % 26) + 'A';
                } else if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                    decrypted_buffer[i] = ((buffer[i] - 'a' - KEY + 26) % 26) + 'a';
                } else {
                    decrypted_buffer[i] = buffer[i];
                }
            }
            write(STDOUT_FILENO, decrypted_buffer, bytes_read);
        }

        printf("File decrypted successfully.\n");
    } else {
        printf("Invalid mode. Use 'e' for encrypt or 'd' for decrypt.\n");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}