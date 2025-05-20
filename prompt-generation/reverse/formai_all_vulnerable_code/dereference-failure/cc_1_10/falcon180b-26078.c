//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_FILE_SIZE (10 * 1024 * 1024)
#define VIRUS_SIGNATURE "X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*"
#define VIRUS_SIGNATURE_LENGTH 68

int scan_file(const char *filename) {
    FILE *fp;
    char buffer[MAX_FILE_SIZE];
    int bytes_read, i;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    bytes_read = fread(buffer, 1, MAX_FILE_SIZE, fp);
    if (bytes_read <= 0) {
        printf("Error: could not read file %s\n", filename);
        fclose(fp);
        return 1;
    }

    fclose(fp);

    for (i = 0; i < bytes_read - VIRUS_SIGNATURE_LENGTH; i++) {
        if (memcmp(buffer + i, VIRUS_SIGNATURE, VIRUS_SIGNATURE_LENGTH) == 0) {
            printf("Virus found in file %s\n", filename);
            return 1;
        }
    }

    printf("File %s is clean\n", filename);
    return 0;
}

int scan_directory(const char *dirname) {
    DIR *dp;
    struct dirent *dirp;

    dp = opendir(dirname);
    if (dp == NULL) {
        printf("Error: could not open directory %s\n", dirname);
        return 1;
    }

    while ((dirp = readdir(dp))!= NULL) {
        if (dirp->d_type == DT_REG) {
            char path[256];
            snprintf(path, sizeof(path), "%s/%s", dirname, dirp->d_name);
            scan_file(path);
        }
    }

    closedir(dp);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    scan_directory(argv[1]);

    return 0;
}