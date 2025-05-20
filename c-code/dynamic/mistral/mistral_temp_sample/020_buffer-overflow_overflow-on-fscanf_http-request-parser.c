#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void parse_request(char *buffer) {
    char method[8], url[256], version[16];
    char *host, *path, *query;
    int status;

    fscanf(stdin, "%s %s %s\n", method, url, version);

    host = strtok(strtok(url, "?"), " ");
    path = strtok(NULL, " ");
    query = strtok(NULL, "\n");

    printf("Method: %s\n", method);
    printf("URL: %s\n", url);
    printf("Host: %s\n", host);
    printf("Path: %s\n", path);
    printf("Query: %s\n", query);
    printf("HTTP Version: %s\n", version);
}

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];

    printf("HTTP Request Parser\n");
    printf("Enter HTTP request:\n");

    fgets(buffer, BUFFER_SIZE, stdin);
    parse_request(buffer);

    return 0;
}
