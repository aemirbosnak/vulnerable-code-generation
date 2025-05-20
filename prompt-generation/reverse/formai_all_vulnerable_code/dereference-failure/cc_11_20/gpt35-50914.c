//FormAI DATASET v1.0 Category: File Synchronizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/* This program synchronizes the contents of two directories by copying new and modified files from one directory to the other*/

int main(int argc, char *argv[]){
    DIR *dir1, *dir2;
    struct dirent *ent1, *ent2;
    struct stat statbuf1, statbuf2;
    char *dirpath1, *dirpath2, *newpath;
    int ret;
    if(argc < 3){
        printf("Usage: %s source_directory destination_directory", argv[0]);
        exit(1);
    }
    dirpath1 = argv[1];
    dirpath2 = argv[2];
    if((dir1 = opendir(dirpath1)) == NULL){
        printf("Error opening source directory %s", dirpath1);
        exit(1);
    }
    if((dir2 = opendir(dirpath2)) == NULL){
        printf("Error opening destination directory %s", dirpath2);
        exit(1);
    }
    while((ent1 = readdir(dir1)) != NULL){
        if(strcmp(ent1->d_name, ".") == 0 || strcmp(ent1->d_name, "..") == 0)
            continue;
        newpath = (char*)malloc(strlen(dirpath2) + strlen(ent1->d_name) + 2);
        sprintf(newpath, "%s/%s", dirpath2, ent1->d_name);
        if((ret = stat(ent1->d_name, &statbuf1)) != 0){
            printf("Error getting information about file %s in source directory", ent1->d_name);
            continue;
        }
        while((ent2 = readdir(dir2)) != NULL){
            if(strcmp(ent2->d_name, ent1->d_name) == 0){
                if((ret = stat(ent2->d_name, &statbuf2)) != 0){
                    printf("Error getting information about file %s in destination directory", ent2->d_name);
                    continue;
                }
                if(statbuf1.st_mtime > statbuf2.st_mtime){
                    if(rename(ent2->d_name, newpath) != 0){
                        printf("Error moving file %s from destination directory to source directory", ent2->d_name);
                        continue;
                    }
                    printf("File %s synchronized\n", ent1->d_name);
                }
                break;
            }
        }
        if(ent2 == NULL){
            if(link(ent1->d_name, newpath) != 0){
                printf("Error copying file %s from source directory to destination directory", ent1->d_name);
                continue;
            }
            printf("File %s copied\n", ent1->d_name);
        }
        free(newpath);
    }
    closedir(dir1);
    closedir(dir2);
    return 0;
}