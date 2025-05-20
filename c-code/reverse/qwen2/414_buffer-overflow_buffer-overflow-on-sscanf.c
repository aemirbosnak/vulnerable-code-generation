#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

void parse_stat_response(char *response) {
    char status[BUFFER_SIZE];
    int count;
    if (sscanf(response, "+OK %s %d", status, &count) != 2) {
        printf("Failed to parse STAT response\n");
        return;
    }
    printf("Status: %s, Count: %d\n", status, count);
}

void parse_list_response(char *response) {
    char filename[50];
    while (sscanf(response, "%*s %s", filename) == 1) {
        printf("Filename: %s\n", filename);
        // Simulate reading more data from the server
        fgets(response, sizeof(response), stdin);
    }
}

int main() {
    char buffer[100];
    printf("Enter STAT response: ");
    fgets(buffer, sizeof(buffer), stdin);
    parse_stat_response(buffer);

    printf("Enter LIST response: ");
    fgets(buffer, sizeof(buffer), stdin);
    parse_list_response(buffer);

    return 0;
}
