//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int countSize(char *path) {
    long long int size = 0;
    char command[1000];
    sprintf(command, "du -ks %s", path);
    FILE *fp = popen(command, "r");
    char str[1000];
    fgets(str, 1000, fp);
    pclose(fp);
    sscanf(str, "%lld", &size);
    return size;
}

void analyzeDisk(char *path) {
    long long int size = countSize(path);
    printf("Total size of %s is %lld Kilobytes", path, size);
    if (size > 1024) {
        size /= 1024;
        printf(", or %lld Megabytes", size);
    }
    if (size > 1024) {
        size /= 1024;
        printf(", or %lld Gigabytes", size);
    }
    printf("\n");
    int numFiles = 0;
    int numDirs = 0;
    char command[1000];
    sprintf(command, "find %s -maxdepth 1 | wc -l", path);
    FILE *fp = popen(command, "r");
    char str[1000];
    fgets(str, 1000, fp);
    pclose(fp);
    sscanf(str, "%d", &numFiles);
    numFiles--;
    sprintf(command, "find %s -maxdepth 1 -type d | wc -l", path);
    fp = popen(command, "r");
    fgets(str, 1000, fp);
    pclose(fp);
    sscanf(str, "%d", &numDirs);
    numDirs--;
    printf("Number of files in %s is %d\n", path, numFiles);
    printf("Number of directories in %s is %d\n", path, numDirs);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s PATH\n", argv[0]);
        return 1;
    }
    analyzeDisk(argv[1]);
    return 0;
}