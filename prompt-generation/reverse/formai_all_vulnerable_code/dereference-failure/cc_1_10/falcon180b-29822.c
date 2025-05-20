//Falcon-180B DATASET v1.0 Category: System administration ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>

#define MAX_PATH 1024

typedef struct dirent dirent;

void print_usage(void) {
    printf("Usage:./program [directory]\n");
    exit(1);
}

void print_file_info(dirent *file, time_t raw_time) {
    char time_buffer[26];
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M", localtime(&raw_time));
    printf("%s %10lu %s\n", file->d_name, file->d_ino, time_buffer);
}

void print_directory_info(char *directory) {
    DIR *dir;
    dirent *file;
    time_t raw_time;

    if ((dir = opendir(directory)) == NULL) {
        perror("");
        exit(1);
    }

    raw_time = time(NULL);

    while ((file = readdir(dir))!= NULL) {
        if (strcmp(file->d_name, ".")!= 0 && strcmp(file->d_name, "..")!= 0) {
            print_file_info(file, raw_time);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        print_usage();
    }

    print_directory_info(argv[1]);

    return 0;
}