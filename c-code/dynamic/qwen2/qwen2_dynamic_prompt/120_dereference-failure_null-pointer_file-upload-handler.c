#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void handleFileUpload(char *filename, char *content) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    fprintf(file, "%s", content);
    fclose(file);
}

int main() {
    char filename[256];
    char content[1024];

    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    printf("Enter content: ");
    fgets(content, sizeof(content), stdin);

    // Simulate a null pointer dereference by passing a null pointer to handleFileUpload
    handleFileUpload(NULL, content);

    return 0;
}
