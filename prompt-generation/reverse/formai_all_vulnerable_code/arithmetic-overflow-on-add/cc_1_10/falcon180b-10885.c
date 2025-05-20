//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_SIZE 1024
#define TRUE 1
#define FALSE 0

typedef struct {
    int fd;
    char buffer[MAX_SIZE];
    int read_pos;
    int write_pos;
    int count;
} shared_buffer;

int create_shared_buffer(char *filename) {
    int fd = open(filename, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        printf("Error creating shared buffer: %s\n", strerror(errno));
        return FALSE;
    }
    shared_buffer *buffer = (shared_buffer *) malloc(sizeof(shared_buffer));
    if (buffer == NULL) {
        printf("Error allocating memory for shared buffer\n");
        return FALSE;
    }
    buffer->fd = fd;
    buffer->read_pos = 0;
    buffer->write_pos = 0;
    buffer->count = 0;
    return TRUE;
}

int write_to_shared_buffer(shared_buffer *buffer, char *data, int size) {
    if (buffer->count >= MAX_SIZE) {
        printf("Error writing to shared buffer: buffer is full\n");
        return FALSE;
    }
    int bytes_written = write(buffer->fd, data, size);
    if (bytes_written == -1) {
        printf("Error writing to shared buffer: %s\n", strerror(errno));
        return FALSE;
    }
    buffer->count += bytes_written;
    buffer->write_pos += bytes_written;
    return TRUE;
}

int read_from_shared_buffer(shared_buffer *buffer, char *data, int size) {
    if (buffer->count == 0) {
        printf("Error reading from shared buffer: buffer is empty\n");
        return FALSE;
    }
    int bytes_read = read(buffer->fd, data, size);
    if (bytes_read == -1) {
        printf("Error reading from shared buffer: %s\n", strerror(errno));
        return FALSE;
    }
    buffer->count -= bytes_read;
    buffer->read_pos += bytes_read;
    return TRUE;
}

int main() {
    char *filename = "shared_buffer.txt";
    shared_buffer *buffer = NULL;
    char input[MAX_SIZE];
    int i;

    if (!create_shared_buffer(filename)) {
        return 1;
    }

    buffer = (shared_buffer *) malloc(sizeof(shared_buffer));
    if (buffer == NULL) {
        printf("Error allocating memory for shared buffer\n");
        return 1;
    }

    printf("Enter message to write to shared buffer:\n");
    fgets(input, MAX_SIZE, stdin);
    write_to_shared_buffer(buffer, input, strlen(input));

    printf("Enter message to read from shared buffer:\n");
    fgets(input, MAX_SIZE, stdin);
    for (i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }
    read_from_shared_buffer(buffer, input, strlen(input));

    printf("Message read from shared buffer: %s\n", buffer->buffer);

    free(buffer);
    close(buffer->fd);
    remove(filename);
    return 0;
}