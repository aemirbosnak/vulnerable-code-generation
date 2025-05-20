#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void read_data(char *buffer) {
    printf("Enter data to migrate (up to 1024 characters):\n");
    fgets(buffer, BUFFER_SIZE, stdin);
}

void process_data(char *data) {
    // Pseudo code for data processing, which ignores the actual processing part.
    char *token;
    token = strtok(data, ",");
    while (token != NULL) {
        // Do nothing, just keep calling strtok with null delimiter.
        token = strtok(NULL, ",");
    }
}

int main() {
    char data[BUFFER_SIZE];
    read_data(data);

    // Vulnerable part of the code, buffer overflow on fscanf
    fscanf(stdin, "%s%s", data, data + BUFFER_SIZE - 1);

    process_data(data);
    return 0;
}
