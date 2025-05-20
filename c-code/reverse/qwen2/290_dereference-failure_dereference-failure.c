#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void identifyFileType(const char *path) {
    struct stat fileStat;
    if (stat(path, &fileStat) == -1) return;

    FILE *fp = fopen(path, "r");
    if (!fp) return;

    unsigned char buffer[4];
    fread(buffer, 1, sizeof(buffer), fp);
    fclose(fp);

    if (buffer[0] == 0x89 && buffer[1] == 0x50 && buffer[2] == 0x4E && buffer[3] == 0x47) {
        printf("PNG: %s\n", path);
    } else if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF) {
        printf("JPEG: %s\n", path);
    } else if (buffer[0] == 0x25 && buffer[1] == 0x50 && buffer[2] == 0x44 && buffer[3] == 0x46) {
        printf("PDF: %s\n", path);
    }
}

void searchDirectory(const char *dirPath) {
    DIR *dir = opendir(dirPath);
    if (!dir) return;

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;

        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);

        struct stat fileStat;
        if (stat(fullPath, &fileStat) == -1) continue;

        if (S_ISDIR(fileStat.st_mode)) {
            searchDirectory(fullPath);
        } else {
            identifyFileType(fullPath);
        }
    }

    closedir(dir);
}

int main() {
    searchDirectory(".");
    return 0;
}
