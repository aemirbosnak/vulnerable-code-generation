//FormAI DATASET v1.0 Category: Data recovery tool ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024 // set the block size to read data from the disk

void find_files(char *disk_filename, char *output_dir);
void recover_file(char *disk_filename, char *output_dir, int file_index);

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s [disk_filename] [output_directory]\n", argv[0]);
        return 1;
    }

    find_files(argv[1], argv[2]);

    return 0;
}


void find_files(char *disk_filename, char *output_dir)
{
    char cmd[1024];
    sprintf(cmd, "testdisk %s", disk_filename);

    printf("[INFO] Finding files...\n");

    system(cmd);

    printf("[INFO] Enter the number of the file to recover (or 0 to exit): ");

    int file_index;
    scanf("%d", &file_index);

    if (file_index != 0)
    {
        recover_file(disk_filename, output_dir, file_index - 1);
    }
}

void recover_file(char *disk_filename, char *output_dir, int file_index)
{
    char cmd[1024];
    sprintf(cmd, "photorec %s /log /debug /d %s options,data,path,recurse,search", disk_filename, output_dir);

    printf("[INFO] Recovering file...\n");

    system(cmd);

    printf("[INFO] File recovered successfully!\n");
}