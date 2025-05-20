//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

void analyze(char* path, int depth){
    DIR* directory = opendir(path);
    if(directory == NULL){
        printf("Error opening directory %s\n", path);
        return;
    }

    struct dirent* dirEntry;
    while((dirEntry = readdir(directory)) != NULL){
        // skip "." and ".." directories
        if(strcmp(dirEntry->d_name, ".") == 0 || strcmp(dirEntry->d_name, "..") == 0){
            continue;
        }

        // build the full path of the directory entry
        char entryPath[1024];
        snprintf(entryPath, sizeof(entryPath), "%s/%s", path, dirEntry->d_name);

        struct stat statBuf;
        if(stat(entryPath, &statBuf) == -1){
            printf("Error getting stats for %s\n", entryPath);
            continue;
        }

        // print the size and name of the directory entry
        for(int i = 0; i < depth; i++){
            printf("  ");
        }
        printf("%-20ld %s\n", statBuf.st_size, dirEntry->d_name);

        // recurse into the directory if it's a subdirectory
        if(S_ISDIR(statBuf.st_mode)){
            analyze(entryPath, depth+1);
        }
    }

    closedir(directory);
}

int main(){
    printf("Please enter the path to analyze:\n");
    char path[1024];
    scanf("%s", path);

    printf("\nDisk Usage Analyzer\n");
    printf("====================\n");

    analyze(path, 0);

    return 0;
}