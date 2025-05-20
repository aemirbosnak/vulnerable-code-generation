//Falcon-180B DATASET v1.0 Category: System administration ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <pwd.h>

#define MAX_LINE_LEN 1024
#define MAX_USER_NAME_LEN 32

struct user_info {
    char username[MAX_USER_NAME_LEN];
    uid_t uid;
    gid_t gid;
};

int main() {
    int fd;
    char filename[MAX_LINE_LEN];
    struct passwd *user_info;
    struct user_info user_data;
    int ret;
    int i;

    printf("Enter the name of the file to be read: ");
    scanf("%s", filename);

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    user_info = getpwuid(getuid());
    strncpy(user_data.username, user_info->pw_name, MAX_USER_NAME_LEN);
    user_data.uid = getuid();
    user_data.gid = getgid();

    ret = read(fd, &user_data, sizeof(user_data));
    if (ret == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    printf("Data read from file:\n");
    printf("Username: %s\n", user_data.username);
    printf("UID: %d\n", user_data.uid);
    printf("GID: %d\n", user_data.gid);

    close(fd);

    return 0;
}