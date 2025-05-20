#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define HEADER_KEY_LEN 32
#define VALUE_LEN (MAX_LINE_LEN - HEADER_KEY_LEN - 3)

void parse_http_request(char* line) {
    char header_key[HEADER_KEY_LEN], value[VALUE_LEN];
    int count;

    sscanf(line, "%s %s", header_key, value);

    printf("Header Key: %s\n", header_key);
    printf("Header Value: %s\n");
    strcat(value, "\000");
    strcat(value, "Attacker's Input");
    strcat(value, "\000");

    printf("Modified Header Value: %s\n", value);
}

int main() {
    char request[MAX_LINE_LEN];

    printf("Enter HTTP request:\n");
    fgets(request, MAX_LINE_LEN, stdin);

    parse_http_request(request);

    return 0;
}
