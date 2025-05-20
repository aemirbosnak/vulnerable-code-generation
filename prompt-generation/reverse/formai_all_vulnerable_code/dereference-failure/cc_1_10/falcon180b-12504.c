//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_NAME_LENGTH 1024
#define VIRUS_SIGNATURE "eicar"
#define VIRUS_SIGNATURE_LENGTH (sizeof(VIRUS_SIGNATURE) - 1)

bool is_infected(const char *file_name) {
    FILE *file;
    char buffer[MAX_FILE_NAME_LENGTH];
    int bytes_read;

    if ((file = fopen(file_name, "rb")) == NULL) {
        return false;
    }

    while ((bytes_read = fread(buffer, sizeof(char), MAX_FILE_NAME_LENGTH, file)) > 0) {
        if (memcmp(buffer, VIRUS_SIGNATURE, VIRUS_SIGNATURE_LENGTH) == 0) {
            fclose(file);
            return true;
        }
    }

    fclose(file);
    return false;
}

void scan_directory(const char *directory) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(directory))!= NULL) {
        while ((entry = readdir(dir))!= NULL) {
            if (entry->d_type == DT_REG) {
                char file_name[MAX_FILE_NAME_LENGTH];
                snprintf(file_name, sizeof(file_name), "%s/%s", directory, entry->d_name);
                if (is_infected(file_name)) {
                    printf("Virus found in file: %s\n", file_name);
                }
            }
        }
        closedir(dir);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char directory[MAX_FILE_NAME_LENGTH];
    snprintf(directory, sizeof(directory), "%s", argv[1]);

    if (access(directory, F_OK)!= 0) {
        printf("Directory does not exist: %s\n", directory);
        return 1;
    }

    if (access(directory, R_OK | X_OK)!= 0) {
        printf("Directory is not readable or executable: %s\n", directory);
        return 1;
    }

    scan_directory(directory);

    return 0;
}