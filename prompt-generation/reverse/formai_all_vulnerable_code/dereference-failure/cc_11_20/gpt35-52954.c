//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: distributed
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define PORT_NUM 9001
#define MAX_BUFF_SIZE 32768

typedef struct SpeedTestPacket_t {
    unsigned short packet_size;
    char buffer[MAX_BUFF_SIZE];
} SpeedTestPacket;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("\nUsage : %s <server IP address>\n\n", argv[0]);
        return 0;
    }

    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        printf("Error opening socket: %s\n", strerror(errno));
        return -1;
    }

    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: no such host.");
        return -1;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT_NUM);
    memcpy(&server_address.sin_addr, server->h_addr_list[0], server->h_length);

    if (connect(sock, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Error connecting: %s\n", strerror(errno));
        return -1;
     }

     // measure download speed
     printf("Measuring download speed\n");
     int packets_received = 0;
     int bytes_received = 0;
     int begin_time = time(NULL);
     while (bytes_received < MAX_BUFF_SIZE && packets_received < 128) {
        SpeedTestPacket packet;
        int bytes_rcvd = recv(sock, &packet, sizeof(packet), 0);
        if (bytes_rcvd < 0) {
            printf("Error receiving data: %s\n", strerror(errno));
            close(sock);
            return -1;
        }
        else if (bytes_rcvd == 0) {
            printf("Server closed connection\n");
            close(sock);
            return -1;
        }
        else {
            bytes_received += bytes_rcvd;
            packets_received++;
        }
    }
    int end_time = time(NULL);
    int time_diff = end_time - begin_time;
    double download_speed = bytes_received / time_diff;
    printf("Downloaded %d bytes in %d seconds. Download speed = %.2f bytes/sec.\n", bytes_received, time_diff, download_speed);

    // measure upload speed
    printf("\nMeasuring upload speed\n");
    SpeedTestPacket packet;
    memset(&packet, 'a', sizeof(packet));
    begin_time = time(NULL);
    int bytes_sent = 0;
    int packets_sent = 0;
    while (packets_sent < 128) {
        int bytes_sent_this_iteration = send(sock, &packet, sizeof(packet), 0);
        if (bytes_sent_this_iteration < 0) {
            printf("Error sending data: %s\n", strerror(errno));
            close(sock);
            return -1;
        }
        else {
            bytes_sent += bytes_sent_this_iteration;
            packets_sent++;
        }
    }
    end_time = time(NULL);
    time_diff = end_time - begin_time;
    double upload_speed = bytes_sent / time_diff;
    printf("Uploaded %d bytes in %d seconds. Upload speed = %.2f bytes/sec.\n", bytes_sent, time_diff, upload_speed);

    close(sock);
    return 0;
}