#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void log_message(char *buf, int size) {
    FILE *fp = fopen("messages.log", "a");
    if (fp == NULL) {
        perror("Error opening log file");
        return;
    }

    fprintf(fp, "[%s]\n", buf);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    char buffer[10];

    if (argc < 2) {
        printf("Usage: ./logging_service <message>\n");
        return 1;
    }

    if (fscanf(stdin, "%s", buffer) != 1) {
        perror("Error reading message");
        return 1;
    }

    printf("Message received: %s\n", buffer);

    // Intentionally overflowing the buffer to demonstrate a buffer overflow vulnerability
    strcpy(buffer, argv[1]);
    log_message(buffer, sizeof(buffer));

    return 0;
}
