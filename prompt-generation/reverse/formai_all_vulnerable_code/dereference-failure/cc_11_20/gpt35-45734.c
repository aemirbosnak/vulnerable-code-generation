//FormAI DATASET v1.0 Category: File Synchronizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_DEPTH 1024

void sync_directory(char *src, char *dst, int depth);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sync_directory(argv[1], argv[2], 0);
    
    return 0;
}

void sync_directory(char *src, char *dst, int depth)
{
    if (depth == MAX_DEPTH)
    {
        printf("Error: maximum depth exceeded.\n");
        exit(EXIT_FAILURE);
    }
    
    DIR *src_dir = opendir(src);
    DIR *dst_dir = opendir(dst);
    
    if (!src_dir)
    {
        printf("Error: could not open source directory %s.\n", src);
        exit(EXIT_FAILURE);
    }
    
    if (!dst_dir)
    {
        if (mkdir(dst, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == -1)
        {
            printf("Error: could not create destination directory %s.\n", dst);
            exit(EXIT_FAILURE);
        }
        
        dst_dir = opendir(dst);
        
        if (!dst_dir)
        {
            printf("Error: could not open destination directory %s.\n", dst);
            exit(EXIT_FAILURE);
        }
    }
    
    struct dirent *src_entry;
    struct dirent *dst_entry;
    struct stat src_st;
    struct stat dst_st;
    
    char src_path[MAX_PATH_LENGTH];
    char dst_path[MAX_PATH_LENGTH];
    
    while ((src_entry = readdir(src_dir)))
    {
        if (strcmp(src_entry->d_name, ".") == 0 || strcmp(src_entry->d_name, "..") == 0)
            continue;
        
        snprintf(src_path, MAX_PATH_LENGTH, "%s/%s", src, src_entry->d_name);
        
        if (lstat(src_path, &src_st) == -1)
        {
            printf("Warning: could not stat source file %s (%s).\n", src_path, strerror(errno));
            continue;
        }
        
        snprintf(dst_path, MAX_PATH_LENGTH, "%s/%s", dst, src_entry->d_name);
        
        if (lstat(dst_path, &dst_st) == -1)
        {
            if (errno == ENOENT)
            {
                if (S_ISDIR(src_st.st_mode))
                {
                    if (mkdir(dst_path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == -1)
                    {
                        printf("Error: could not create destination directory %s (%s).\n", dst_path, strerror(errno));
                        exit(EXIT_FAILURE);
                    }
                    
                    printf("Created directory: %s.\n", dst_path);
                    
                    sync_directory(src_path, dst_path, depth + 1);
                }
                else if (S_ISREG(src_st.st_mode))
                {
                    FILE *src_file = fopen(src_path, "rb");
                    
                    if (!src_file)
                    {
                        printf("Warning: could not open source file %s (%s).\n", src_path, strerror(errno));
                        continue;
                    }
                    
                    FILE *dst_file = fopen(dst_path, "wb");
                    
                    if (!dst_file)
                    {
                        fclose(src_file);
                        printf("Error: could not create destination file %s (%s).\n", dst_path, strerror(errno));
                        exit(EXIT_FAILURE);
                    }
                    
                    char buffer[4096];
                    size_t count;
                    
                    while ((count = fread(buffer, 1, 4096, src_file)))
                        fwrite(buffer, 1, count, dst_file);
                    
                    fclose(src_file);
                    fclose(dst_file);
                    
                    printf("Copied file: %s -> %s.\n", src_path, dst_path);
                }
            }
            else
            {
                printf("Warning: could not stat destination file %s (%s).\n", dst_path, strerror(errno));
            }
        }
        else
        {
            if (S_ISDIR(src_st.st_mode))
            {
                if (!S_ISDIR(dst_st.st_mode))
                {
                    printf("Error: %s is a directory, but %s is not.\n", src_path, dst_path);
                    exit(EXIT_FAILURE);
                }
                
                sync_directory(src_path, dst_path, depth + 1);
            }
            else if (S_ISREG(src_st.st_mode))
            {
                if (!S_ISREG(dst_st.st_mode))
                {
                    printf("Error: %s is a regular file, but %s is not.\n", src_path, dst_path);
                    exit(EXIT_FAILURE);
                }
                
                if (src_st.st_mtime > dst_st.st_mtime)
                {
                    FILE *src_file = fopen(src_path, "rb");
                    
                    if (!src_file)
                    {
                        printf("Warning: could not open source file %s (%s).\n", src_path, strerror(errno));
                        continue;
                    }
                    
                    FILE *dst_file = fopen(dst_path, "wb");
                    
                    if (!dst_file)
                    {
                        fclose(src_file);
                        printf("Error: could not create destination file %s (%s).\n", dst_path, strerror(errno));
                        exit(EXIT_FAILURE);
                    }
                    
                    char buffer[4096];
                    size_t count;
                    
                    while ((count = fread(buffer, 1, 4096, src_file)))
                        fwrite(buffer, 1, count, dst_file);
                    
                    fclose(src_file);
                    fclose(dst_file);
                    
                    printf("Updated file: %s -> %s.\n", src_path, dst_path);
                }
            }
        }
    }
    
    while ((dst_entry = readdir(dst_dir)))
    {
        if (strcmp(dst_entry->d_name, ".") == 0 || strcmp(dst_entry->d_name, "..") == 0)
            continue;
        
        snprintf(dst_path, MAX_PATH_LENGTH, "%s/%s", dst, dst_entry->d_name);
        
        if (lstat(dst_path, &dst_st) != -1)
            continue;
        
        printf("Removed file/directory: %s.\n", dst_path);
        
        if (unlink(dst_path) == -1)
        {
            printf("Error: could not remove file/directory %s (%s).\n", dst_path, strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
    
    closedir(src_dir);
    closedir(dst_dir);
}