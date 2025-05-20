//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 65535
#define DEFAULT_PORT 8080

void print_header() {
    printf("=================================\n");
    printf("==     NETWORK QOS MONITOR     ==\n");
    printf("=================================\n");
}

void print_menu() {
    printf("\n\n");
    printf("1. Check latency\n");
    printf("2. Check bandwidth\n");
    printf("3. Check packet loss\n");
    printf("4. Quit\n");
}

void check_latency(char* hostname) {
    struct timeval start, end;
    struct addrinfo hints, *servinfo, *p;
    int status, sockfd;
    double latency;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(hostname, NULL, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return;
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            continue;
        }
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }
        break;
    }

    if (p == NULL) {
        fprintf(stderr, "unable to connect\n");
        return;
    }

    gettimeofday(&start, NULL);

    char* msg = "ping";
    int size = strlen(msg);
    send(sockfd, msg, size, 0);

    char buffer[MAX_PACKET_SIZE] = {0};
    int byte_count = recv(sockfd, buffer, MAX_PACKET_SIZE, 0);

    gettimeofday(&end, NULL);

    close(sockfd);

    latency = ((end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0) / 2;
    printf("Latency: %.2lf ms\n", latency);
}

void check_bandwidth(char* hostname) {
    int sockfd, port, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_PACKET_SIZE] = {0};

    port = DEFAULT_PORT;

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        return;
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr,"ERROR opening socket\n");
        return;
    }

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) == -1) {
        fprintf(stderr,"ERROR connecting\n");
        return;
    }

    int i;
    for (i = 0; i < MAX_PACKET_SIZE; i++) {
        buffer[i] = 'a';
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);

    if ((n = send(sockfd,buffer,MAX_PACKET_SIZE,0)) == -1) {
        fprintf(stderr,"ERROR writing to socket\n");
        return;
    }

    if ((n = recv(sockfd,buffer,MAX_PACKET_SIZE,0)) == -1) {
        fprintf(stderr,"ERROR reading from socket\n");
        return;
    }

    gettimeofday(&end, NULL);

    close(sockfd);

    double duration = ((end.tv_sec - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6;
    double bandwidth = MAX_PACKET_SIZE / duration / 1000000 * 8;
    printf("Bandwidth: %.2lf Mbps\n", bandwidth);
}

void check_packet_loss(char* hostname) {
    struct sockaddr_in servaddr;
	int sockfd;

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(hostname);
	servaddr.sin_port = htons(DEFAULT_PORT);

	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket creation failed");
		return;
	}

	sendto(sockfd, (const char*) "ping", 4, MSG_CONFIRM, (const struct sockaddr*)&servaddr, sizeof(servaddr));

	char buffer[MAX_PACKET_SIZE] = {0};
    struct timeval start, end;
	gettimeofday(&start, NULL);
	recvfrom(sockfd, (char*)buffer, sizeof(buffer), MSG_WAITALL, (struct sockaddr*)&servaddr, sizeof(servaddr));
	gettimeofday(&end, NULL);

	close(sockfd);

	double duration = ((end.tv_sec - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6;
    double packet_loss = (duration > 1) ? 1 : 0; // if duration is more than 1s, consider packet loss
    printf("Packet loss: %.2lf\n", packet_loss);
}

int main() {
    char hostname[100];
    int choice;

    print_header();

    printf("Enter hostname: ");
    scanf("%s", hostname);

    while (1) {
        print_menu();

        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                check_latency(hostname);
                break;
            case 2:
                check_bandwidth(hostname);
                break;
            case 3:
                check_packet_loss(hostname);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}