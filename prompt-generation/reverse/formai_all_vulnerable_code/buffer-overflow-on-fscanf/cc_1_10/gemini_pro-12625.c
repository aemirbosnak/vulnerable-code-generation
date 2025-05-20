//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <libgen.h>

#define MAX_SCAN_SIZE 1024 * 1024
#define MAX_VIRUS_SIGS 100

typedef struct {
    char *name;
    size_t size;
    unsigned char *data;
} virus_sig;

virus_sig virus_sigs[MAX_VIRUS_SIGS];
size_t num_virus_sigs = 0;

int load_virus_sigs(const char *filename) {
    FILE *fp;
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    for (i = 0; i < MAX_VIRUS_SIGS; i++) {
        if (fscanf(fp, "%s %zu\n", virus_sigs[i].name, &virus_sigs[i].size) != 2) {
            break;
        }
        virus_sigs[i].data = malloc(virus_sigs[i].size);
        if (virus_sigs[i].data == NULL) {
            perror("malloc");
            return -1;
        }
        if (fread(virus_sigs[i].data, virus_sigs[i].size, 1, fp) != 1) {
            perror("fread");
            return -1;
        }
    }

    num_virus_sigs = i;

    fclose(fp);

    return 0;
}

int scan_file(const char *filename) {
    int fd;
    unsigned char buf[MAX_SCAN_SIZE];
    size_t nread;
    int i;
    int j;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    while ((nread = read(fd, buf, MAX_SCAN_SIZE)) > 0) {
        for (i = 0; i < num_virus_sigs; i++) {
            for (j = 0; j < nread - virus_sigs[i].size; j++) {
                if (memcmp(&buf[j], virus_sigs[i].data, virus_sigs[i].size) == 0) {
                    printf("Virus %s found in file %s at offset %zu\n", virus_sigs[i].name, filename, j);
                    return 1;
                }
            }
        }
    }

    if (nread == -1) {
        perror("read");
        return -1;
    }

    close(fd);

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <virus sig file> <file to scan>\n", argv[0]);
        return 1;
    }

    if (load_virus_sigs(argv[1]) != 0) {
        return 1;
    }

    if (scan_file(argv[2]) != 0) {
        return 1;
    }

    return 0;
}