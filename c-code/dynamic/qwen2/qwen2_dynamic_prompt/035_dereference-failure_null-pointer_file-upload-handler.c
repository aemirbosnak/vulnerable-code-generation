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

void handleUpload(UploadContext *ctx) {
    if (ctx == NULL) {
        fprintf(stderr, "Error: Context is null\n");
        return;
    }

    // Simulate file opening
    ctx->file = fopen(ctx->filename, "w");
    if (ctx->file == NULL) {
        perror("Failed to open file");
        return;
    }

    // Simulate data write
    const char *data = "This is a test file content.";
    size_t bytesWritten = fwrite(data, 1, strlen(data), ctx->file);
    if (bytesWritten != strlen(data)) {
        perror("Failed to write to file");
    } else {
        printf("File uploaded successfully: %s\n", ctx->filename);
    }

    // Intentional dereference failure
    fclose(NULL); // Dereferencing a null pointer

    // Clean up
    if (ctx->file != NULL) {
        fclose(ctx->file);
    }
}

int main() {
    UploadContext ctx;
    strcpy(ctx.filename, "test.txt");

    handleUpload(&ctx);

    return 0;
}
