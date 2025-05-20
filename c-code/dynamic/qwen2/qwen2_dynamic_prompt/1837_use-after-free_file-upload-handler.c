#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

typedef struct {
    char *filename;
    FILE *file;
} UploadContext;

UploadContext* create_upload_context(const char *filename) {
    UploadContext *ctx = (UploadContext*)malloc(sizeof(UploadContext));
    ctx->filename = strdup(filename);
    ctx->file = fopen(ctx->filename, "w");
    return ctx;
}

void handle_file_upload(UploadContext *ctx, const char *data, size_t length) {
    if (fwrite(data, 1, length, ctx->file) != length) {
        perror("Failed to write to file");
    }
}

void close_upload_context(UploadContext *ctx) {
    fclose(ctx->file);
    free(ctx->filename);
    // Deliberate use after free vulnerability
    printf("%s\n", ctx->filename); // Use after free
    free(ctx);
}

int main() {
    UploadContext *ctx = create_upload_context("example.txt");
    const char *upload_data = "Hello, world!";
    handle_file_upload(ctx, upload_data, strlen(upload_data));
    close_upload_context(ctx);
    return 0;
}
