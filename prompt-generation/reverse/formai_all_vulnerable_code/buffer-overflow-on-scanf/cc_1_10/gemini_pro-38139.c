//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// The elusive "mind-bending" part begins here...

struct socket_dance {
    int fd;
    char *brainwaves;
    struct sockaddr_in addr;
};

void mind_meld(struct socket_dance *dance, char *message) {
    sendto(dance->fd, message, strlen(message), 0, (struct sockaddr *) &dance->addr, sizeof(dance->addr));
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    // The ethereal realms of socket wizardry commence...

    int astral_projection = socket(AF_INET, SOCK_DGRAM, 0);
    if (astral_projection == -1) {
        perror("socket");
        return 1;
    }

    struct hostent *host_oracle = gethostbyname(argv[1]);
    if (host_oracle == NULL) {
        perror("gethostbyname");
        close(astral_projection);
        return 1;
    }

    struct socket_dance cosmic_ballet;
    cosmic_ballet.fd = astral_projection;
    cosmic_ballet.brainwaves = argv[2];
    memset(&cosmic_ballet.addr, 0, sizeof(cosmic_ballet.addr));
    cosmic_ballet.addr.sin_family = AF_INET;
    cosmic_ballet.addr.sin_port = htons(atoi(argv[2]));
    bcopy((char *) host_oracle->h_addr, (char *) &cosmic_ballet.addr.sin_addr.s_addr, host_oracle->h_length);

    // The hypnotic loop of network communication...

    while (1) {
        char *message = malloc(1024);
        printf("Enter your telepathic message: ");
        scanf("%s", message);

        mind_meld(&cosmic_ballet, message);

        char *response = malloc(1024);
        recvfrom(cosmic_ballet.fd, response, 1024, 0, NULL, NULL);
        printf("Received response: %s\n", response);

        free(message);
        free(response);
    }

    return 0;
}