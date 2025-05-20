#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void handle_response(char *response) {
    char status[BUFFER_SIZE];
    int num;
    if (sscanf(response, "%s %d", status, &num) == 2) {
        printf("Status: %s, Number: %d\n", status, num);
    } else {
        printf("Invalid response format.\n");
    }
}

int main() {
    char buffer[BUFFER_SIZE];
    fgets(buffer, sizeof(buffer), stdin);
    handle_response(buffer);
    return 0;
}
