//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE (1024 * 1024) // 1MB
#define MAX_BACKUP_FILES 10
#define DATE_TIME_FORMAT "%Y%m%d%H%M%S"

struct backup_file {
    char filename[100];
    time_t timestamp;
};

void backup_file(char *filename) {
    FILE *fp_in, *fp_out;
    char buf[MAX_FILE_SIZE];
    int len;
    time_t now = time(NULL);
    struct backup_file backup_files[MAX_BACKUP_FILES];
    int num_backup_files = 0;

    sprintf(buf, "%s.%ld", filename, now);
    fp_out = fopen(buf, "wb");
    if (fp_out == NULL) {
        printf("Error: could not create backup file.\n");
        exit(1);
    }

    fp_in = fopen(filename, "rb");
    if (fp_in == NULL) {
        printf("Error: could not open input file.\n");
        fclose(fp_out);
        remove(buf);
        exit(1);
    }

    while ((len = fread(buf, 1, MAX_FILE_SIZE, fp_in)) > 0) {
        fwrite(buf, 1, len, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);

    strcpy(backup_files[num_backup_files].filename, filename);
    backup_files[num_backup_files].timestamp = now;
    num_backup_files++;

    if (num_backup_files > MAX_BACKUP_FILES) {
        remove(backup_files[0].filename);
        num_backup_files--;
    }

    printf("Backup complete.\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    backup_file(argv[1]);

    return 0;
}