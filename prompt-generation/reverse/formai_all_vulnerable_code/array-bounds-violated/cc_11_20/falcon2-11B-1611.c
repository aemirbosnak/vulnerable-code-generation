//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int i, n, c, addrlen, sockfd, one = 1, retval;
    char buffer[1000], hostname[1000], line[1000];
    FILE *fp;
    struct hostent *host;
    struct sockaddr_in serv_addr;

    // Check if user wants to ping a single IP address
    if (argc == 2) {
        printf("Pinging %s...\n", argv[1]);

        // Create a socket
        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("ERROR opening socket");
            exit(1);
        }

        // Set the IP address of the server
        memset((char *) &serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
        serv_addr.sin_port = htons(80);

        // Connect to the server
        if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            perror("ERROR connecting");
            exit(1);
        }

        // Send data to the server
        if ((one = write(sockfd, "GET / HTTP/1.1\r\n\r\n", 23)) < 0) {
            perror("ERROR sending data");
            exit(1);
        }

        // Read the server's response
        if ((one = read(sockfd, buffer, 1000)) < 0) {
            perror("ERROR reading response");
            exit(1);
        }

        printf("%s", buffer);
        close(sockfd);

        return 0;
    }

    // Check if user wants to ping a list of IP addresses
    if (argc == 3) {
        char *ip_list[argc - 2];
        char *line = NULL;
        char *ptr = NULL;
        size_t len = 0;
        int i = 0;

        // Parse the IP address list from the command line arguments
        for (i = 2; i < argc; i++) {
            ip_list[i - 2] = argv[i];
        }

        // Open the file containing the IP address list
        if ((fp = fopen(ip_list[0], "r")) == NULL) {
            perror("ERROR opening file");
            exit(1);
        }

        // Read the IP address list from the file
        while (getline(&line, &len, fp)!= -1) {
            ip_list[i] = line;
            i++;
        }

        // Close the file
        fclose(fp);

        // Ping each IP address in the list
        for (i = 0; i < argc - 2; i++) {
            printf("Pinging %s...\n", ip_list[i]);

            // Create a socket
            if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                perror("ERROR opening socket");
                exit(1);
            }

            // Set the IP address of the server
            memset((char *) &serv_addr, 0, sizeof(serv_addr));
            serv_addr.sin_family = AF_INET;
            inet_pton(AF_INET, ip_list[i], &serv_addr.sin_addr);
            serv_addr.sin_port = htons(80);

            // Connect to the server
            if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
                perror("ERROR connecting");
                exit(1);
            }

            // Send data to the server
            if ((one = write(sockfd, "GET / HTTP/1.1\r\n\r\n", 23)) < 0) {
                perror("ERROR sending data");
                exit(1);
            }

            // Read the server's response
            if ((one = read(sockfd, buffer, 1000)) < 0) {
                perror("ERROR reading response");
                exit(1);
            }

            printf("%s", buffer);
            close(sockfd);
        }

        return 0;
    }

    // Print usage instructions
    printf("Usage: %s [-h] [-s <ip>] [-l <ip_list>]\n", argv[0]);
    printf("  -h --help              Print this help message\n");
    printf("  -s <ip>                Ping a single IP address\n");
    printf("  -l <ip_list>           Ping a list of IP addresses\n");

    return 0;
}