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
    if (ctx == NULL) {
        return NULL;
    }
    ctx->filename = strdup(filename);
    if (ctx->filename == NULL) {
        free(ctx);
        return NULL;
    }
    ctx->file = fopen(ctx->filename, "wb");
    if (ctx->file == NULL) {
        free(ctx->filename);
        free(ctx);
        return NULL;
    }
    return ctx;
}

void destroy_upload_context(UploadContext *ctx) {
    if (ctx != NULL) {
        if (ctx->file != NULL) {
            fclose(ctx->file);
        }
        free(ctx->filename);
        free(ctx);
    }
}

int handle_file_upload(const char *upload_data, size_t data_size, const char *filename) {
    UploadContext *ctx = create_upload_context(filename);
    if (ctx == NULL) {
        fprintf(stderr, "Failed to create upload context\n");
        return -1;
    }

    if (fwrite(upload_data, 1, data_size, ctx->file) != data_size) {
        fprintf(stderr, "Failed to write to file\n");
        destroy_upload_context(ctx);
        return -1;
    }

    destroy_upload_context(ctx);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <data> <filename>\n", argv[0]);
        return 1;
    }

    const char *upload_data = argv[1];
    const char *filename = argv[2];

    int result = handle_file_upload(upload_data, strlen(upload_data), filename);
    if (result != 0) {
        fprintf(stderr, "File upload failed\n");
        return 1;
    }

    printf("File uploaded successfully\n");
    return 0;
}
