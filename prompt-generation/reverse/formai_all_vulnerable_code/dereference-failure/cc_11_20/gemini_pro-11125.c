//GEMINI-pro DATASET v1.0 Category: System administration ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main() {
    struct stat sb;
    struct passwd *pwd;
    struct group *grp;
    char buf[1024];
    char *filename = "myfile.txt";

    // Stat the file
    if (stat(filename, &sb) == -1) {
        perror("stat");
        return 1;
    }

    // Get the file owner's username
    pwd = getpwuid(sb.st_uid);
    if (pwd == NULL) {
        perror("getpwuid");
        return 1;
    }

    // Get the file group's name
    grp = getgrgid(sb.st_gid);
    if (grp == NULL) {
        perror("getgrgid");
        return 1;
    }

    // Print the file information
    printf("File: %s\n", filename);
    printf("Size: %ld bytes\n", sb.st_size);
    printf("Owner: %s\n", pwd->pw_name);
    printf("Group: %s\n", grp->gr_name);
    printf("Permissions: %o\n", sb.st_mode);
    printf("Last modified: %s", ctime(&sb.st_mtime));

    // Check if the file is a regular file
    if (S_ISREG(sb.st_mode)) {
        printf("File is a regular file.\n");
    } else if (S_ISDIR(sb.st_mode)) {
        printf("File is a directory.\n");
    } else if (S_ISCHR(sb.st_mode)) {
        printf("File is a character device.\n");
    } else if (S_ISBLK(sb.st_mode)) {
        printf("File is a block device.\n");
    } else if (S_ISFIFO(sb.st_mode)) {
        printf("File is a FIFO.\n");
    } else if (S_ISLNK(sb.st_mode)) {
        printf("File is a symbolic link.\n");
    } else if (S_ISSOCK(sb.st_mode)) {
        printf("File is a socket.\n");
    } else {
        printf("File is of unknown type.\n");
    }

    // Read the file's contents
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    while (fgets(buf, sizeof(buf), fp) != NULL) {
        printf("%s", buf);
    }

    fclose(fp);

    return 0;
}