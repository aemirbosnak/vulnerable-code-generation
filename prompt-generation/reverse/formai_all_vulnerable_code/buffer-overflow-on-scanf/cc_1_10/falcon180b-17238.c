//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024
#define MAX_FDS 256

int main() {
    int num_fds = 0;
    int fds[MAX_FDS];
    char buf[BUF_SIZE];
    int bytes_read;
    int i;

    printf("Enter the number of files to recover:\n");
    scanf("%d", &num_fds);

    for(i = 0; i < num_fds; i++) {
        printf("Enter file name %d:\n", i+1);
        scanf("%s", buf);
        fds[i] = open(buf, O_RDONLY);
        if(fds[i] == -1) {
            printf("Error opening file %s\n", buf);
            exit(1);
        }
    }

    printf("Recovering files...\n");
    while(1) {
        for(i = 0; i < num_fds; i++) {
            bytes_read = read(fds[i], buf, BUF_SIZE);
            if(bytes_read == -1) {
                if(errno == EAGAIN) {
                    continue;
                } else {
                    printf("Error reading file %s\n", buf);
                    exit(1);
                }
            } else if(bytes_read == 0) {
                close(fds[i]);
                fds[i] = -1;
            } else {
                write(1, buf, bytes_read);
            }
        }
    }

    return 0;
}