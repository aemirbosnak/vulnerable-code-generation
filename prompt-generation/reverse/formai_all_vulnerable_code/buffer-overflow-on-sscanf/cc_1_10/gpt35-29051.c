//FormAI DATASET v1.0 Category: File Synchronizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// define a struct to store the synchronization settings for each directory
struct sync_setting {
    char source_dir[256];
    char target_dir[256];
    char exclusion_list[256];
};

// function to copy a file from source_dir to target_dir
int copy_file(const char *source_file, const char *target_file) {
    FILE *src, *tgt;
    char ch;
    src = fopen(source_file, "r");
    if (src == NULL) {
        printf("Unable to open %s for reading\n", source_file);
        return -1;
    }
    tgt = fopen(target_file, "w");
    if (tgt == NULL) {
        printf("Unable to open %s for writing\n", target_file);
        fclose(src);
        return -1;
    }
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, tgt);
    }
    fclose(src);
    fclose(tgt);
    return 0;
}

// function to check if a file or directory is in the exclusion list
int is_excluded(const char *exclusion_list, const char *file_name) {
    char *token = strtok(exclusion_list, ",");
    while (token != NULL) {
        if (strcmp(token, file_name) == 0) {
            return 1;
        }
        token = strtok(NULL, ",");
    }
    return 0;
}

// function to synchronize two directories
int synchronize_directories(const char *source_dir, const char *target_dir, const char *exclusion_list) {
    struct dirent *dp;
    struct stat st;
    int result = 0;
    char source_file[256], target_file[256];
    DIR *dir = opendir(source_dir);
    if (!dir) {
        printf("Unable to open directory %s\n", source_dir);
        return -1;
    }
    // loop through each file/directory in source_dir
    while ((dp = readdir(dir)) != NULL) {
        // ignore . and ..
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }
        snprintf(source_file, 256, "%s/%s", source_dir, dp->d_name);
        snprintf(target_file, 256, "%s/%s", target_dir, dp->d_name);
        if (is_excluded(exclusion_list, dp->d_name)) {
            continue;
        }
        if (stat(source_file, &st) == 0) {
            if (S_ISDIR(st.st_mode)) { // if it's a directory, create the same directory in target_dir
                mkdir(target_file, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
                result = synchronize_directories(source_file, target_file, exclusion_list); // synchronize the subdirectory
            } else { // if it's a file, check if it already exists in target_dir
                if (stat(target_file, &st) == 0) {
                    if (st.st_mtime < st.st_ctime) { // if target file is older than source file, update target file
                        result = copy_file(source_file, target_file);
                    }
                } else { // if target file doesn't exist, create it
                    result = copy_file(source_file, target_file);
                }
            }
        }
        if (result != 0) { // if there is any error, break the loop
            break;
        } 
    }
    closedir(dir);
    return result;
}

// function to read synchronization settings from a file and synchronize the directories accordingly
int synchronize_from_file(const char *filename) {
    FILE *fp;
    char line[512];
    struct sync_setting ss;
    int result = 0;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open %s\n", filename);
        return -1;
    }
    while (fgets(line, 512, fp)) {
        if (line[strlen(line)-1] == '\n') {
            line[strlen(line)-1] = '\0';
        }
        sscanf(line, "%s %s %s", ss.source_dir, ss.target_dir, ss.exclusion_list);
        result = synchronize_directories(ss.source_dir, ss.target_dir, ss.exclusion_list);
        if (result != 0) { // if there is any error, break the loop
            break;
        }
    }
    fclose(fp);
    return result;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide the configuration file name\n");
        return -1;
    }
    int result = synchronize_from_file(argv[1]);
    if (result == 0) {
        printf("Done\n");
    } else {
        printf("Failed\n");
    }
    return result;
}