//FormAI DATASET v1.0 Category: Data recovery tool ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FILE_NAME_LEN 128
#define SECTOR_SIZE 512
#define MAX_FILES 10000

typedef struct file_metadata {
    char file_name[FILE_NAME_LEN];
    int start_sector;
    int file_size;
    bool is_found;
} t_file_metadata;

int main(int argc, char* argv[])
{
    FILE* disk = NULL;
    char* sector = (char*)malloc(SECTOR_SIZE);

    if(argc < 2) {
        printf("Missing disk file name. Usage: %s <disk_file_name>\n", argv[0]);
        return -1;
    }

    disk = fopen(argv[1], "rb");
    if(!disk) {
        printf("Unable to open disk %s\n", argv[1]);
        return -2;
    }

    t_file_metadata file[MAX_FILES];
    memset(file, 0, MAX_FILES * sizeof(t_file_metadata));

    int num_files = 0;
    int disk_size = 0;
    fseek(disk, 0, SEEK_END);
    disk_size = ftell(disk);
    fseek(disk, 0, SEEK_SET);

    int sec_cnt = 0;
    while(!feof(disk)) {
        fread(sector, sizeof(char), SECTOR_SIZE, disk);

        if(memcmp(sector, "FILE", 4) == 0) {
            int file_size = ((int*)sector)[1];
            int file_start_sector = sec_cnt + 1;
            char* file_name = sector + 12;

            if((num_files + 1) * sizeof(t_file_metadata) > MAX_FILES * sizeof(t_file_metadata)) {
                printf("ERROR: Too many files found on the disk. Maximum capacity is %d files.\n", MAX_FILES);
                fclose(disk);
                free(sector);
                return -3;
            }

            if(file_start_sector * SECTOR_SIZE + file_size > disk_size) {
                printf("WARNING: Invalid file boundaries for file %s.\n", file_name);
                continue;
            }

            memcpy(file[num_files].file_name, file_name, strlen(file_name)+1);
            file[num_files].start_sector = file_start_sector;
            file[num_files].file_size = file_size;
            file[num_files].is_found = false;
        
            num_files++;
        }
        
        sec_cnt++;
    }

    printf("%d Files found on disk.\n", num_files);

    printf("Scan disk for missing or corrupted files (Y/N)? ");
    char answer = getchar();

    if(answer == 'Y' || answer == 'y') {
        for(int i = 0; i < num_files; i++) {
            fseek(disk, file[i].start_sector * SECTOR_SIZE, SEEK_SET);
            int size_remaining = file[i].file_size;
            char filename[FILE_NAME_LEN];
            snprintf(filename, FILE_NAME_LEN, "%s_recovered", file[i].file_name);
            FILE* recovered_file = fopen(filename, "wb");
            if(!recovered_file) {
                printf("ERROR: Unable to create file %s_recovered.\n", file[i].file_name);
                fclose(disk);
                free(sector);
                return -4;
            }

            while(size_remaining > 0) {
                int read_size = SECTOR_SIZE;
                if(read_size > size_remaining)
                    read_size = size_remaining;

                fread(sector, sizeof(char), read_size, disk);
                size_remaining -= read_size;
            
                fwrite(sector, sizeof(char), read_size, recovered_file);
            }

            fclose(recovered_file);

            if(size_remaining == 0) {
                file[i].is_found = true;
                printf("File %s found and restored.\n", file[i].file_name);
            }
            else {
                printf("WARNING: File %s is corrupted.\n", file[i].file_name);
            }
        }
    }

    printf("List of missing files on disk:\n");
    for(int i = 0; i < num_files; i++) {
        if(!file[i].is_found) {
            printf("%s\n", file[i].file_name);
        }
    }

    fclose(disk);
    free(sector);

    return 0;
}