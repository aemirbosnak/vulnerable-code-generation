//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 4096

typedef struct {
    char *name;
    int size;
    int start_sector;
    int end_sector;
    int is_deleted;
} FileEntry;

typedef struct {
    int num_files;
    FileEntry *files;
} Directory;

void print_file_entry(FileEntry *entry) {
    printf("Name: %s\n", entry->name);
    printf("Size: %d bytes\n", entry->size);
    printf("Start Sector: %d\n", entry->start_sector);
    printf("End Sector: %d\n", entry->end_sector);
    printf("Is Deleted: %s\n\n", entry->is_deleted? "Yes" : "No");
}

int compare_file_entries(const void *a, const void *b) {
    FileEntry *entry1 = (FileEntry *)a;
    FileEntry *entry2 = (FileEntry *)b;
    return strcmp(entry1->name, entry2->name);
}

Directory *read_directory(int fd) {
    Directory *dir = malloc(sizeof(Directory));
    dir->num_files = 0;
    dir->files = NULL;
    int ret = read(fd, dir, sizeof(Directory));
    if (ret!= sizeof(Directory)) {
        printf("Error reading directory.\n");
        exit(1);
    }
    return dir;
}

void free_directory(Directory *dir) {
    if (dir->files!= NULL) {
        for (int i = 0; i < dir->num_files; i++) {
            free(dir->files[i].name);
        }
        free(dir->files);
    }
    free(dir);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        exit(1);
    }
    int img_fd = open(argv[1], O_RDONLY);
    if (img_fd == -1) {
        printf("Error opening image file.\n");
        exit(1);
    }
    Directory *root_dir = read_directory(img_fd);
    qsort(root_dir->files, root_dir->num_files, sizeof(FileEntry), compare_file_entries);
    for (int i = 0; i < root_dir->num_files; i++) {
        print_file_entry(&root_dir->files[i]);
    }
    free_directory(root_dir);
    close(img_fd);
    return 0;
}