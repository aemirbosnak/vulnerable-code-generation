//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Sherlock Holmes
#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// Declare a struct to hold file name and its size
struct File {
    char name[256];
    long size;
};

// Recursive function to iterate through all directories and files
void iterate(char* dir_path, struct File* files, int* file_count) {
    DIR* dir = opendir(dir_path);
    struct dirent* entry;
    while((entry = readdir(dir)) != NULL ) {
        if ( strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0 ) {
            continue;
        }
        char path[1024];
        sprintf(path, "%s/%s", dir_path, entry->d_name);
        if ( entry->d_type == DT_DIR ) {
            iterate(path, files, file_count);
        } else {
            struct File file;
            strcpy(file.name, path);
            FILE* f = fopen(path, "rb");
            if ( f == NULL ) {
                fprintf(stderr, "Cannot open %s\n", path);
                continue;
            }
            fseek(f, 0, SEEK_END);
            file.size = ftell(f);
            fclose(f);
            files[*file_count] = file;
            *file_count += 1;
        }
    }
    closedir(dir);
}

int compare_file_sizes(const void* a, const void* b) {
    const struct File* file_a = (struct File*)(a);
    const struct File* file_b = (struct File*)(b);
    if ( file_a->size > file_b->size ) {
        return -1;
    } else if ( file_a->size < file_b->size ) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    printf("Welcome to the C Disk Space Analyzer!\n\n");

    char dir_path[1024];
    printf("Please input the directory to analyze: ");
    fgets(dir_path, 1024, stdin);
    dir_path[strlen(dir_path) - 1] = '\0'; // remove newline character

    struct File files[10000];
    int file_count = 0;
    iterate(dir_path, files, &file_count);

    qsort(files, file_count, sizeof(struct File), compare_file_sizes);

    printf("\nThe top 10 largest files in \"%s\" are:\n", dir_path);

    printf("\n%-80s\t%s\n", "File Name", "Size");
    printf("----------------------------------------------------------------------------------\n");

    long total_size = 0;
    int i = 0;
    for ( ; i < 10 && i < file_count; ++i ) {
        printf("%-80s\t%.2f MB\n", files[i].name, ((float)files[i].size) / (1024*1024));
        total_size += files[i].size;
    }

    printf("\nTotal size of top 10 files: %.2f MB\n\n", ((float)total_size) / (1024*1024));
    return 0;
}