#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void handleFileUpload(char *filename, char *content) {
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "Saving %s with content: %s", filename, content);
    printf("%s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <content>\n", argv[0]);
        return 1;
    }

    char filename[256];
    char content[1024];

    // Simulate file upload parameters
    strcpy(filename, argv[1]);
    strcpy(content, argv[2]);

    // Vulnerable function call
    handleFileUpload(filename, content);

    return 0;
}
