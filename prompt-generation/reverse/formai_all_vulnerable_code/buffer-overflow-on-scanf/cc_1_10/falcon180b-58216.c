//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTS 100
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int num_hosts;
    char *hosts[MAX_HOSTS];
    int sock;
    struct hostent *he;
    struct sockaddr_in sa;
    char buffer[BUFFER_SIZE];
    int len;
    int i;

    if (argc < 2) {
        printf("Usage: %s host1 [host2... hostN]\n", argv[0]);
        return 1;
    }

    num_hosts = argc - 1;

    for (i = 0; i < num_hosts; i++) {
        hosts[i] = argv[i + 1];
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    while (1) {
        printf("Enter host name: ");
        scanf("%s", buffer);

        if (buffer[0] == '\0') {
            continue;
        }

        he = gethostbyname(buffer);
        if (he == NULL) {
            printf("Error: %s\n", hstrerror(h_errno));
            continue;
        }

        sa.sin_family = AF_INET;
        sa.sin_port = htons(7);
        sa.sin_addr = *(struct in_addr *)he->h_addr;

        len = strlen(buffer);
        strncpy(buffer, "PING ", BUFFER_SIZE - len);
        strncat(buffer, buffer, BUFFER_SIZE - len);

        sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr *)&sa, sizeof(sa));

        memset(buffer, 0, BUFFER_SIZE);
        len = recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&sa, &len);

        if (len > 0) {
            printf("%s\n", buffer);
        }
    }

    close(sock);
    return 0;
}