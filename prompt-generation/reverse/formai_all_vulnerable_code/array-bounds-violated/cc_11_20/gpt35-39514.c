//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_LINE 4096

int main(int argc, char *argv[]) {

    struct hostent *hp;
    struct sockaddr_in sin;
    char buf[MAX_LINE];
    int s;
    ssize_t n;

    /* check command line arguments */
    if(argc != 4) {
        fprintf(stderr, "usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    /* translate hostname to IP address */
    hp = gethostbyname(argv[1]);
    if (!hp) {
        fprintf(stderr, "unknown host: %s\n", argv[1]);
        exit(1);
    }

    /* build address data structure */
    bzero((char *)&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    bcopy(hp->h_addr, (char *)&sin.sin_addr, hp->h_length);
    sin.sin_port = htons(110);

    /* active open */
    if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("error creating socket");
        exit(1);
    }

    if (connect(s, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
        exit(1);
    }

    /* receive greeting from server */
    if ((n = recv(s, buf, MAX_LINE, 0)) < 0) {
        perror("error receiving greeting from server");
        exit(1);
    }

    buf[n] = '\0';
    printf("%s", buf);

    /* send username to server */
    snprintf(buf, MAX_LINE, "USER %s\r\n", argv[2]);
    if (send(s, buf, strlen(buf), 0) < 0) {
        perror("error sending username to server");
        exit(1);
    }

    /* receive response from server */
    if ((n = recv(s, buf, MAX_LINE, 0)) < 0) {
        perror("error receiving response from server");
        exit(1);
    }

    buf[n] = '\0';
    printf("%s", buf);

    /* send password to server */
    snprintf(buf, MAX_LINE, "PASS %s\r\n", argv[3]);
    if (send(s, buf, strlen(buf), 0) < 0) {
        perror("error sending password to server");
        exit(1);
    }

    /* receive response from server */
    if ((n = recv(s, buf, MAX_LINE, 0)) < 0) {
        perror("error receiving response from server");
        exit(1);
    }

    buf[n] = '\0';
    printf("%s", buf);

    /* send list command to server */
    snprintf(buf, MAX_LINE, "LIST\r\n");
    if (send(s, buf, strlen(buf), 0) < 0) {
        perror("error sending list command to server");
        exit(1);
    }

    /* receive response from server */
    if ((n = recv(s, buf, MAX_LINE, 0)) < 0) {
        perror("error receiving response from server");
        exit(1);
    }

    buf[n] = '\0';
    printf("%s", buf);

    /* send quit command to server */
    snprintf(buf, MAX_LINE, "QUIT\r\n");
    if (send(s, buf, strlen(buf), 0) < 0) {
        perror("error sending quit command to server");
        exit(1);
    }

    /* receive response from server */
    if ((n = recv(s, buf, MAX_LINE, 0)) < 0) {
        perror("error receiving response from server");
        exit(1);
    }

    buf[n] = '\0';
    printf("%s", buf);

    /* clean up */
    close(s);

    return 0;
}