//Falcon-180B DATASET v1.0 Category: Error handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <setjmp.h>

typedef struct {
    jmp_buf env;
    int code;
} error_t;

void error_init(error_t *err) {
    if (setjmp(err->env) == 0) {
        err->code = 0;
    }
}

void error_throw(error_t *err, int code, const char *fmt,...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    longjmp(err->env, code);
}

void error_catcher(error_t *err) {
    if (err->code!= 0) {
        fprintf(stderr, "Error: %d\n", err->code);
        exit(1);
    }
}

int main() {
    error_t err;
    error_init(&err);

    FILE *file = fopen("nonexistent_file.txt", "r");
    if (file == NULL) {
        error_throw(&err, 1, "Failed to open file: %s", "nonexistent_file.txt");
    }

    int num = 0;
    if (fscanf(file, "%d", &num)!= 1) {
        error_throw(&err, 2, "Invalid data in file: %s", "nonexistent_file.txt");
    }

    fclose(file);

    error_catcher(&err);

    return 0;
}