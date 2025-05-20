//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFF_SIZE 1024

typedef struct {
    char dir_path[1024];
    char remote_path[1024];
} Config;

int read_config(char *filename, Config *config) {
    FILE *fp;
    char line[1024];

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error opening config file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        sscanf(line, "%s %s", config->dir_path, config->remote_path);
    }

    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]) {
    Config config;
    DIR *dir;
    struct dirent *ent;
    char remote_file[1024];
    char local_file[1024];
    char command[1024];
    FILE *fp;

    if (argc!= 2) {
        printf("Usage: %s <config_file>\n", argv[0]);
        exit(1);
    }

    if (read_config(argv[1], &config)!= 0) {
        exit(1);
    }

    if ((dir = opendir(config.dir_path)) == NULL) {
        printf("Error opening directory.\n");
        exit(1);
    }

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type!= DT_REG) {
            continue;
        }

        strcpy(local_file, config.dir_path);
        strcat(local_file, "/");
        strcat(local_file, ent->d_name);

        strcpy(remote_file, config.remote_path);
        strcat(remote_file, "/");
        strcat(remote_file, ent->d_name);

        sprintf(command, "rsync -avz -e ssh %s %s", remote_file, local_file);
        if (system(command)!= 0) {
            printf("Error syncing file: %s\n", ent->d_name);
        }
    }

    closedir(dir);
    return 0;
}