//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_FILE_NAME 256
#define MAX_DIR_NAME 256
#define MAX_BUF_SIZE 1024

struct FileInfo {
    char file_name[MAX_FILE_NAME];
    char dir_name[MAX_DIR_NAME];
    time_t mod_time;
};

void backup_file(char *file_name, char *dir_name) {
    FILE *fp = fopen(file_name, "r");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    char *buf = malloc(MAX_BUF_SIZE);
    if (!buf) {
        fclose(fp);
        perror("Error allocating memory");
        return;
    }

    struct FileInfo info;
    strcpy(info.file_name, file_name);
    strcpy(info.dir_name, dir_name);
    info.mod_time = time(NULL);

    while (fgets(buf, MAX_BUF_SIZE, fp)) {
        fprintf(stdout, "%s", buf);
        fputs(buf, stdout);
    }

    free(buf);
    fclose(fp);

    FILE *fp_backup = fopen(dir_name, "w");
    if (!fp_backup) {
        perror("Error opening backup file");
        return;
    }

    fwrite(&info, sizeof(struct FileInfo), 1, fp_backup);
    fwrite(buf, strlen(buf), 1, fp_backup);
    fclose(fp_backup);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file_name> <dir_name>\n", argv[0]);
        return 1;
    }

    backup_file(argv[1], argv[2]);

    return 0;
}