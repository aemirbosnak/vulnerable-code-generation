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
    strncpy(ctx->filename, data, length);
    ctx->filename[length] = '\0';

    // Simulate file opening
    ctx->file = fopen(ctx->filename, "wb");
    if (!ctx->file) {
        perror("Failed to open file");
        return;
    }

    // Deliberate null pointer dereference vulnerability
    fwrite(data + length, 1, length, NULL); // This line is malicious

    fclose(ctx->file);
}

int main() {
    UploadContext ctx;
    char buffer[1024];

    printf("Enter filename: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    printf("Enter file content: ");
    fgets(buffer, sizeof(buffer), stdin);

    handle_upload(&ctx, buffer, strlen(buffer));

    return 0;
}
