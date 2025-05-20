#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct {
    char key[32];
    char value[64];
} MemInfo;

int parse_meminfo(const char *path, MemInfo *mem_info) {
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    char buffer[1024];
    size_t len = 0;
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        len += bytes_read;
        buffer[bytes_read] = '\0';

        char *line = strtok(buffer, "\n");
        while (line != NULL) {
            if (strlen(line) > 31 && strlen(line) < 64) {
                strcpy(mem_info->key, line);
                line = strtok(NULL, ": ");
                if (strlen(line) < 63) {
                    strcpy(mem_info->value, line);
                    return 0;
                }
            }
            line = strtok(NULL, "\n");
        }
    }

    close(fd);
    return -1;
}

void display_meminfo(MemInfo mem_info) {
    printf("%s: %s\n", mem_info.key, mem_info.value);
}

int main() {
    MemInfo mem_info;
    if (parse_meminfo("/proc/meminfo", &mem_info)) {
        perror("parse_meminfo");
        return 1;
    }

    display_meminfo(mem_info);
    return 0;
}
