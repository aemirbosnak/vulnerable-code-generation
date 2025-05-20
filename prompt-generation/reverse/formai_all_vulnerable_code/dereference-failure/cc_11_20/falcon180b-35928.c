//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file {
    char *name;
    char *path;
    int size;
    char *backup_path;
};

int main() {
    int num_files;
    struct file *files;

    printf("Enter the number of files to backup: ");
    scanf("%d", &num_files);

    files = (struct file *) malloc(num_files * sizeof(struct file));

    for (int i = 0; i < num_files; i++) {
        printf("Enter the name of file %d: ", i+1);
        scanf("%s", files[i].name);
        printf("Enter the path of file %s: ", files[i].name);
        scanf("%s", files[i].path);
        files[i].size = 0;
        strcpy(files[i].backup_path, "");
    }

    for (int i = 0; i < num_files; i++) {
        FILE *fp = fopen(files[i].path, "rb");
        if (fp == NULL) {
            printf("Error: File %s not found.\n", files[i].path);
            exit(1);
        }
        fseek(fp, 0, SEEK_END);
        files[i].size = ftell(fp);
        fclose(fp);
    }

    for (int i = 0; i < num_files; i++) {
        strcat(files[i].backup_path, files[i].path);
        strcat(files[i].backup_path, ".bak");
        printf("Backup path for %s: %s\n", files[i].name, files[i].backup_path);
    }

    printf("Enter the directory to store backups: ");
    scanf("%s", files[0].backup_path);

    for (int i = 0; i < num_files; i++) {
        strcpy(files[i].backup_path, files[0].backup_path);
        strcat(files[i].backup_path, "/");
        strcat(files[i].backup_path, files[i].name);
        strcat(files[i].backup_path, ".bak");
    }

    for (int i = 0; i < num_files; i++) {
        if (files[i].size > 0) {
            FILE *fp_in = fopen(files[i].path, "rb");
            FILE *fp_out = fopen(files[i].backup_path, "wb");

            if (fp_in == NULL || fp_out == NULL) {
                printf("Error: Could not open file.\n");
                exit(1);
            }

            char buffer[1024];
            int bytes_read;

            while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp_in)) > 0) {
                fwrite(buffer, 1, bytes_read, fp_out);
            }

            fclose(fp_in);
            fclose(fp_out);
        }
    }

    printf("Backup complete.\n");

    return 0;
}