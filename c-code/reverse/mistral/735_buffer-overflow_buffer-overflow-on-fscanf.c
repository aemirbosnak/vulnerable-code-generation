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

#define BUFFER_SIZE 1024

int main() {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    char command[128] = "/usr/bin/uptime -p";
    int ret;

    fp = popen(command, "r");
    if (!fp) {
        perror("popen");
        return 1;
    }

    while ((ret = fscanf(fp, "%s", buffer)) != EOF) {
        if (ret > 0) {
            printf("%s\n", buffer);
        }
    }

    if (pclose(fp) != 0) {
        perror("pclose");
        return 1;
    }

    return 0;
}
