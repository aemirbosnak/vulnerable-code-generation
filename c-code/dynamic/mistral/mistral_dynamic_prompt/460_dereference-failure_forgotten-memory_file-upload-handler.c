#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 4096

void read_file(FILE *fp, char *buffer) {
    size_t num_read;
    num_read = fread(buffer, 1, BUF_SIZE, fp);
    buffer[num_read] = '\0';
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <upload_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *upload = fopen(argv[1], "rb");
    if (!upload) {
        perror("Error opening upload file");
        return 1;
    }

    char *data = malloc(BUF_SIZE);
    if (!data) {
        perror("Error allocating memory");
        fclose(upload);
        return 1;
    }

    read_file(upload, data);
    fclose(upload);

    FILE *output = fopen(argv[2], "wb");
    if (!output) {
        perror("Error opening output file");
        free(data);
        return 1;
    }

    fwrite(data, 1, strlen(data), output);
    fclose(output);

    free(data);

    printf("File upload successful.\n");

    // Dereference NULL pointer for fun! (Uncomment this line if you dare.)
    // int *ptr = NULL;
    // printf("%d\n", *ptr);

    return 0;
}
