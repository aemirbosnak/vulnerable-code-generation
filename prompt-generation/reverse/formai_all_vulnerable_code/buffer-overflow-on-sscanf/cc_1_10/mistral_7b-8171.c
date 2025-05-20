//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_MAX 4096
#define IP_ADDR_LEN 16

typedef struct {
    char ip[IP_ADDR_LEN];
    int count;
} ip_stats_t;

int main() {
    FILE *fp;
    char line[LINE_MAX];
    char token[IP_ADDR_LEN];
    ip_stats_t *ip_stats;
    int ip_count = 0;

    fp = fopen("access.log", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    ip_stats = calloc(1, sizeof(ip_stats_t));
    if (ip_stats == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, LINE_MAX, fp) != NULL) {
        sscanf(line, "%s%s", token, token + strlen(token) + 1);
        if (strlen(token) < IP_ADDR_LEN || strlen(token) > IP_ADDR_LEN) {
            continue;
        }

        int index = 0;
        for (; index < ip_count; index++) {
            if (strcmp(ip_stats[index].ip, token) == 0) {
                ip_stats[index].count++;
                break;
            }
        }

        if (index == ip_count) {
            ip_stats[ip_count++] = (ip_stats_t) { strcpy(ip_stats[ip_count - 1].ip, token), 1 };
        }
    }

    fclose(fp);

    printf("IP Address\tCount\n");
    for (int i = 0; i < ip_count; i++) {
        printf("%s\t%d\n", ip_stats[i].ip, ip_stats[i].count);
    }

    free(ip_stats);
    return 0;
}