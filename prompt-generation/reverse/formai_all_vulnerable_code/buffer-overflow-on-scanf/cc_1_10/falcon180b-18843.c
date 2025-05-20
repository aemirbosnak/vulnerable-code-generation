//Falcon-180B DATASET v1.0 Category: Error handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_SIZE 100

int main() {
    FILE *file;
    char filename[MAX_SIZE];
    char *buf = NULL;
    size_t bufsize = 0;
    int ret;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    // Allocate buffer for reading file
    buf = malloc(MAX_SIZE);
    if (buf == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    // Read file into buffer
    bufsize = fread(buf, 1, MAX_SIZE, file);
    if (bufsize == 0) {
        printf("Error reading file\n");
        return 1;
    }

    // Close file
    ret = fclose(file);
    if (ret!= 0) {
        printf("Error closing file: %s\n", strerror(errno));
        return 1;
    }

    // Print buffer contents
    printf("File contents:\n%s", buf);

    // Free buffer memory
    free(buf);

    return 0;
}