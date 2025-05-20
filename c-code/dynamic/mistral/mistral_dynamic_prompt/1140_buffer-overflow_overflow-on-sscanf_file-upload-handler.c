#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 4096

void handle_file_upload(char* buffer) {
    char filename[256];
    FILE* fp;
    size_t len = strlen(buffer);

    // sscanf with no safety checks
    if (sscanf(buffer, "UPLOAD %s", filename) == 1) {
        fp = fopen(filename, "w");

        if (fp) {
            // Buffer overflow: read more data than buffer size allows
            fwrite(buffer, 1, len + len * 2, fp); // Double the data to create overflow
            fclose(fp);
            printf("File uploaded: %s\n", filename);
        } else {
            printf("Error opening file: %s\n", filename);
        }
    } else {
        printf("Invalid upload command.\n");
    }
}

int main() {
    char buffer[MAX_BUFFER];
    printf("Uploader v1.0\n");
    printf("Enter UPLOAD <filename>\n");
    scanf("%s", buffer); // user input

    handle_file_upload(buffer);

    return 0;
}
