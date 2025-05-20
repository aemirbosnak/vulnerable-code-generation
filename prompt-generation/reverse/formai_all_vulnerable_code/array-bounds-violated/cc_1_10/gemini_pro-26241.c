//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>

// Error codes
enum ErrorCodes {
    ERR_OK = 0,
    ERR_INVALID_ARG,
    ERR_NOT_FOUND,
    ERR_OUT_OF_MEMORY,
    ERR_OTHER
};

// Error messages
static const char *error_messages[] = {
    "OK",
    "Invalid argument",
    "Not found",
    "Out of memory",
    "Other"
};

// Error handling context
typedef struct ErrorHandlerContext {
    jmp_buf env;
    int error_code;
} ErrorHandlerContext;

// Set error code and jump to error handler
void throw_error(ErrorHandlerContext *ctx, int error_code) {
    ctx->error_code = error_code;
    longjmp(ctx->env, 1);
}

// Error handler
void error_handler(ErrorHandlerContext *ctx) {
    if (ctx->error_code == ERR_OK) {
        printf("No error occurred.\n");
    } else {
        printf("Error: %s\n", error_messages[ctx->error_code]);
    }
}

// Function that may throw an error
int do_something(int arg) {
    if (arg <= 0) {
        throw_error(NULL, ERR_INVALID_ARG);
    }
    // ... more code
}

// Main function
int main() {
    ErrorHandlerContext ctx;
    int result;

    if (setjmp(ctx.env) != 0) {
        error_handler(&ctx);
        return ctx.error_code;
    }

    // Call function that may throw an error
    result = do_something(10);

    if (ctx.error_code != ERR_OK) {
        error_handler(&ctx);
        return ctx.error_code;
    }

    printf("Result: %d\n", result);
    return 0;
}