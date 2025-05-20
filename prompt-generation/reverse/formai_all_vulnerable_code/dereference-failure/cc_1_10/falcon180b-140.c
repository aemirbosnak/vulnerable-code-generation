//Falcon-180B DATASET v1.0 Category: System administration ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

/* Function prototypes */
void print_users(char *filename);
void print_groups(char *filename);
int compare_names(const void *a, const void *b);
int compare_gids(const void *a, const void *b);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    FILE *file;

    if ((file = fopen(filename, "r")) == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    struct passwd *pwd;
    struct group *grp;

    /* Read users from file */
    while ((pwd = getpwent())!= NULL) {
        printf("User: %s\n", pwd->pw_name);
    }
    endpwent();

    /* Read groups from file */
    while ((grp = getgrent())!= NULL) {
        printf("Group: %s\n", grp->gr_name);
    }
    endgrent();

    fclose(file);
    return 0;
}

void print_users(char *filename) {
    FILE *file;
    struct passwd *pwd;

    if ((file = fopen(filename, "r")) == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    while ((pwd = getpwent())!= NULL) {
        printf("User: %s\n", pwd->pw_name);
    }

    endpwent();
    fclose(file);
}

void print_groups(char *filename) {
    FILE *file;
    struct group *grp;

    if ((file = fopen(filename, "r")) == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    while ((grp = getgrent())!= NULL) {
        printf("Group: %s\n", grp->gr_name);
    }

    endgrent();
    fclose(file);
}

int compare_names(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int compare_gids(const void *a, const void *b) {
    return *(gid_t *)a - *(gid_t *)b;
}