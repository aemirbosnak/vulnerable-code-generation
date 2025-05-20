//Falcon-180B DATASET v1.0 Category: Error handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_ERRORS 10

typedef struct {
    char *filename;
    int line_num;
    char *msg;
} Error;

static Error errors[MAX_ERRORS];
static int num_errors = 0;

void add_error(char *filename, int line_num, char *msg) {
    if (num_errors >= MAX_ERRORS) {
        fprintf(stderr, "Error: Too many errors.\n");
        exit(1);
    }

    errors[num_errors].filename = filename;
    errors[num_errors].line_num = line_num;
    errors[num_errors].msg = msg;
    num_errors++;
}

void print_errors() {
    if (num_errors == 0) {
        printf("No errors found.\n");
        return;
    }

    printf("Found %d errors:\n", num_errors);
    for (int i = 0; i < num_errors; i++) {
        printf(" - %s:%d: %s\n", errors[i].filename, errors[i].line_num, errors[i].msg);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    char line[MAX_LINE_LEN];
    int line_num = 1;
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        int len = strlen(line);
        if (line[len - 1]!= '\n') {
            add_error(argv[1], line_num, "Line too long.");
            break;
        }

        for (int i = 0; i < len - 1; i++) {
            if (!isprint(line[i])) {
                add_error(argv[1], line_num, "Invalid character in line.");
                break;
            }
        }

        line_num++;
    }

    fclose(fp);
    print_errors();
    return 0;
}