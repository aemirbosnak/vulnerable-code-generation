#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <ctype.h>

void parse_http_request(char *buffer) {
    char method[10];
    char url[256];
    char version[16];
    char headers[4096];
    char body[65536];
    int len;

    // HTTP request format:
    // <method> <URL> HTTP/<version>
    // <headers>\r\n<body>

    len = sscanf(buffer, "%s %s %s\n%[^\n]%s", method, url, version, headers, body);
    if (len != 4) {
        printf("Invalid HTTP request format.\n");
        return;
    }

    // Example of a buffer overflow by manipulating the URL
    char ip_address[16];
    sscanf(url, "%15s %*s", ip_address);
    strcat(ip_address, "\x00\x01\x02"); // Replace with any arbitrary data

    printf("Method: %s\n", method);
    printf("URL: %s\n", url);
    printf("Version: %s\n", version);
    printf("Headers: %s\n", headers);
    printf("Body: %s\n", body);
    printf("IP address: %s\n", ip_address);
}

int main() {
    char buffer[65536];

    printf("Enter an HTTP request:\n");
    fgets(buffer, sizeof(buffer), stdin);

    parse_http_request(buffer);

    return 0;
}
