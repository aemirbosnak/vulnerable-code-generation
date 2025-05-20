#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void read_input(char* buffer) {
    printf("Enter your database credentials (username password)\n");
    fscanf(stdin, "%s %s", buffer, buffer+strlen(buffer));
}

void process_data(char* data) {
    printf("Processing data: %s\n", data);
    // Do something with the data
}

int main() {
    char user[BUFFER_SIZE], pass[BUFFER_SIZE];
    read_input(user);
    strcat(user, pass); // Concatenate user and pass to overflow the buffer
    process_data(user);
    return 0;
}
