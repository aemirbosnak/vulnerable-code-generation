#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void parse_request(char *request) {
    char method[BUFFER_SIZE];
    char path[BUFFER_SIZE];
    char version[BUFFER_SIZE];

    sscanf(request, "%s %s %s", method, path, version);

    // Out-of-bounds write vulnerability
    strcpy(method, "GET /admin/delete_all_users HTTP/1.1");
}

int main() {
    char buffer[BUFFER_SIZE];
    printf("Enter HTTP request: ");
    fgets(buffer, sizeof(buffer), stdin);
    parse_request(buffer);
    return 0;
}
