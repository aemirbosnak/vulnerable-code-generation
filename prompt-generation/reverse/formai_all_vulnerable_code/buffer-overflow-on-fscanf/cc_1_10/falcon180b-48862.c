//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <process_id>\n", argv[0]);
        exit(1);
    }

    int pid = atoi(argv[1]);
    char path[BUF_SIZE];
    snprintf(path, BUF_SIZE, "/proc/%d/cmdline", pid);

    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Cannot open %s\n", path);
        exit(1);
    }

    char buf[BUF_SIZE];
    fgets(buf, BUF_SIZE, fp);
    buf[strcspn(buf, "\n")] = '\0'; // remove newline character

    printf("Process name: %s\n", buf);
    fclose(fp);

    char status_path[BUF_SIZE];
    snprintf(status_path, BUF_SIZE, "/proc/%d/status", pid);

    fp = fopen(status_path, "r");
    if (fp == NULL) {
        printf("Cannot open %s\n", status_path);
        exit(1);
    }

    char state;
    while (fscanf(fp, "State: %c\n", &state)!= EOF) {
        printf("State: %c\n", state);
    }

    fclose(fp);

    return 0;
}