//FormAI DATASET v1.0 Category: File Synchronizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argC, char *argV[]) {

    if (argC != 3){
        printf("Usage: ./fileSync source_directory target_directory\n");
        exit(1);
    }

    DIR *src, *dst;

    struct dirent *readSrc, *readDst;
    struct stat src_file_info, dst_file_info;

    char src_dir[100], dst_dir[100];
    char src_path[110], dst_path[110];

    int src_fd, dst_fd;
    int returnReadSrc, returnReadDst;
    int closeSrc, closeDst;
    int bytesWritten;

    realpath(argV[1], src_dir);
    realpath(argV[2], dst_dir);

    src = opendir(src_dir);
    dst = opendir(dst_dir);

    if (src == NULL || dst == NULL){
        printf("Error: Unable to open source or destination directory\n");
        exit(1);
    }

    // iterate over files in source directory
    while ((readSrc = readdir(src))) {

        if (!strcmp(readSrc->d_name, ".") || !strcmp(readSrc->d_name, "..")){
            continue;
        }

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, readSrc->d_name);

        // check if the file exists in the destination directory
        if (stat(src_path, &src_file_info) == -1){
            printf("Error: Unable to get file info for %s\n", src_path);
            continue;
        }

        strcpy(dst_path, dst_dir);
        strcat(dst_path, "/");
        strcat(dst_path, readSrc->d_name);

        if (stat(dst_path, &dst_file_info) == -1){
            printf("%s does not exist in target directory, creating...\n", readSrc->d_name);
            dst_fd = creat(dst_path, src_file_info.st_mode);
            close(dst_fd);
        }

        // check if the files already have the same modification date
        if (src_file_info.st_mtime == dst_file_info.st_mtime){
            printf("%s is already up-to-date in target directory\n", readSrc->d_name);
            continue;
        }

        // open the files for reading and writing
        src_fd = open(src_path, O_RDONLY);
        dst_fd = open(dst_path, O_WRONLY);

        // verify if both files were opened successfully
        if (src_fd == -1 || dst_fd == -1){
            printf("%s can't be opened for synchronisation\n", readSrc->d_name);
            continue;
        }

        // read and write file data
        char buffer[1000];

        while ((returnReadSrc = read(src_fd, buffer, sizeof(buffer))) > 0){
            bytesWritten = write(dst_fd, buffer, returnReadSrc);
        }

        printf("%s has been synchronized successfully.\n", readSrc->d_name);

        closeSrc = close(src_fd);
        closeDst = close(dst_fd);

    }

    closedir(src);
    closedir(dst);
    return 0;
}