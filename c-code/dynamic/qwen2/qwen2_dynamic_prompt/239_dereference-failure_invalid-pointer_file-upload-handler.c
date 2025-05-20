#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    FILE *file;
} UploadContext;

void handle_upload(UploadContext *ctx, const char *data, size_t length) {
    if (length > MAX_FILENAME_LENGTH - 1) {
        fprintf(stderr, "Filename too long\n");
        return;
    }
    strncpy(ctx->filename, data, MAX_FILENAME_LENGTH);
    ctx->filename[MAX_FILENAME_LENGTH - 1] = '\0';

    // Simulate file opening
    ctx->file = fopen(ctx->filename, "wb");
    if (!ctx->file) {
        perror("Failed to open file");
        return;
    }

    // Deliberate dereference failure: invalid pointer
    fwrite(data + length, 1, 1, NULL); // Invalid pointer here

    fclose(ctx->file);
}

int main() {
    UploadContext ctx;
    memset(&ctx, 0, sizeof(ctx));

    const char *upload_data = "example.txt";
    size_t upload_length = strlen(upload_data);

    handle_upload(&ctx, upload_data, upload_length);

    return 0;
}
