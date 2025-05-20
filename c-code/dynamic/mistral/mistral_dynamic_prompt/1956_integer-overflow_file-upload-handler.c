#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 4096

int main(int argc, char *argv[]) {
    char buffer[MAX_BUFFER];
    FILE *fp;

    if (argc < 3) {
        printf("Usage: %s <filename> <size>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "wb");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    printf("Uploading data...\n");
    fgets(buffer, MAX_BUFFER, stdin);

    size_t size = atoi(argv[2]);
    if (size > MAX_BUFFER) {
        printf("Size exceeds buffer limit.\n");
        return 1;
    }

    fwrite(buffer, size, 1, fp);
    fclose(fp);
    printf("File uploaded.\n");

    // Stack overflow by writing beyond allocated buffer size
    char *vuln_buffer = (char*)malloc(size);
    strcpy(vuln_buffer, buffer);

    return 0;
}
