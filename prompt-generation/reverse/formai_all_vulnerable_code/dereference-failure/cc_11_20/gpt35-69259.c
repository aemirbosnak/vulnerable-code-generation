//FormAI DATASET v1.0 Category: File Synchronizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
 
void synchronize(char* source_dir, char* target_dir){
    DIR *source, *target;
    struct dirent *source_entry, *target_entry;
    struct stat source_stat, target_stat;
    char source_file[PATH_MAX], target_file[PATH_MAX];
 
    // open directories
    source = opendir(source_dir);
    target = opendir(target_dir);
 
    if(source == NULL || target == NULL){
        printf("Error: Could not open directories.\n");
        exit(EXIT_FAILURE);
    }
 
    // synchronize files from source to target
    while((source_entry = readdir(source)) != NULL){
        // skip current and parent directory
        if(strcmp(source_entry->d_name, ".") == 0 || strcmp(source_entry->d_name, "..") == 0)
            continue;
 
        // get full path of source file
        sprintf(source_file, "%s/%s", source_dir, source_entry->d_name);

        // get file status
        if(stat(source_file, &source_stat) == -1){
            printf("Error: Could not get file status.\n");
            exit(EXIT_FAILURE);
        }

        // check if source file is a regular file
        if(S_ISREG(source_stat.st_mode)){
            // check if target file exists
            sprintf(target_file, "%s/%s", target_dir, source_entry->d_name);
            if(stat(target_file, &target_stat) == -1){
                // if target file does not exist, copy source file to target directory
                printf("Copying %s to %s\n", source_file, target_file);
                if(link(source_file, target_file) == -1){
                    printf("Error: Could not copy file.\n");
                    exit(EXIT_FAILURE);
                }
            } else {
                // if target file exists, compare modification times
                if(difftime(source_stat.st_mtime, target_stat.st_mtime) > 0){
                    printf("Updating %s in %s\n", source_file, target_dir);
                    if(unlink(target_file) == -1 || link(source_file, target_file) == -1){
                        printf("Error: Could not update file.\n");
                        exit(EXIT_FAILURE);
                    }
                }
            }
        } else if(S_ISDIR(source_stat.st_mode)){
            // if source file is a directory, recursively synchronize contents
            sprintf(target_file, "%s/%s", target_dir, source_entry->d_name);

            // create directory if it does not exist
            if(mkdir(target_file, source_stat.st_mode) == -1){
                printf("Error: Could not create directory.\n");
                exit(EXIT_FAILURE);
            }

            // synchronize contents
            synchronize(source_file, target_file);
        }
    }
 
    // remove files from target that do not exist in source
    while((target_entry = readdir(target)) != NULL){
        // skip current and parent directory
        if(strcmp(target_entry->d_name, ".") == 0 || strcmp(target_entry->d_name, "..") == 0)
            continue;

        // get full path of target file
        sprintf(target_file, "%s/%s", target_dir, target_entry->d_name);
 
        // check if target file exists in source
        sprintf(source_file, "%s/%s", source_dir, target_entry->d_name);
        if(access(source_file, F_OK) == -1){
            // if target file does not exist in source, delete it
            printf("Deleting %s from %s\n", target_file, target_dir);
            if(unlink(target_file) == -1){
                printf("Error: Could not delete file.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
 
    // close directories
    closedir(source);
    closedir(target);
}
 
int main(int argc, char** argv){
    if(argc != 3){
        printf("Usage: %s source_dir target_dir\n", argv[0]);
        exit(EXIT_FAILURE);
    }
 
    synchronize(argv[1], argv[2]);
 
    return 0;
}