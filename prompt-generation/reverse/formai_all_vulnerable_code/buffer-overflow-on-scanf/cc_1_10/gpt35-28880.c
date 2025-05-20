//FormAI DATASET v1.0 Category: File Synchronizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void copy_file(char *source_path,char *destination_path){
    FILE *source_file,*destination_file;
    source_file = fopen(source_path,"rb");
    destination_file = fopen(destination_path,"wb");
    if (source_file == NULL || destination_file == NULL){
        printf("Error! Could not open file.\n");
        exit(EXIT_FAILURE);
    }

    char ch;
    while ((ch = fgetc(source_file)) != EOF){
        fputc(ch,destination_file);
    }

    fclose(source_file);
    fclose(destination_file);
}

void run_sync(char *source_dir,char *destination_dir){
    DIR *source_ptr;
    DIR *destination_ptr;
    struct dirent *source_entity;
    struct dirent *destination_entity;
    struct stat source_stat;
    struct stat destination_stat;
    char source_path[PATH_MAX];
    char destination_path[PATH_MAX];

    source_ptr = opendir(source_dir);
    destination_ptr = opendir(destination_dir);

    if (source_ptr == NULL || destination_ptr == NULL){
        printf("Error! Could not open directory.\n");
        exit(EXIT_FAILURE);
    }

    while ((source_entity = readdir(source_ptr)) != NULL){
        if (source_entity->d_type == DT_REG){ // Check if entity is a regular file
            sprintf(source_path,"%s/%s",source_dir,source_entity->d_name);
            stat(source_path,&source_stat);
            int found_file = 0;
            while ((destination_entity = readdir(destination_ptr)) != NULL){
                if (destination_entity->d_type == DT_REG &&
                    strcmp(destination_entity->d_name,source_entity->d_name) == 0){ // Check if file with same name exists in destination dir
                    found_file = 1;
                    sprintf(destination_path,"%s/%s",destination_dir,destination_entity->d_name);
                    stat(destination_path,&destination_stat);
                    if (source_stat.st_mtime > destination_stat.st_mtime){ // Check if source file is newer than destination file
                        copy_file(source_path,destination_path);
                        printf("%s synced to %s\n",source_path,destination_path);
                    }
                }
            }
            rewinddir(destination_ptr); // Reset destination directory pointer to start reading again
            if (found_file == 0){ // File does not exist in destination directory
                sprintf(destination_path,"%s/%s",destination_dir,source_entity->d_name);
                copy_file(source_path,destination_path);
                printf("%s synced to %s\n",source_path,destination_path);
            }
        }
    }
    closedir(source_ptr);
    closedir(destination_ptr);
}

int main(){
    char source_dir[PATH_MAX];
    char destination_dir[PATH_MAX];

    printf("Welcome to our romantic file synchronizer!\n");
    printf("Please enter the source directory: ");
    scanf("%s",source_dir);
    printf("Please enter the destination directory: ");
    scanf("%s",destination_dir);

    run_sync(source_dir,destination_dir);

    printf("Sync complete! I love to synchronize files with you!\n");

    return 0;
}