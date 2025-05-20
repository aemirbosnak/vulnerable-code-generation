//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE 1024
#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 64
#define MAX_IP_LEN 16
#define MAX_USER_LEN 64
#define MAX_FILE_LEN 256

typedef struct {
    char ip[MAX_IP_LEN];
    char user[MAX_USER_LEN];
    char file[MAX_FILE_LEN];
} access_t;

void parse_line(char *line, int *count, access_t *access) {
    char *token, *saveptr = NULL;
    int i = 0;

    token = strtok_r(line, " ", &saveptr);
    if (token == NULL) {
        return;
    }

    strncpy(access->ip, token, MAX_IP_LEN);
    i++;

    token = strtok_r(NULL, " ", &saveptr);
    if (token == NULL) {
        return;
    }

    strncpy(access->user, token, MAX_USER_LEN);
    i++;

    token = strtok_r(NULL, " ", &saveptr);
    if (token == NULL) {
        return;
    }

    strncpy(access->file, token, MAX_FILE_LEN);
    i++;

    *count += i;
}

int main() {
    FILE *fp;
    char line[MAX_LINE];
    int count = 0;
    access_t access;

    fp = fopen("access.log", "r");
    if (fp == NULL) {
        printf("Error opening access.log\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        parse_line(line, &count, &access);
    }

    fclose(fp);

    printf("Total accesses: %d\n", count);

    return 0;
}