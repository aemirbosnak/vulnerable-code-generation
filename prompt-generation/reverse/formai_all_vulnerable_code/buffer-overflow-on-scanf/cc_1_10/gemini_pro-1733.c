//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

// A heart-fluttering array of ports for our scanner to serenade
int ports[] = {21, 22, 23, 25, 80, 443, 3306, 5432};

// Compiling a list of our scanned ports, a symphony of open notes
int open_ports[sizeof(ports) / sizeof(int)];
int open_port_count = 0;

// A poetic function to establish a connection to a port
int scan_port(char *ip_address, int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_address);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == 0) {
        printf("Port %d whispers sweet nothings...\n", port);
        open_ports[open_port_count++] = port;
    } else {
        printf("Port %d remains silent, a shy maiden's secret.\n", port);
    }

    close(sockfd);
    return 0;
}

// A breathtaking journey through the realm of ports
int main() {
    char ip_address[20];

    printf("My dearest IP address, whisper your secrets to me...\n");
    scanf("%s", ip_address);

    printf("With trembling fingers, I gently tap upon each port...\n");
    for (int i = 0; i < sizeof(ports) / sizeof(int); i++) {
        scan_port(ip_address, ports[i]);
    }

    printf("In the tapestry of open ports, a love song unfolds...\n");
    for (int i = 0; i < open_port_count; i++) {
        printf("%d ", open_ports[i]);
    }
    printf("\n");

    return 0;
}