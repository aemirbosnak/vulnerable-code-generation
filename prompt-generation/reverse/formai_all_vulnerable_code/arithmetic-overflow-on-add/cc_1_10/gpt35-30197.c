//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return -1;
    }
    
    int total_size = 0;
    char *dir_name = argv[1];
    struct stat dir_stat;
    if (lstat(dir_name, &dir_stat) < 0) {
        printf("Error: Unable to stat %s\n", dir_name);
        return -1;
    }
    
    if (!S_ISDIR(dir_stat.st_mode)) {
        printf("Error: %s is not a directory\n", dir_name);
        return -1;
    }
    
    printf("C Disk space analyzer\n");
    printf("=====================\n\n");
    printf("Directory: \t%s\n", dir_name);
    printf("Total size: \t%ld bytes\n", dir_stat.st_size);
    printf("=====================\n\n");
    
    FILE *file_list = popen("find . -type f", "r");
    if (file_list == NULL) {
        printf("Error: Failed to obtain file list\n");
        return -1;
    }
    
    printf("%-40s\t%10s\n", "File Name", "File Size");
    while (!feof(file_list)) {
        char file_path[1024];
        fgets(file_path, sizeof(file_path), file_list);
        file_path[strcspn(file_path, "\n")] = 0;
        
        struct stat file_stat;
        if (lstat(file_path, &file_stat) < 0) {
            printf("Error: Unable to stat %s\n", file_path);
            continue;
        }
        
        if (S_ISREG(file_stat.st_mode)) {
            printf("%-40s\t%10ld bytes\n", file_path, file_stat.st_size);
            total_size += file_stat.st_size;
        }
    }
    
    printf("\n=====================\n\n");
    printf("Total size of all files: \t%ld bytes\n", total_size);
    
    pclose(file_list);
    
    return 0;
}