//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

char *program_name;

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

void usage(void)
{
    fprintf(stderr, "Usage: %s <host> <port>\n", program_name);
    exit(1);
}

int main(int argc, char **argv)
{
    program_name = argv[0];
    if (argc!= 3)
        usage();
    int port = atoi(argv[2]);
    if (port <= 0 || port > 65535)
        usage();
    char *host = argv[1];
    struct hostent *hp = gethostbyname(host);
    if (hp == NULL)
        error("gethostbyname");
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error("socket");
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.s_addr = *(unsigned long *) hp->h_addr;
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) == -1)
        error("connect");
    close(sock);
    printf("Port %d is open on %s\n", port, host);
    return 0;
}