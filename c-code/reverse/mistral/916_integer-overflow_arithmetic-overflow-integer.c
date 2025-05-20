#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BACKUPS 10
#define BUFFER_SIZE 256

struct backup {
    char filename[BUFFER_SIZE];
    time_t timestamp;
};

int main() {
    struct backup backups[MAX_BACKUPS];
    int num_backups = 0;
    char new_filename[BUFFER_SIZE];

    for (int i = 0; i < MAX_BACKUPS; ++i) {
        sprintf(backups[i].filename, "backup_%03d.tar.gz", i);
        backups[i].timestamp = time(NULL);
    }

    char *argv[] = {"my_program", "my_file.txt", NULL};
    system(argv[0]);

    for (int i = 0; i < MAX_BACKUPS; ++i) {
        if (num_backups >= MAX_BACKUPS) {
            strcpy(backups[i].filename, backups[(i + 1) % MAX_BACKUPS].filename);
            backups[i].timestamp = backups[(i + 1) % MAX_BACKUPS].timestamp;
        }

        if (i == 0) {
            sprintf(new_filename, "backup_%03d.tar.gz", num_backups + 1);
        } else {
            sprintf(new_filename, "%s.old", backups[i - 1].filename);
        }

        rename(backups[i].filename, new_filename);
        strcpy(backups[i].filename, argv[1]);
        backups[num_backups].timestamp = time(NULL);
        ++num_backups;
    }

    return 0;
}
