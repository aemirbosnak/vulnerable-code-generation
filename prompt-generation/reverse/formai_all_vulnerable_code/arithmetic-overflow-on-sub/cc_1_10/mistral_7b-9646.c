//MISTRAL-7B DATASET v1.0 Category: Antivirus scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_FILE_SIZE (1024 * 1024) // 1MB
#define SIGNATURE_SIZE 16
#define NUM_SIGNATURES 5

typedef struct {
    char signature[SIGNATURE_SIZE];
    off_t file_offset;
} Signature;

Signature signatures[NUM_SIGNATURES] = {
    {"JAVA_START", 0},
    {"MALWARE_1", 0},
    {"SUSPICIOUS_CODE", 0},
    {"BACKDOOR", 0},
    {"ROOTKIT", 0}
};

int scan_file(const char *filename) {
    int i, j;
    struct stat st;
    int fd;
    char *map_base;
    off_t file_size;

    if (stat(filename, &st) < 0) {
        perror("Error statting file");
        return 1;
    }

    if (st.st_size > MAX_FILE_SIZE) {
        printf("File %s is too big to scan\n", filename);
        return 1;
    }

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file for scanning");
        return 1;
    }

    file_size = st.st_size;
    map_base = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);

    for (i = 0; i < NUM_SIGNATURES; i++) {
        Signature *sig = &signatures[i];

        for (j = 0; j < file_size - sig->file_offset; j++) {
            if (memcmp(&map_base[j], sig->signature, SIGNATURE_SIZE) == 0) {
                printf("Virus '%s' found in file '%s'\n", sig->signature, filename);
                munmap(map_base, file_size);
                return 1;
            }
        }
    }

    munmap(map_base, file_size);

    return 0;
}

int main(int argc, char *argv[]) {
    int i;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    for (i = 0; i < NUM_SIGNATURES; i++) {
        signatures[i].file_offset = i * SIGNATURE_SIZE;
    }

    if (scan_file(argv[1])) {
        printf("Error scanning file '%s'\n", argv[1]);
        return 1;
    }

    printf("File '%s' is clean\n", argv[1]);
    return 0;
}