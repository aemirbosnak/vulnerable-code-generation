//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

//function to get size of a file or directory
long long int getSize(char* path){
    struct stat st;
    //get the status of the file or link
    if(stat(path, &st)==0){
        //if it is directory call the function recursively to get the size
        if(S_ISDIR(st.st_mode)){
            DIR* dir;
            struct dirent* entry;
            long long int size = 0;

            dir = opendir(path);
            if(dir==NULL){
                printf("Error opening directory.");
                return -1;
            }

            while((entry = readdir(dir))!=NULL){
                //ignore the current and parent directory
                if(strcmp(entry->d_name, ".")==0||strcmp(entry->d_name, "..")==0){
                    continue;
                }
                char temp[1000];
                sprintf(temp, "%s/%s", path, entry->d_name);
                size += getSize(temp);
            }
            closedir(dir);
            return size;
        }
        else{
            //if it is a file return the size
            return st.st_size;
        }
    }
    else{
        printf("Error getting status of the file.");
        return -1;
    }
}

int main(){
    //get user input for the directory path
    char path[1000];
    printf("Enter the directory path: ");
    scanf("%s", path);
    printf("\n");

    //call the function to get the size of the directory
    long long int size = getSize(path);

    //print the size in appropriate format
    if(size<1024){
        printf("Size of the directory is %lld bytes.", size);
    }
    else if(size<1048576){
        printf("Size of the directory is %.2f KB.", (float)size/1024);
    }
    else if(size<1073741824){
        printf("Size of the directory is %.2f MB.", (float)size/1048576);
    }
    else{
        printf("Size of the directory is %.2f GB.", (float)size/1073741824);
    }

    return 0;
}