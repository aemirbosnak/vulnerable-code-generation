//Falcon-180B DATASET v1.0 Category: System administration ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

void print_dir(const char* path) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error: %s\n", strerror(errno));
        return;
    }

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        printf("%s\n", ent->d_name);
    }

    closedir(dir);
}

void create_file(const char* path, const char* content) {
    FILE* file = fopen(path, "w");
    if (file == NULL) {
        printf("Error: %s\n", strerror(errno));
        return;
    }

    fprintf(file, "%s", content);
    fclose(file);
}

void append_to_file(const char* path, const char* content) {
    FILE* file = fopen(path, "a");
    if (file == NULL) {
        printf("Error: %s\n", strerror(errno));
        return;
    }

    fprintf(file, "%s", content);
    fclose(file);
}

int main() {
    const char* dir_path = "./test_dir";
    mkdir(dir_path, 0755);

    print_dir(dir_path);

    const char* file_path = "./test_dir/test.txt";
    create_file(file_path, "Hello, world!");

    print_dir(dir_path);

    const char* append_content = "\nThis is a test.";
    append_to_file(file_path, append_content);

    print_dir(dir_path);

    return 0;
}