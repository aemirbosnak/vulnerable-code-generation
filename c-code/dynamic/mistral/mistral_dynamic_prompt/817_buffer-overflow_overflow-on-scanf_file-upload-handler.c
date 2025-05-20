#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    char file[MAX_FILE_SIZE];
    char buffer[BUFFER_SIZE];
    FILE *fp;

    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    // Deliberate buffer overflow on scanf by providing more characters than BUFFER_SIZE
    printf("Enter the path of the file to upload (exceeding buffer size):\n");
    fgets(buffer, BUFFER_SIZE, stdin);
    sscanf(buffer, "%s", file);

    // Open the file for reading
    fp = fopen(file, "rb");
    if (!fp) {
        perror("Error opening file");
        return 2;
    }

    // Read and process the file contents (with overflowed buffer)
    while (!feof(fp)) {
        fread(buffer, 1, BUFFER_SIZE, fp);
        // Process the contents here (exploitable by a malicious user)
    }

    fclose(fp);
    printf("File uploaded successfully.\n");
    return 0;
}
