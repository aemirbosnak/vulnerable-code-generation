#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

int main() {
    int sockfd, i, len, data[1024];

    sockfd = socket(AF_INET, SOCK_RAW, htons(3));
    ioctl(sockfd, FIONREAD, &len);

    read(sockfd, data, len);

    // Out-of-bounds read
    data[len] = 42;

    write(sockfd, data, len);

    close(sockfd);

    return 0;
}
