#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <string.h>

int main() {
    int fd = socket(AF_INET, SOCK_STREAM, htons(8));
    char buf[1024] = "hello world";
    write(fd, buf, strlen(buf));
    close(fd);
    return 0;
}
