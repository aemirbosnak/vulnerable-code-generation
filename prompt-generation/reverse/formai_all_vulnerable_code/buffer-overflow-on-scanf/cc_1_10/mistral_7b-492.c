//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PATH 256
#define MAX_NAME 50
#define MAX_EXT 10

int main() {
    char path[MAX_PATH], name[MAX_NAME], ext[MAX_EXT], backupPath[MAX_PATH];
    FILE *src, *dest;

    printf("Enter file path: ");
    scanf("%s", path);

    printf("Enter file name: ");
    scanf("%s", name);

    printf("Enter backup extension: ");
    scanf("%s", ext);

    strcat(name, ".");
    strcat(name, ext);

    strcpy(backupPath, path);
    strcat(backupPath, "/");
    strcat(backupPath, name);
    strcat(backupPath, ".");
    strcat(backupPath, ext);
    strcat(backupPath, "_bak");

    if ((src = fopen(path, "rb")) == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    if ((dest = fopen(backupPath, "wb")) == NULL) {
        printf("Error creating backup file.\n");
        fclose(src);
        return 1;
    }

    fseek(src, 0, SEEK_END);
    long fileSize = ftell(src);
    rewind(src);

    fwrite(fread(src, 1, fileSize, src), 1, fileSize, dest);

    printf("Backup created: %s\n", backupPath);
    fclose(src);
    fclose(dest);

    return 0;
}