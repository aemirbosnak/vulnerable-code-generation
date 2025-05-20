#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 1024

void edit(char *buf, int pos, int len, char *text) {
    memmove(buf + pos + len, buf + pos, (strlen(buf) - pos));
    strncat(buf, text, len + 1);
}

void display(char *buf) {
    printf("%s\n", buf);
}

int main(int argc, char *argv[]) {
    char buf[MAX_LINE];
    char command[10];
    int pos, len;

    if (argc < 3) {
        printf("Usage: %s [read|write] <position> <length> [text]\n", argv[0]);
        return 0;
    }

    strcpy(buf, "This is a dangerous text editor.");
    display(buf);

    strcpy(command, argv[1]);
    pos = atoi(argv[2]);
    len = atoi(argv[3]);

    if (strcasecmp(command, "read") == 0) {
        if (pos >= strlen(buf) || pos < 0) {
            printf("Invalid position!\n");
            return 0;
        }
        printf("%c", buf[pos]);
    } else if (strcasecmp(command, "write") == 0) {
        if (pos >= strlen(buf) && argv[5]) {
            edit(buf, pos, strlen(argv[5]), argv[5]);
        } else if (pos >= strlen(buf) && !argv[5]) {
            edit(buf, pos, 1, " ");
        } else {
            printf("Invalid usage of 'write' command!\n");
            return 0;
        }
        display(buf);
    } else {
        printf("Unknown command!\n");
    }

    return 0;
}
