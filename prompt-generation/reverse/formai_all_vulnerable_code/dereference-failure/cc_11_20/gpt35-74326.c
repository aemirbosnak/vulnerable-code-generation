//FormAI DATASET v1.0 Category: File Synchronizer ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<time.h>

// Function to compare two files based on their last modification time
int compare_time(struct dirent* dir1, struct dirent* dir2) 
{   
    char* file1 = dir1->d_name;
    char* file2 = dir2->d_name;
    
    struct stat attr1, attr2;
    stat(file1, &attr1);
    stat(file2, &attr2);
    
    return difftime(attr1.st_mtime, attr2.st_mtime);
}

int main(int argc, char** argv)
{
    if(argc <= 2) {
        printf("Usage:\t./synchro <source_dir> <dest_dir>\n");
        exit(0);
    }
    
    char* src_location = argv[1];
    char* dest_location = argv[2];
    
    // Check if source and destination directories are valid
    DIR* src_dir = opendir(src_location);
    if(src_dir == NULL) {
        perror("Source directory doesn't exists");
        exit(0);
    }
    DIR* dest_dir = opendir(dest_location);
    if(dest_dir == NULL) {
        perror("Destination directory doesn't exists");
        exit(0);
    }
    
    // Read source and destination directories
    struct dirent **namelist1, **namelist2;
    int n1, n2;
    n1 = scandir(src_location, &namelist1, NULL, alphasort);
    if(n1 < 0) {
        perror("Error reading source directory");
        exit(0);
    }
    n2 = scandir(dest_location, &namelist2, NULL, alphasort);
    if(n2 < 0) {
        perror("Error reading destination directory");
        exit(0);
    }
    
    // Synchronize files from source to destination directory
    for(int i = 0; i < n1; i++) {
        char* src_file = namelist1[i]->d_name;
        if(strcmp(src_file, ".") == 0 || strcmp(src_file, "..") == 0)
            continue;
        
        char src_path[100], dest_path[100];
        sprintf(src_path, "%s/%s", src_location, src_file);
        sprintf(dest_path, "%s/%s", dest_location, src_file);
        
        struct stat attr1, attr2;
        int src_exist = stat(src_path, &attr1);
        int dest_exist = stat(dest_path, &attr2);
        
        // New file found in source directory
        if(src_exist == 0 && dest_exist < 0) {
            int fp1 = open(src_path, O_RDONLY);
            int fp2 = open(dest_path, O_CREAT|O_WRONLY, 0644);
            char buffer;
            while(read(fp1, &buffer, 1) == 1) {
                write(fp2, &buffer, 1);
            }
            printf("File %s copied from source to destination\n", src_file);
        }
        // File exists in both source and destination directory
        else if(src_exist == 0 && dest_exist == 0){
            // Compare last modification time of both files
            int modified = compare_time(namelist1[i], namelist2[i]);
            if(modified > 0) {
                int fp1 = open(src_path, O_RDONLY);
                int fp2 = open(dest_path, O_WRONLY|O_TRUNC);
                char buffer;
                while(read(fp1, &buffer, 1) == 1) {
                    write(fp2, &buffer, 1);
                }
                printf("File %s updated in destination\n", src_file);
            }
        }
    }
    
    // Delete files in destination directory which are not present in source directory
    for(int i = 0; i < n2; i++) {
        char* dest_file = namelist2[i]->d_name;
        if(strcmp(dest_file, ".") == 0 || strcmp(dest_file, "..") == 0)
            continue;
        
        char dest_path[100];
        sprintf(dest_path, "%s/%s", dest_location, dest_file);
        
        int present = 0;
        for(int j = 0; j < n1; j++) {
            if(strcmp(namelist1[j]->d_name, dest_file) == 0)
                present = 1;
        }
        if(present == 0) {
            int res = remove(dest_path);
            if(res == 0) {
                printf("File %s removed from destination\n", dest_file);
            }
        }
    }
    
    // Free allocated memory
    for(int i = 0; i < n1; i++)
        free(namelist1[i]);
    for(int i = 0; i < n2; i++)
        free(namelist2[i]);
    free(namelist1);
    free(namelist2);
    
    closedir(src_dir);
    closedir(dest_dir);
    
    return 0;
}