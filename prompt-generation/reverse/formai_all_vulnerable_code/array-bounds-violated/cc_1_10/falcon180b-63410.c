//Falcon-180B DATASET v1.0 Category: Error handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_ERRORS 10

int num_errors = 0;
char error_messages[MAX_NUM_ERRORS][100];
int error_line_numbers[MAX_NUM_ERRORS];

void add_error(int line_num, const char* msg) {
    if (num_errors >= MAX_NUM_ERRORS) {
        fprintf(stderr, "Error: Too many errors, aborting.\n");
        exit(1);
    }
    strncpy(error_messages[num_errors], msg, 100);
    error_line_numbers[num_errors] = line_num;
    num_errors++;
}

void print_errors() {
    if (num_errors == 0) {
        printf("No errors found.\n");
    } else {
        printf("Found %d errors:\n", num_errors);
        for (int i = 0; i < num_errors; i++) {
            printf("%d: %s\n", error_line_numbers[i], error_messages[i]);
        }
    }
}

int is_valid_identifier(const char* str) {
    int len = strlen(str);
    if (len == 0 || len > MAX_LINE_LENGTH) {
        add_error(__LINE__, "Invalid identifier length");
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isalnum(str[i])) {
            add_error(__LINE__, "Invalid identifier character");
            return 0;
        }
    }
    return 1;
}

int main() {
    FILE* fp = fopen("example.c", "r");
    if (fp == NULL) {
        add_error(__LINE__, "Could not open file");
        return 1;
    }
    char line[MAX_LINE_LENGTH];
    int line_num = 1;
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int len = strlen(line);
        if (line[len-1]!= '\n') {
            add_error(__LINE__, "Line too long");
        }
        for (int i = 0; i < len-1; i++) {
            if (line[i] == '\r') {
                add_error(__LINE__, "Invalid line ending");
            }
        }
        if (is_valid_identifier(line)) {
            printf("Line %d is valid.\n", line_num);
        } else {
            printf("Line %d is invalid.\n", line_num);
        }
        line_num++;
    }
    fclose(fp);
    print_errors();
    return 0;
}