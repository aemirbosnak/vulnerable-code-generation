//Falcon-180B DATASET v1.0 Category: System administration ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>

#define MAX_LINE_LENGTH 1024

char *get_username(uid_t uid) {
    struct passwd *pw;
    char *username = NULL;

    if ((pw = getpwuid(uid))!= NULL) {
        username = strdup(pw->pw_name);
    }

    return username;
}

char *get_groupname(gid_t gid) {
    struct group *gr;
    char *groupname = NULL;

    if ((gr = getgrgid(gid))!= NULL) {
        groupname = strdup(gr->gr_name);
    }

    return groupname;
}

int main(int argc, char **argv) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *delimiter = ":";
    char *token;
    char *username = NULL;
    char *groupname = NULL;
    char *filename = NULL;
    uid_t uid;
    gid_t gid;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    filename = argv[1];

    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        token = strtok(line, delimiter);
        uid = atoi(token);
        username = get_username(uid);
        token = strtok(NULL, delimiter);
        gid = atoi(token);
        groupname = get_groupname(gid);

        printf("UID: %d\n", uid);
        printf("Username: %s\n", username);
        printf("GID: %d\n", gid);
        printf("Groupname: %s\n\n", groupname);
    }

    fclose(fp);

    return 0;
}