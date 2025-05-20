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
    UploadContext *ctx = malloc(sizeof(UploadContext));
    if (!ctx) return NULL;
    ctx->filename = strdup(filename);
    ctx->file = fopen(ctx->filename, "wb");
    if (!ctx->file) {
        free(ctx->filename);
        free(ctx);
        return NULL;
    }
    return ctx;
}

void handle_file_upload(UploadContext *ctx, const char *data, size_t length) {
    if (fwrite(data, 1, length, ctx->file) != length) {
        fprintf(stderr, "Failed to write data to file\n");
    }
}

void cleanup_upload_context(UploadContext *ctx) {
    if (ctx->file) fclose(ctx->file);
    free(ctx->filename);
    free(ctx);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <data>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    const char *data = argv[2];

    UploadContext *ctx = create_upload_context(filename);
    if (!ctx) {
        fprintf(stderr, "Failed to create upload context\n");
        return 1;
    }

    handle_file_upload(ctx, data, strlen(data));

    // Dereference failure (forgotten memory)
    // This is a deliberate mistake to demonstrate a vulnerability
    // Normally, you would call cleanup_upload_context(ctx) here

    return 0;
}
