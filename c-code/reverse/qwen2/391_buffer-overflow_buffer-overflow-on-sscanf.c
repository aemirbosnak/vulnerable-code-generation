#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <start-port-end-port>\n", argv[0]);
        return 1;
    }

    const char *port_range = argv[1];
    char *end_port_str;
    int start_port = strtol(port_range, &end_port_str, 10);

    if (*end_port_str == '-') {
        int end_port = strtol(end_port_str + 1, NULL, 10);
        printf("Start Port: %d\nEnd Port: %d\n", start_port, end_port);
    } else {
        fprintf(stderr, "Invalid port range format.\n");
        return 1;
    }

    return 0;
}
