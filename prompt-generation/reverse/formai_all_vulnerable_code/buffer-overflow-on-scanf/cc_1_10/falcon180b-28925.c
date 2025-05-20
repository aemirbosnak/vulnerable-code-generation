//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000
#define MIN_SIZE 10

typedef struct {
    char data[MAX_SIZE];
    int size;
} Buffer;

void init_buffer(Buffer *buffer) {
    buffer->size = 0;
}

void add_to_buffer(Buffer *buffer, char *data, int size) {
    if (buffer->size + size > MAX_SIZE) {
        printf("Buffer overflow! ");
        return;
    }
    memcpy(buffer->data + buffer->size, data, size);
    buffer->size += size;
}

void print_buffer(Buffer *buffer) {
    printf("Buffer: ");
    for (int i = 0; i < buffer->size; i++) {
        printf("%c", buffer->data[i]);
    }
    printf("\n");
}

int main() {
    char log_file[100];
    printf("Enter log file name: ");
    scanf("%s", log_file);

    FILE *fp = fopen(log_file, "r");
    if (fp == NULL) {
        printf("Error opening file! ");
        return 1;
    }

    Buffer buffer;
    init_buffer(&buffer);

    char line[MAX_SIZE];
    while (fgets(line, MAX_SIZE, fp)!= NULL) {
        int size = strlen(line);
        if (size < MIN_SIZE) {
            printf("Line too short! ");
            continue;
        }
        add_to_buffer(&buffer, line, size);
    }

    fclose(fp);

    printf("Log file analysis:\n");
    printf("Total number of lines: %d\n", buffer.size / MAX_SIZE);
    printf("Average line length: %d\n", buffer.size / MAX_SIZE);

    return 0;
}