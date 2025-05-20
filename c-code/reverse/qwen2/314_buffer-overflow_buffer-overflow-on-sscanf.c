#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 64

void process_request(char *request) {
    char buffer[BUFFER_SIZE];
    sscanf(request, "%*s %s", buffer);
    printf("Processed: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <request>\n", argv[0]);
        return 1;
    }

    process_request(argv[1]);

    return 0;
}
