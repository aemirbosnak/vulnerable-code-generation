//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define LEN 256

struct FileInfo {
    char filename[LEN];
    char file_type;
    unsigned int size;
    unsigned int checksum;
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [file]\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    unsigned int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    struct FileInfo file_info;
    file_info.filename[0] = '\0';
    file_info.file_type = '\0';
    file_info.size = 0;
    file_info.checksum = 0;

    while (file_size > 0) {
        int read_size = file_size > LEN? LEN : file_size;
        unsigned char buffer[read_size];
        file_size -= read_size;

        if (fread(buffer, 1, read_size, file)!= read_size) {
            perror("fread");
            break;
        }

        file_info.checksum += buffer[0];
    }

    fclose(file);

    int file_fd = open(argv[1], O_RDONLY);
    if (file_fd == -1) {
        perror("open");
        return 1;
    }

    unsigned char* file_content = mmap(NULL, file_info.size, PROT_READ, MAP_SHARED, file_fd, 0);
    if (file_content == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    memcpy(file_content, &file_info, sizeof(file_info));

    struct FileInfo* virus_found = malloc(sizeof(struct FileInfo));
    if (virus_found == NULL) {
        perror("malloc");
        return 1;
    }

    virus_found->filename[0] = '\0';
    virus_found->file_type = '\0';
    virus_found->size = 0;
    virus_found->checksum = 0;

    int i;
    for (i = 0; i < file_info.size; i += 4) {
        if (file_content[i] == 0x4d5a && file_content[i+1] == 0x4d5a &&
            file_content[i+2] == 0x4d5a && file_content[i+3] == 0x4d5a) {
            virus_found->checksum += file_content[i+4];
        }
    }

    if (virus_found->checksum!= 0x4d5a4d5a4d5a4d5a) {
        fprintf(stderr, "Virus found!\n");
        fclose(file);
        close(file_fd);
        free(virus_found);
        return 1;
    }

    fclose(file);
    close(file_fd);
    free(virus_found);

    return 0;
}