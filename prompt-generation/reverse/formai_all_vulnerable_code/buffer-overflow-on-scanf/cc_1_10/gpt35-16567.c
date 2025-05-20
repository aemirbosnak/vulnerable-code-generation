//FormAI DATASET v1.0 Category: File Synchronizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

bool isDirectory(char *path){
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

void synchronize(char *src_path, char *dest_path){
    if(!isDirectory(src_path) || !isDirectory(dest_path)){
        printf("Error: source or destination is not a directory!\n");
        exit(1);
    }
    DIR *src_dir = opendir(src_path);
    DIR *dest_dir = opendir(dest_path);
    if(src_dir == NULL || dest_dir == NULL){
        printf("Error opening directories!\n");
        exit(1);
    }
    struct dirent *entry;
    while((entry = readdir(src_dir)) != NULL){
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        char src_file[strlen(src_path) + strlen(entry->d_name) + 2];
        sprintf(src_file, "%s/%s", src_path, entry->d_name);
        char dest_file[strlen(dest_path) + strlen(entry->d_name) + 2];
        sprintf(dest_file, "%s/%s", dest_path, entry->d_name);
        if(isDirectory(src_file)){
            mkdir(dest_file, 0777);
            synchronize(src_file, dest_file);
        } else {
            FILE *src = fopen(src_file, "r");
            FILE *dest;
            bool file_exists = false;
            while((entry = readdir(dest_dir)) != NULL){
                if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                    continue;
                char file[strlen(dest_path) + strlen(entry->d_name) + 2];
                sprintf(file, "%s/%s", dest_path, entry->d_name);
                if(strcmp(file, dest_file) == 0){
                    file_exists = true;
                    break;
                }
            }
            rewinddir(dest_dir);
            if(file_exists){
                char choice;
                printf("File '%s' already exists in destination. Do you want to overwrite it? (y/n): ", entry->d_name);
                scanf("%c", &choice);
                if(choice == 'y' || choice == 'Y')
                    dest = fopen(dest_file, "w");
                else
                    continue;
            } else {
                dest = fopen(dest_file, "w");
            }
            char c;
            while((c = fgetc(src)) != EOF){
                fputc(c, dest);
            }
            printf("File '%s' synchronized!\n", entry->d_name);
            fclose(src);
            fclose(dest);
        }
    }
    closedir(src_dir);
    closedir(dest_dir);
}

int main(){
    char src_path[100], dest_path[100];
    printf("Enter path to source directory: ");
    scanf("%s", src_path);
    printf("Enter path to destination directory: ");
    scanf("%s", dest_path);
    synchronize(src_path, dest_path);
    return 0;
}