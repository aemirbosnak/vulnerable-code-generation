//Falcon-180B DATASET v1.0 Category: Error handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <setjmp.h>

#define MAX_ERRORS 10

typedef struct {
    jmp_buf env;
    int errors[MAX_ERRORS];
    int error_count;
} ErrorContext;

void error_occurred(ErrorContext *ctx, const char *format,...) {
    va_list args;
    va_start(args, format);
    vsnprintf(ctx->errors[ctx->error_count], sizeof(ctx->errors[0]), format, args);
    ctx->error_count++;
    if (ctx->error_count >= MAX_ERRORS) {
        ctx->error_count = MAX_ERRORS - 1;
    }
    va_end(args);
    longjmp(ctx->env, 1);
}

void print_errors(ErrorContext *ctx) {
    for (int i = 0; i < ctx->error_count; i++) {
        printf("Error %d: %s\n", i + 1, ctx->errors[i]);
    }
}

int main() {
    ErrorContext ctx;
    if (setjmp(ctx.env)!= 0) {
        print_errors(&ctx);
        return 1;
    }

    FILE *file = fopen("nonexistent_file.txt", "r");
    if (file == NULL) {
        error_occurred(&ctx, "Failed to open file: %s", "nonexistent_file.txt");
    }

    char buffer[10];
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        error_occurred(&ctx, "Failed to read from file: %s", "nonexistent_file.txt");
    }

    fclose(file);

    return 0;
}