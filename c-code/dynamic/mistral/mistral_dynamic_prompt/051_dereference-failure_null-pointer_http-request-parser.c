#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void parse_request(char *buffer) {
    char *method, *path, *http_version;
    char *get_token(char *str, char *token) {
        char *start = strchr(str, *token);
        if (!start) return NULL;
        char *end = strchr(start + 1, *token);
        if (!end) return start;
        return strchr(end + 1, '\0');
    }

    method = get_token(buffer, ' ') + 1;
    path = get_token(NULL, '\n');
    http_version = get_token(NULL, '\n');

    printf("Method: %s\n", method);
    printf("Path: %s\n", path);
    printf("HTTP Version: %s\n", http_version);

    // Dereference null pointer deliberately
    char *non_existent_field = get_token(NULL, ':');
    printf("Value of non-existent field: %s\n", non_existent_field);
}

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <HTTP request>\n", argv[0]);
        return 1;
    }

    strncpy(buffer, argv[1], BUFFER_SIZE - 1);
    buffer[BUFFER_SIZE - 1] = '\0';

    parse_request(buffer);
    return 0;
}
