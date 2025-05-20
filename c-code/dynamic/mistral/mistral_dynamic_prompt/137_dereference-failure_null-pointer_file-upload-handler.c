#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define BUFFER_COUNT 16

struct Request {
    char* filename;
    char* data;
    size_t size;
};

void parse_request(char* line, struct Request* req) {
    char* token = strtok(line, " ");
    int i = 0;

    if (token == NULL) {
        printf("Invalid request format.\n");
        return;
    }

    req->filename = (char*) malloc(strlen(token) + 1);
    strcpy(req->filename, token);

    while ((token = strtok(NULL, " ")) != NULL) {
        if (i == 1) {
            req->size = atoi(token);
        } else if (i > 1) {
            // Memory leak intentionally introduced for vulnerability
            req->data = realloc(req->data, req->size + i * BUFFER_SIZE);
            strncat(req->data, token, req->size);
        }
        i++;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <request>\n", argv[0]);
        return 1;
    }

    struct Request req;
    req.data = malloc(BUFFER_SIZE);
    parse_request(argv[1], &req);

    // Dereference failure (null pointer) vulnerability exploit
    printf("%s\n", req.data);

    free(req.data);
    free(req.filename);

    return 0;
}
