//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: automated
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file or directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *path = argv[1];
    struct stat st;
    if (lstat(path, &st) == -1) {
        perror("lstat");
        return EXIT_FAILURE;
    }

    printf("File: %s\n", path);
    printf("Type: ");
    switch (st.st_mode & S_IFMT) {
    case S_IFREG:  printf("Regular file\n"); break;
    case S_IFDIR:  printf("Directory\n"); break;
    case S_IFLNK:  printf("Symbolic link\n"); break;
    case S_IFBLK:  printf("Block device\n"); break;
    case S_IFCHR:  printf("Character device\n"); break;
    case S_IFSOCK: printf("Socket\n"); break;
    case S_IFIFO:  printf("FIFO\n"); break;
    default:       printf("Unknown file type\n"); break;
    }

    printf("Size: %ld bytes\n", st.st_size);
    printf("Permissions: %o\n", st.st_mode);
    printf("Owner: %s\n", getpwuid(st.st_uid)->pw_name);
    printf("Group: %s\n", getgrgid(st.st_gid)->gr_name);
    printf("Last modified: %s", ctime(&st.st_mtime));
    printf("Last accessed: %s", ctime(&st.st_atime));
    printf("Last status change: %s", ctime(&st.st_ctime));

    if (S_ISDIR(st.st_mode)) {
        DIR *dir = opendir(path);
        if (dir == NULL) {
            perror("opendir");
            return EXIT_FAILURE;
        }

        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            printf("  %s\n", entry->d_name);
        }

        closedir(dir);
    }

    return EXIT_SUCCESS;
}