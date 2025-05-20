#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void parse_request(char *request) {
    char method[MAX_LINE_LENGTH];
    char path[MAX_LINE_LENGTH];
    char version[MAX_LINE_LENGTH];

    sscanf(request, "%s %s %s", method, path, version);

    // Out-of-bounds write vulnerability
    strcpy(method, "GET /admin/delete_all_users HTTP/1.1");
}

int main() {
    char buffer[MAX_LINE_LENGTH];
    printf("Enter an HTTP request: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    parse_request(buffer);

    return 0;
}
