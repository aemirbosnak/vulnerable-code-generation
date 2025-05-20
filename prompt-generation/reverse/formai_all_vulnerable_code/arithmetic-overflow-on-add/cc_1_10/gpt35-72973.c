//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Sherlock Holmes
#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <unistd.h>

int main() {

    char *url = "google.com";
    struct hostent *host = gethostbyname(url);
    
    if (host == NULL) {
        printf("There was an error resolving the IP address.\n");
        return 0;
    }
    
    char *ip = inet_ntoa(*((struct in_addr*) host->h_addr_list[0]));
    printf("Connecting to: %s (%s)\n", url, ip);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket.\n");
        return 0;
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection failed.\n");
        return 0;
    }

    gettimeofday(&end_time, NULL);

    long int time_elapsed = ((end_time.tv_sec - start_time.tv_sec) * 1000000L) + (end_time.tv_usec - start_time.tv_usec);
    
    double bytes_received = 0;
    long int total_time = 0;

    printf("Connected to server, running speed test...\n");

    for (int i = 1; i <= 10; i++) {
        char *message = "GET / HTTP/1.1\r\n\r\n";
        if (send(sock, message, strlen(message), 0) < 0) {
            printf("Error sending HTTP request.\n");
            break;
        }

        char buffer[2048] = {0};
        int result = recv(sock, buffer, sizeof(buffer), 0);
        if (result < 0) {
            printf("Error receiving response from server.\n");
            break;
        }

        bytes_received += result;

        gettimeofday(&start_time, NULL);

        result = recv(sock, buffer, sizeof(buffer), MSG_WAITALL);

        gettimeofday(&end_time, NULL);

        if (result < 0) {
            printf("Error receiving response from server.\n");
            break;
        }

        total_time += ((end_time.tv_sec - start_time.tv_sec) * 1000000L) + (end_time.tv_usec - start_time.tv_usec);

        printf("Test %d complete.\n", i);
    }

    close(sock);

    double speed = bytes_received * 8 / total_time;
    printf("Download speed: %.2f Mbps\n", speed);

    return 0;
}