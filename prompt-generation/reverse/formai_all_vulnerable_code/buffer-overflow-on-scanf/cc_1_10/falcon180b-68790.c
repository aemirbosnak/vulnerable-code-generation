//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024

int main() {
    char line[MAX_LINE_LENGTH];
    FILE *fp;
    char *file_name;
    char *mode;
    int fd;
    struct statvfs buf;
    long total_space, available_space;
    float used_space;

    // Prompt user for file name
    printf("Enter file name: ");
    scanf("%s", file_name);

    // Open file in read mode
    mode = "r";
    fp = fopen(file_name, mode);

    // Check if file is open
    if (fp == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    // Get the file size
    fseek(fp, 0L, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    // Check for errors
    if (file_size < 0) {
        printf("Error getting file size: %s\n", strerror(errno));
        fclose(fp);
        exit(1);
    }

    // Open file in read mode
    fd = open(file_name, O_RDONLY);

    // Check if file is open
    if (fd < 0) {
        printf("Error opening file: %s\n", strerror(errno));
        fclose(fp);
        exit(1);
    }

    // Get the disk usage information
    if (fstatvfs(fd, &buf) < 0) {
        printf("Error getting disk usage information: %s\n", strerror(errno));
        close(fd);
        fclose(fp);
        exit(1);
    }

    // Calculate the total and available space
    total_space = buf.f_blocks * buf.f_frsize;
    available_space = buf.f_bavail * buf.f_frsize;

    // Calculate the used space
    used_space = total_space - available_space;

    // Print the results
    printf("File name: %s\n", file_name);
    printf("File size: %ld bytes\n", file_size);
    printf("Total disk space: %ld bytes\n", total_space);
    printf("Available disk space: %ld bytes\n", available_space);
    printf("Used disk space: %ld bytes\n", used_space);

    // Close the file and exit
    fclose(fp);
    close(fd);
    exit(0);
}