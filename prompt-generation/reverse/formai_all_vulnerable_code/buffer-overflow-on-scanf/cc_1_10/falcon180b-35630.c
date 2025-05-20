//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILE_SIZE (1024 * 1024) // 1 MB
#define KEY_SIZE 16 // 128 bits

typedef struct {
    FILE *file;
    char *filename;
    int filesize;
    char *key;
} FileContext;

void generate_key(char *key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

int read_file(FileContext *ctx) {
    char buffer[MAX_FILE_SIZE];
    int bytes_read = 0;

    rewind(ctx->file);
    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, ctx->file)) > 0) {
        ctx->filesize += bytes_read;
        if (ctx->filesize > MAX_FILE_SIZE) {
            printf("Error: File is too large to encrypt.\n");
            exit(1);
        }
    }

    return bytes_read;
}

int write_file(FileContext *ctx) {
    char buffer[MAX_FILE_SIZE];
    int bytes_written = 0;

    rewind(ctx->file);
    while ((bytes_written = fwrite(ctx->key, 1, ctx->filesize, ctx->file)) > 0) {
        ctx->filesize -= bytes_written;
    }

    return bytes_written;
}

int main() {
    char input_filename[256];
    char output_filename[256];
    char key[KEY_SIZE];

    printf("Enter input filename: ");
    scanf("%s", input_filename);

    printf("Enter output filename: ");
    scanf("%s", output_filename);

    FileContext ctx = {0};
    ctx.file = fopen(input_filename, "rb");
    if (!ctx.file) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    generate_key(key);

    ctx.key = key;
    ctx.filename = output_filename;
    read_file(&ctx);
    write_file(&ctx);

    fclose(ctx.file);

    printf("File encrypted successfully!\n");
    return 0;
}