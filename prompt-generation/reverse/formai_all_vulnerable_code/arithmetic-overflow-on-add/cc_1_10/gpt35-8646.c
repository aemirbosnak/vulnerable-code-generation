//FormAI DATASET v1.0 Category: Data recovery tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a struct for holding file metadata
typedef struct {
    char filename[256];
    int size;
    char date_created[20];
} File;

// define a function for parsing the contents of a damaged file system
void recover_files(char* disk_image_path) {
    // read the contents of the disk image file
    FILE* disk_image_file = fopen(disk_image_path, "r");
    fseek(disk_image_file, 0L, SEEK_END);
    int disk_image_size = ftell(disk_image_file);
    rewind(disk_image_file);
    char* disk_image = (char*) malloc(disk_image_size+1);
    fread(disk_image, 1, disk_image_size, disk_image_file);
    fclose(disk_image_file);

    // search for the file system metadata
    char* metadata_header = "FILESYSTEM_METADATA";
    char* metadata_start = strstr(disk_image, metadata_header);
    if(metadata_start == NULL) {
        printf("ERROR: Could not find file system metadata.");
        return;
    }
    metadata_start += strlen(metadata_header) + 1;

    // parse the file system metadata and display the recovered files
    int num_files = *(int*) metadata_start;
    metadata_start += sizeof(int);
    File* files = (File*) malloc(num_files * sizeof(File));
    for(int i = 0; i < num_files; i++) {
        strcpy(files[i].filename, metadata_start);
        metadata_start += strlen(metadata_start) + 1;
        files[i].size = *(int*) metadata_start;
        metadata_start += sizeof(int);
        strcpy(files[i].date_created, metadata_start);
        metadata_start += strlen(metadata_start) + 1;
    }
    printf("RECOVERED FILES:\n");
    for(int i = 0; i < num_files; i++) {
        printf("%s (%d bytes, created on %s)\n", files[i].filename, files[i].size, files[i].date_created);
    }
}

// sample usage
int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("USAGE: %s disk_image_file\n", argv[0]);
        return 1;
    }
    char* disk_image_path = argv[1];
    recover_files(disk_image_path);
    return 0;
}