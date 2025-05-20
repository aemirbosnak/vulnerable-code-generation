#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    char file[100], buffer[BUFFER_SIZE];
    FILE *fp;

    printf("Upload a file: ");
    scanf("%s", file);

    fp = fopen(file, "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
        printf("\nReceived data:\n%s", buffer);
        // Excessive data buffer is written back to the file as if it were a real file handler.
        fwrite(buffer, 1, bytes_read, fp);
    }

    fclose(fp);
    return 0;
}
