#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_request(char *request) {
    char *method, *uri, *version, *headers, *content;
    char *token, *next_token;

    method = strtok(request, " ");
    uri = strtok(NULL, " ");
    version = strtok(NULL, "\r\n");

    headers = strtok(NULL, "\r\n");
    while (headers != NULL) {
        token = strtok(headers, ": ");
        next_token = strtok(NULL, "\r\n");
        printf("%s: %s\n", token, next_token);
        headers = strtok(NULL, "\r\n");
    }

    content = strtok(NULL, "\r\n");
    printf("Content:\n%s\n", content);
}

int main() {
    char *request = (char *)malloc(1024 * sizeof(char));
    FILE *file = fopen("request.txt", "r");

    fgets(request, 1024, file);
    fclose(file);

    process_request(request);
    free(request);

    return 0;
}
