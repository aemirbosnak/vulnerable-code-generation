//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

// Function to get the current time in seconds since epoch
double get_current_time() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    return (double) (tm->tm_sec + 60 * (tm->tm_min + 60 * (tm->tm_hour + 24 * tm->tm_mday + (365 + floor(tm->tm_year / 4 - floor(tm->tm_year / 100))))) + 0.5);
}

// Function to get the hostname of the machine
char* get_hostname() {
    char hostname[1024];
    gethostname(hostname, sizeof(hostname));
    return hostname;
}

// Function to get the IP address of the machine
char* get_ip_address() {
    char ip_address[INET_ADDRSTRLEN];
    struct hostent *host_info;
    host_info = gethostbyname(get_hostname());
    if (host_info == NULL) {
        printf("Error: No hostname resolved\n");
        exit(1);
    }
    inet_ntop(host_info->h_addrtype, host_info->h_addr_list[0], ip_address, sizeof(ip_address));
    return ip_address;
}

// Function to create a socket and connect to a remote server
int connect_to_server(const char* hostname, const char* port) {
    int sockfd, valread;
    struct sockaddr_in server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(port));
    server.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send a packet of data to the server
int send_packet(int sockfd, const char* data) {
    int valread;

    if ((valread = send(sockfd, data, strlen(data), 0)) < 0) {
        perror("Error sending packet");
        exit(EXIT_FAILURE);
    }

    return valread;
}

// Function to receive a packet of data from the server
int receive_packet(int sockfd, char* buffer, const int size) {
    int valread;

    if ((valread = recv(sockfd, buffer, size, 0)) < 0) {
        perror("Error receiving packet");
        exit(EXIT_FAILURE);
    }

    return valread;
}

// Function to close a socket
void close_socket(int sockfd) {
    if (close(sockfd) < 0) {
        perror("Error closing socket");
        exit(EXIT_FAILURE);
    }
}

// Function to check the quality of service of a packet
int check_qos(int sockfd, const char* data) {
    int valread;

    if ((valread = send(sockfd, data, strlen(data), 0)) < 0) {
        perror("Error sending packet");
        exit(EXIT_FAILURE);
    }

    if ((valread = receive_packet(sockfd, &valread, sizeof(valread))) < 0) {
        perror("Error receiving packet");
        exit(EXIT_FAILURE);
    }

    if (valread == 1) {
        printf("Packet QoS is good\n");
        return 1;
    } else {
        printf("Packet QoS is bad\n");
        return 0;
    }
}

// Main function
int main() {
    int sockfd;
    char data[1024];
    char hostname[1024];
    char ip_address[INET_ADDRSTRLEN];
    char port[16];

    bzero(data, sizeof(data));
    bzero(hostname, sizeof(hostname));
    bzero(ip_address, sizeof(ip_address));
    bzero(port, sizeof(port));

    printf("Enter hostname of the server: ");
    scanf("%s", hostname);
    printf("Enter port number of the server: ");
    scanf("%s", port);

    sockfd = connect_to_server(hostname, port);
    if (sockfd < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    while (1) {
        time_t current_time = time(NULL);
        double current_time_in_seconds = get_current_time();
        printf("Current time: %s\n", ctime(&current_time));
        printf("Current time in seconds since epoch: %f\n", current_time_in_seconds);

        bzero(data, sizeof(data));
        snprintf(data, sizeof(data), "Packet from %s:%s at %s", get_hostname(), get_ip_address(), ctime(&current_time));
        printf("Sending packet: %s\n", data);
        send_packet(sockfd, data);

        int qos = check_qos(sockfd, data);
        if (qos == 1) {
            printf("Packet QoS is good\n");
        } else {
            printf("Packet QoS is bad\n");
        }

        close_socket(sockfd);
    }

    return 0;
}