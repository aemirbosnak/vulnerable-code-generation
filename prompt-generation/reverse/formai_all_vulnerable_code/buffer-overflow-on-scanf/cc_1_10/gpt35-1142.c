//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: recursive
#include <stdio.h>
#include <dirent.h>
#include <string.h>

void scan_directory(char *dir_path) {
    DIR *dir = opendir(dir_path);

    if (dir == NULL) {
        printf("Failed to open directory %s", dir_path);
        return;
    }

    struct dirent *dir_entry;

    while ((dir_entry = readdir(dir)) != NULL) {
        if (dir_entry->d_name[0] == '.') {
            continue;   // ignore hidden files
        }

        char file_path[256];
        sprintf(file_path, "%s/%s", dir_path, dir_entry->d_name);

        if (dir_entry->d_type == DT_DIR) {
            scan_directory(file_path);
        } else {
            FILE *fp = fopen(file_path, "rb");

            if (fp == NULL) {
                printf("Failed to open file %s", file_path);
                continue;
            }

            // Check 4 bytes at a time for virus signature
            unsigned char signature[] = { 'V', 'I', 'R', 'U', 'S' };
            unsigned char buffer[8];
            int count = 0;

            while (fread(buffer, sizeof(buffer), 1, fp) == 1) {
                for (int i = 0; i < sizeof(buffer); i++) {
                    if (buffer[i] == signature[count]) {
                        count++;

                        if (count == sizeof(signature)) {
                            printf("Virus detected in file %s", file_path);
                            fclose(fp);
                            return;
                        }
                    } else {
                        count = 0;
                    }
                }
            }

            fclose(fp);
        }
    }

    closedir(dir);
}

int main() {
    char dir_path[256];
    printf("Enter directory path to scan: ");
    scanf("%s", dir_path);

    scan_directory(dir_path);
    printf("Scan complete. No viruses detected.");

    return 0;
}