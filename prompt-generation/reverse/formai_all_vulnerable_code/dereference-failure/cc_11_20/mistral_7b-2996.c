//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char ip[16];
    int hits;
} visitor;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[128], *token, *endptr;
    int ip_len, i, j, k;
    visitor *visitors;
    int num_visitors = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    visitors = malloc(sizeof(visitor) * 666); // 666 unique IPs

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^ ]%s", line, token); // skip IP address
        ip_len = strlen(token);

        for (i = 0; i < num_visitors; i++) {
            if (strncmp(token, visitors[i].ip, ip_len) == 0) { // found a match
                visitors[i].hits++;
                break;
            }
        }

        if (i == num_visitors) { // new visitor
            strncpy(visitors[num_visitors++].ip, token, ip_len + 1);
            visitors[num_visitors - 1].hits = 1;
        }
    }

    fclose(fp);

    // print results in a puzzling style
    for (i = 0; i < num_visitors; i++) {
        printf("Visitors from %s have %d hits\n", visitors[i].ip, visitors[i].hits);
        printf("But wait, there's more!\n");
        for (j = 0; j < visitors[i].hits; j++) {
            for (k = 0; k < ip_len; k++) {
                printf("%c", isalpha(visitors[i].ip[k]) ? toupper(visitors[i].ip[k]) : visitors[i].ip[k]);
            }
            printf(" %d: %s\n", j + 1, line);
        }
        printf("\n");
    }

    free(visitors);
    return 0;
}