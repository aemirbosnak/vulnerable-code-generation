//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return 1;
    }
    
    struct stat sb;
    int fd, r, w;
    char buf[BUFSIZ], *p;
    DIR *dp;
    struct dirent *ep;
    char source_dir[100], destination_dir[100];
    int file_count = 0;
    
    // Get the source and destination directories from the command line arguments
    strcpy(source_dir, argv[1]);
    strcpy(destination_dir, argv[2]);
    
    // Open the source directory and get its current file attributes
    if ((fd = open(source_dir, O_RDONLY)) == -1) {
        perror("open");
        return 1;
    }
    if (fstat(fd, &sb) == -1) {
        perror("fstat");
        return 1;
    }
    
    // Open the destination directory and create any missing subdirectories
    if ((w = open(destination_dir, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1) {
        perror("open");
        return 1;
    }
    
    // Iterate through each file in the source directory
    dp = opendir(source_dir);
    while (ep = readdir(dp)) {
        if (ep->d_name[0] == '.')
            continue;
        if (strcmp(ep->d_name, ".") == 0 || strcmp(ep->d_name, "..") == 0)
            continue;
        file_count++;
        
        // Create a temporary copy of the source file
        if ((fd = open(source_dir, O_RDONLY)) == -1) {
            perror("open");
            return 1;
        }
        if (fstat(fd, &sb) == -1) {
            perror("fstat");
            return 1;
        }
        if ((r = creat(destination_dir, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1) {
            perror("creat");
            return 1;
        }
        
        // Write the contents of the source file to the destination file
        if ((w = open(destination_dir, O_WRONLY)) == -1) {
            perror("open");
            return 1;
        }
        while ((r = read(fd, buf, sizeof(buf))) > 0) {
            if ((w = write(w, buf, r)) == -1) {
                perror("write");
                return 1;
            }
        }
        if (close(fd) == -1) {
            perror("close");
            return 1;
        }
        
        // Clean up the temporary file
        if (unlink(destination_dir) == -1) {
            perror("unlink");
            return 1;
        }
        
        // Print a progress message
        if ((p = strrchr(ep->d_name, '.'))!= NULL) {
            *p = '\0';
            printf("%s (%d/%d)\n", ep->d_name, file_count, sb.st_size);
        } else {
            printf("%s (%d/%d)\n", ep->d_name, file_count, sb.st_size);
        }
    }
    if (closedir(dp) == -1) {
        perror("closedir");
        return 1;
    }
    
    // Close the source directory
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }
    
    printf("File synchronization complete.\n");
    return 0;
}