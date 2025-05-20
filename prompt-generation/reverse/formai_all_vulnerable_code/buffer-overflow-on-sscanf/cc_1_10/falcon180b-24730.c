//Falcon-180B DATASET v1.0 Category: Error handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ERROR_LENGTH 1024
#define MAX_NUM_ERRORS 10

typedef struct {
    char *file_name;
    int line_num;
    char *error_msg;
} Error;

int num_errors = 0;
Error errors[MAX_NUM_ERRORS];

void add_error(char *file_name, int line_num, char *error_msg) {
    if (num_errors == MAX_NUM_ERRORS) {
        printf("Error: Too many errors, cannot add more.\n");
        return;
    }

    errors[num_errors].file_name = strdup(file_name);
    errors[num_errors].line_num = line_num;
    errors[num_errors].error_msg = strdup(error_msg);

    num_errors++;
}

void print_errors() {
    if (num_errors == 0) {
        printf("No errors found.\n");
        return;
    }

    printf("Errors found:\n");
    for (int i = 0; i < num_errors; i++) {
        printf("File: %s\nLine: %d\nError: %s\n", errors[i].file_name, errors[i].line_num, errors[i].error_msg);
    }
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char error_msg[MAX_ERROR_LENGTH];
    char file_name[MAX_LINE_LENGTH];

    fp = fopen("example.c", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    int line_num = 1;
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (strstr(line, "error")!= NULL) {
            if (sscanf(line, "Error: %[^\n]", error_msg) == 1) {
                sprintf(file_name, "example.c");
                add_error(file_name, line_num, error_msg);
            }
        }
        line_num++;
    }

    fclose(fp);

    print_errors();

    return 0;
}