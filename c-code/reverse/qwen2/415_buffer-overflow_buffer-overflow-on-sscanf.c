#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void parse_response(char *response) {
    char status[BUFFER_SIZE];
    int message_count;
    if (sscanf(response, "+OK %s %d", status, &message_count) == 2) {
        printf("Status: %s\n", status);
        printf("Message Count: %d\n", message_count);
        for (int i = 0; i < message_count; i++) {
            char msg[BUFFER_SIZE];
            if (sscanf(response, "%*s %*d %s", msg) == 1) {
                printf("Message %d: %s\n", i + 1, msg);
            }
        }
    } else {
        printf("Failed to parse response.\n");
    }
}

int main() {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, "+OK LIST 5\r\n1 FETCH 1 (FLAGS (\Deleted))\r\n2 FETCH 2 (FLAGS ())\r\n3 FETCH 3 (FLAGS ())\r\n4 FETCH 4 (FLAGS ())\r\n5 FETCH 5 (FLAGS ())\r\n");

    while (buffer[0] != '\0') {
        char *pos = strchr(buffer, '\n');
        if (pos != NULL) {
            *pos = '\0';
            parse_response(buffer);
            memmove(buffer, pos + 1, strlen(pos + 1) + 1);
        } else {
            break;
        }
    }

    return 0;
}
