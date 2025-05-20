//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: inquisitive
// Delve into the enigmatic realm of file metadata with this captivating example!

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    // Embark on a metadata-mining adventure with this curious code!

    char realpath_buf[PATH_MAX];
    char *resolved_path = realpath(argv[1], realpath_buf);
    if (resolved_path == NULL) {
        perror("realpath");
        return 1;
    }

    printf("Unveiling the secrets hidden within %s...\n\n", resolved_path);

    struct stat metadata;
    if (stat(resolved_path, &metadata) == -1) {
        perror("stat");
        return 1;
    }

    printf("Inquisitive questions and their illuminating answers:\n\n");

    // Uncover the file's numeric user ID and group ID
    printf("Who owns this file (UID): %ld\n", metadata.st_uid);
    printf("Which group does it belong to (GID): %ld\n", metadata.st_gid);

    // Dig deeper into the identity of the file's owner and group
    struct passwd *user_info = getpwuid(metadata.st_uid);
    if (user_info != NULL) {
        printf("File owner's username: %s\n", user_info->pw_name);
    } else {
        printf("Unable to determine file owner's username.\n");
    }

    struct group *group_info = getgrgid(metadata.st_gid);
    if (group_info != NULL) {
        printf("File group's name: %s\n", group_info->gr_name);
    } else {
        printf("Unable to determine file group's name.\n");
    }

    // Time to explore the file's temporal dimensions
    printf("File's last modification time: %s", ctime(&metadata.st_mtime));
    printf("File's last access time: %s", ctime(&metadata.st_atime));
    printf("File's creation time: %s", ctime(&metadata.st_ctime));

    // Dive into the depths of file permissions
    printf("File's permissions (octal): %o\n", metadata.st_mode);
    printf("File's permissions (symbolic): ");

    // Decipher the file type from its mode
    if (S_ISREG(metadata.st_mode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(metadata.st_mode)) {
        printf("Directory\n");
    } else if (S_ISCHR(metadata.st_mode)) {
        printf("Character device\n");
    } else if (S_ISBLK(metadata.st_mode)) {
        printf("Block device\n");
    } else if (S_ISFIFO(metadata.st_mode)) {
        printf("FIFO (named pipe)\n");
    } else if (S_ISLNK(metadata.st_mode)) {
        printf("Symbolic link\n");
    } else if (S_ISSOCK(metadata.st_mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown file type\n");
    }

    // Conclude this metaphysical journey with the file's size
    printf("File size (bytes): %ld\n", metadata.st_size);

    return 0;
}