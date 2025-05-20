//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_IP_ADDRESS_LENGTH 16

typedef struct {
    char ip[MAX_IP_ADDRESS_LENGTH];
    int count;
} ip_count;

int main(int argc, char *argv[]) {
    FILE *log_file;
    char line[MAX_LINE_LENGTH];
    char ip_str[MAX_IP_ADDRESS_LENGTH];
    ip_count *ip_list = NULL;
    int ip_list_size = 0;
    int i, j;

    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        perror("Error opening log file");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, log_file) != NULL) {
        // Remove newline character and leading/trailing whitespaces
        size_t newline_pos = strlen(line) - 1;
        while (newline_pos > 0 && isspace((unsigned char)line[newline_pos])) {
            newline_pos--;
        }
        line[newline_pos] = '\0';

        for (i = 0; i < strlen(line) && isspace((unsigned char)line[i]); i++);

        if (i >= strlen(line)) {
            continue;
        }

        strncpy(ip_str, line + i, sizeof(ip_str));
        for (j = 0; j < strlen(ip_str) && ip_str[j] != ':' && ip_str[j] != ' '; j++);
        ip_str[j] = '\0';

        for (i = 0; i < ip_list_size; i++) {
            if (strcmp(ip_list[i].ip, ip_str) == 0) {
                ip_list[i].count++;
                break;
            }
        }

        if (ip_list_size == ip_list_size + 1) {
            ip_count *new_ip = (ip_count *)realloc(ip_list, sizeof(ip_count) * (ip_list_size + 1));
            if (new_ip == NULL) {
                perror("Error allocating memory");
                fclose(log_file);
                free(ip_list);
                return 1;
            }
            ip_list = new_ip;
            strcpy(ip_list[ip_list_size++].ip, ip_str);
            ip_list[ip_list_size - 1].count = 1;
        }
    }

    fclose(log_file);

    for (i = 0; i < ip_list_size; i++) {
        printf("%s: %d\n", ip_list[i].ip, ip_list[i].count);
    }

    free(ip_list);

    return 0;
}