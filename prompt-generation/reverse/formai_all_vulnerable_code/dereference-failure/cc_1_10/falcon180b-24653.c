//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILENAME_LEN 100
#define BACKUP_DIR "backup"

struct file {
    char filename[MAX_FILENAME_LEN];
    time_t last_modified;
};

struct file *files[MAX_FILES];
int num_files = 0;

void add_file(char *filename) {
    struct file *f = malloc(sizeof(struct file));
    strcpy(f->filename, filename);
    f->last_modified = time(NULL);
    files[num_files++] = f;
}

void backup_files() {
    char backup_filename[MAX_FILENAME_LEN];
    time_t current_time = time(NULL);
    struct tm *tm = localtime(&current_time);
    sprintf(backup_filename, "%s/%04d%02d%02d_%02d%02d%02d", BACKUP_DIR,
            tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour,
            tm->tm_min, tm->tm_sec);
    mkdir(BACKUP_DIR, 0777);
    mkdir(backup_filename, 0777);
    for (int i = 0; i < num_files; i++) {
        char dest_filename[MAX_FILENAME_LEN];
        sprintf(dest_filename, "%s/%s", backup_filename, files[i]->filename);
        FILE *src_file = fopen(files[i]->filename, "rb");
        FILE *dest_file = fopen(dest_filename, "wb");
        fseek(src_file, 0, SEEK_END);
        long file_size = ftell(src_file);
        rewind(src_file);
        char buffer[1024];
        while (fread(buffer, 1, 1024, src_file) > 0) {
            fwrite(buffer, 1, 1024, dest_file);
        }
        fclose(src_file);
        fclose(dest_file);
    }
}

void check_files() {
    for (int i = 0; i < num_files; i++) {
        if (files[i]->last_modified!= time(NULL)) {
            backup_files();
        }
    }
}

int main() {
    add_file("test.txt");
    add_file("example.cpp");
    while (1) {
        check_files();
        sleep(60);
    }
    return 0;
}