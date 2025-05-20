//Code Llama-13B DATASET v1.0 Category: System administration ; Style: secure
// Secure System Administration Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>

// Function to check if a file exists
int file_exists(const char *filename) {
    struct stat st;
    return (stat(filename, &st) == 0);
}

// Function to check if a file is writable
int file_writable(const char *filename) {
    struct stat st;
    return (stat(filename, &st) == 0 && (st.st_mode & S_IWUSR));
}

// Function to check if a file is executable
int file_executable(const char *filename) {
    struct stat st;
    return (stat(filename, &st) == 0 && (st.st_mode & S_IXUSR));
}

// Function to check if a file is owned by the current user
int file_owned_by_current_user(const char *filename) {
    struct passwd *pw = getpwuid(getuid());
    return (pw != NULL && strcmp(pw->pw_name, filename) == 0);
}

// Function to check if a file is owned by a specific group
int file_owned_by_group(const char *filename, const char *group) {
    struct group *gr = getgrnam(group);
    return (gr != NULL && strcmp(gr->gr_name, filename) == 0);
}

// Function to check if a file is readable
int file_readable(const char *filename) {
    struct stat st;
    return (stat(filename, &st) == 0 && (st.st_mode & S_IRUSR));
}

// Function to check if a file is deletable
int file_deletable(const char *filename) {
    struct stat st;
    return (stat(filename, &st) == 0 && (st.st_mode & S_IXUSR));
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    if (file_exists(filename)) {
        printf("File exists\n");
    } else {
        printf("File does not exist\n");
    }

    if (file_writable(filename)) {
        printf("File is writable\n");
    } else {
        printf("File is not writable\n");
    }

    if (file_executable(filename)) {
        printf("File is executable\n");
    } else {
        printf("File is not executable\n");
    }

    if (file_owned_by_current_user(filename)) {
        printf("File is owned by current user\n");
    } else {
        printf("File is not owned by current user\n");
    }

    if (file_owned_by_group(filename, "admin")) {
        printf("File is owned by group 'admin'\n");
    } else {
        printf("File is not owned by group 'admin'\n");
    }

    if (file_readable(filename)) {
        printf("File is readable\n");
    } else {
        printf("File is not readable\n");
    }

    if (file_deletable(filename)) {
        printf("File is deletable\n");
    } else {
        printf("File is not deletable\n");
    }

    return 0;
}