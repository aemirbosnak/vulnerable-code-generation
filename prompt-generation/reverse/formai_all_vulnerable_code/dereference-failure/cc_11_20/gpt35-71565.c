//FormAI DATASET v1.0 Category: Log analysis ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("logfile.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file");
        return 1;
    }

    // Initializing variables
    char* addr = NULL;
    int count = 0;
    int status = 0;
    char* target = "127.0.0.1";
    char* error_msg = "Something wrong happened";

    while ((read = getline(&line, &len, fp)) != -1) {
        // Counting number of times localhost is accessed
        if (strstr(line, target) != NULL) {
            count++;
            if (status == 0) {
                status = 1;
            }
        }

        // Checking for a specific error message
        if (strstr(line, error_msg) != NULL && strstr(line, target) != NULL) {
            if (status == 1) {
                printf("Error: Issue detected on localhost\n");
                status = 2;
            }
        }

        // Extracting memory addresses from the log
        if (strchr(line, '(') != NULL && strchr(line, ')') != NULL) {
            char* c = strtok(line, "(");
            while (c != NULL) {
                if (strstr(c, "0x") != NULL) {
                    addr = c;
                    break;
                }
                c = strtok(NULL, "(");
            }
        }
    }

    // Printing results
    printf("Total local host access: %d\n", count);
    if (status == 2) {
        printf("Error detected on localhost\n");
    }
    if (addr != NULL) {
        printf("Memory Address: %s\n", addr);
    }

    fclose(fp);
    if (line) {
        free(line);
    }
    return 0;
}