//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>

#define MAX_PATH_LEN 1000
#define MAX_FILE_NAME_LEN 100
#define MAX_DIR_NAME_LEN 100

typedef struct {
    char path[MAX_PATH_LEN];
    long long total_size;
    long long num_files;
    long long num_dirs;
} dir_stats_t;

void print_dir_stats(dir_stats_t *stats) {
    printf("Directory: %s\n", stats->path);
    printf("Total size: %lld bytes\n", stats->total_size);
    printf("Number of files: %lld\n", stats->num_files);
    printf("Number of directories: %lld\n", stats->num_dirs);
    printf("\n");
}

void count_dir_size(const char *dir_path, dir_stats_t *stats) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        return;
    }

    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        char path[MAX_PATH_LEN];
        sprintf(path, "%s/%s", dir_path, ent->d_name);

        struct stat file_stat;
        if (stat(path, &file_stat) == 0) {
            if (S_ISDIR(file_stat.st_mode)) {
                stats->num_dirs++;
                count_dir_size(path, stats);
            } else {
                stats->num_files++;
                stats->total_size += file_stat.st_size;
            }
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    dir_stats_t stats;
    strcpy(stats.path, argv[1]);

    count_dir_size(argv[1], &stats);

    print_dir_stats(&stats);

    return 0;
}