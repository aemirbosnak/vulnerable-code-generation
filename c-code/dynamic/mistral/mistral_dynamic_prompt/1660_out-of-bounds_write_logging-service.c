#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void log_entry(const char *user, const char *message) {
    char log_file[] = "log.txt";
    FILE *fp = fopen(log_file, "a");
    if (fp == NULL) {
        printf("Error opening log file.\n");
        return;
    }

    fprintf(fp, "%s: %s\n", user, message);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: ./logging_service username log_level message\n");
        return 1;
    }

    char *user = argv[1];
    char *log_level = argv[2];
    char *message = argv[3];

    char log_message[BUFFER_SIZE];
    strcpy(log_message, user);
    strcat(log_message, ": ");
    strcat(log_message, log_level);
    strcat(log_message, ": ");
    strcat(log_message, message);

    char *fmt_str = "%d bytes written to log_message.\n";
    char temp[BUFFER_SIZE + 10];
    sprintf(temp, fmt_str, strlen(log_message) + strlen(user) + strlen(log_level) + strlen(message) + 9); // 9 = length of ": " and "." in fmt_str

    printf(temp);
    log_entry(user, message);

    return 0;
}
