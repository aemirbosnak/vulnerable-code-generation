//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

void printSize(long int size){
    if(size < 1024)
        printf("%ld B", size);
    else if(size < 1024*1024)
        printf("%.2f KB", (float)size / 1024);
    else if(size < 1024*1024*1024)
        printf("%.2f MB", (float)size / (1024*1024));
    else
        printf("%.2f GB", (float)size / (1024*1024*1024));   
}

void scan(char *path, int depth){
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    long int totalSize = 0;
    char filePath[256];

    if((dir = opendir(path)) == NULL)
        return;

    while((entry = readdir(dir)) != NULL){
        //skip current and parent dir
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        //create file path
        sprintf(filePath, "%s/%s", path, entry->d_name);

        //get file info
        if (stat(filePath, &fileStat) < 0)
            continue;

        //print file size info
        for(int i=0; i<depth; i++)
            printf("\t");
        printf("%s\t", entry->d_name);
        printSize(fileStat.st_size);
        printf("\n");

        //if file is a directory, scan it recursively
        if(S_ISDIR(fileStat.st_mode))
            scan(filePath, depth+1);

        totalSize += fileStat.st_size;      
    }

    closedir(dir);

    //print total size of current dir
    if(depth == 0){
        printf("total disk space used: ");
        printSize(totalSize);
        printf("\n");
    }
}

int main(){
    char path[256];

    printf("Enter the path to scan: ");
    scanf("%s", path);

    printf("Scanning %s...\n", path);
    scan(path, 0);

    return 0;
}