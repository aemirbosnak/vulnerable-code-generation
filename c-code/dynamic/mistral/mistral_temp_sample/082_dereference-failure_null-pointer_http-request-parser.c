#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

void parse_http_request(char *buffer) {
    char *method, *url, *version;
    int content_length;
    char *content;

    method = strtok(buffer, " ");
    url = strtok(NULL, " ");
    version = strtok(NULL, "\n");

    if (strcasecmp(method, "GET") != 0) {
        printf("Invalid HTTP method: %s\n", method);
        return;
    }

    content_length = atoi(strtok(NULL, " "));
    content = malloc(content_length);
    strcpy(content, strtok(NULL, "\n"));

    printf("Method: GET\n");
    printf("URL: %s\n", url);
    printf("HTTP Version: %s\n", version);
    printf("Content Length: %d\n", content_length);
    printf("Content:\n%s\n", content);

    free(content);
}

int main(int argc, char *argv[]) {
    char buffer[1024];
    FILE *fp = fopen("request.txt", "r");

    if (!fp) {
        printf("Error: Unable to open request file.\n");
        return 1;
    }

    fgets(buffer, sizeof(buffer), fp);
    parse_http_request(buffer);

    fclose(fp);
    return 0;
}
