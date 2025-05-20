//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MB 1048576

typedef struct {
    char *name;
    double size;
} File;

void print_top_ten(File *files){
    printf("+------------------+-------------+\n");
    printf("| Filename         | Size (MB)   |\n");
    printf("+------------------+-------------+\n");

    for(int i = 0; i < 10; i++){
        printf("| %-16s | %11.2f |\n", files[i].name, files[i].size);
    }

    printf("+------------------+-------------+\n");
}

double get_dir_size(const char *path){
    double size = 0;
    DIR *d = opendir(path);
    if(d == NULL){
        return 0;
    }

    struct dirent *dir;
    struct stat file_stats;

    while((dir = readdir(d)) != NULL){
        if(strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0){
            continue;
        }

        char filepath[512];
        snprintf(filepath, sizeof(filepath), "%s/%s", path, dir->d_name);
        if(stat(filepath, &file_stats) == -1){
            continue;
        }

        if(S_ISDIR(file_stats.st_mode)){
            size += get_dir_size(filepath);
        }else{
            size += file_stats.st_size;
        }
    }

    closedir(d);
    return size / MB;
}

void find_largest_files(const char *path, int max_count){
    File *files = calloc(max_count, sizeof(File));

    DIR *d = opendir(path);
    if(d == NULL){
        return;
    }

    struct dirent *dir;
    struct stat file_stats;

    while((dir = readdir(d)) != NULL){
        if(strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0){
            continue;
        }

        char filepath[512];
        snprintf(filepath, sizeof(filepath), "%s/%s", path, dir->d_name);
        if(stat(filepath, &file_stats) == -1){
            continue;
        }

        if(!S_ISREG(file_stats.st_mode)){
            continue;
        }

        double size = file_stats.st_size / MB;
        for(int i = 0; i < max_count; i++){
            if(size > files[i].size){
                File temp = files[i];
                files[i].name = strdup(filepath);
                files[i].size = size;
                for(int j = i + 1; j < max_count; j++){
                    File next = files[j];
                    files[j] = temp;
                    temp = next;
                }
                break;
            }
        }
    }

    print_top_ten(files);

    for(int i = 0; i < max_count; i++){
        free(files[i].name);
    }
    free(files);

    closedir(d);
}

int main(){
    char path[512];
    printf("Enter the name of the directory to analyze: ");
    scanf("%s", path);

    printf("\nCalculating total directory size...\n");
    double dir_size = get_dir_size(path);
    printf("Total directory size: %.2f MB\n\n", dir_size);

    printf("Finding largest files...\n");
    find_largest_files(path, 10);

    return 0;
}