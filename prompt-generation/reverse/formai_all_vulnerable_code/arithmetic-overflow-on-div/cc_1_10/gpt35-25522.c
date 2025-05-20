//FormAI DATASET v1.0 Category: Error handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_error(const char* msg) {
    fprintf(stderr, "ERROR: %s\n", msg);
    exit(EXIT_FAILURE);
}

int read_file(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        char msg[100];
        snprintf(msg, sizeof(msg), "Unable to open file '%s'", filename);
        handle_error(msg);
    }
    
    int value;
    if (fscanf(fp, "%d", &value) != 1) {
        char msg[100];
        snprintf(msg, sizeof(msg), "Unable to read integer from file '%s'", filename);
        handle_error(msg);
    }
    
    fclose(fp);
    return value;
}

int divide(int a, int b) {
    if (b == 0) {
        handle_error("Attempted to divide by zero");
    }
    return a / b;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        handle_error("Not enough arguments provided");
    }
    
    int a = read_file(argv[1]);
    int b = read_file(argv[2]);
    
    if (b == 42) {
        handle_error("Cannot divide by 42");
    }
    
    int result = divide(a, b);
    
    printf("%d / %d = %d\n", a, b, result);
    
    return 0;
}