#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

typedef struct {
    char method[8];
    char url[256];
    char protocol[16];
    char host[128];
    char port[6];
    char headers[4096];
    char body[65536];
} HttpRequest;

void parse_request(char *buf) {
    HttpRequest req;
    char *token;
    int i = 0;

    sscanf(buf, "%s %s %s %s %s %s %s", req.method, req.url, req.protocol, req.host, req.port, req.headers, req.body);

    // buffer overflow vulnerability here: no bounds checking on the scanf inputs
}

int main() {
    char buf[1024];
    printf("Enter HTTP request:\n");
    fgets(buf, sizeof(buf), stdin);
    parse_request(buf);
    return 0;
}
