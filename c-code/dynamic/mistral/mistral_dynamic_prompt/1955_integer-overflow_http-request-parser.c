#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];
    char host[256];
    char path[256];
    char method[8];

    printf("Parse HTTP request\n");

    // read HTTP request from stdin
    size_t n = fread(buffer, sizeof(char), BUFFER_SIZE, stdin);
    buffer[n] = '\0'; // null terminate the buffer

    // parse HTTP request
    sscanf(buffer, "%s %s %s", method, host, path);

    // manipulate the host buffer to cause an integer overflow
    size_t host_length = strlen(host);
    host[host_length] = '\n'; // add a newline character

    // create a large integer and access the host buffer through it
    int big_int = 0;
    int* host_ptr = (int*)&big_int;
    host_ptr[0] = atoi(host) + 1; // increment the host integer value

    printf("Method: %s\n", method);
    printf("Host: %d\n", host_ptr[0]); // prints the integer value that overflows into the host buffer
    printf("Path: %s\n", path);

    return 0;
}
