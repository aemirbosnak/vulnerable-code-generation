//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 1234
#define MAXLINE 1024

int main() {
    struct hostent *host;
    struct sockaddr_in server_address;
    char buffer[MAXLINE];
    int socket_fd, bytes_received, cpu_usage;
    float idle_time, system_time, uptime;

    // Get host information
    if ((host = gethostbyname("localhost")) == NULL) {
        perror("gethostbyname error");
        exit(1);
    }

    // Create socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    // Set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect error");
        exit(1);
    }

    // Get CPU usage data
    FILE *fp = fopen("/proc/stat", "r");
    fscanf(fp, "%*s %d %f %f %f", &cpu_usage, &idle_time, &system_time, &uptime);
    fclose(fp);

    // Convert to percentage
    int total_time = cpu_usage + idle_time + system_time;
    float cpu_percentage = ((float)cpu_usage / (float)total_time) * 100.0;

    // Send CPU usage data to server
    sprintf(buffer, "CPU usage is %0.2f%%\n", cpu_percentage);
    write(socket_fd, buffer, strlen(buffer));

    // Receive response from server
    bytes_received = read(socket_fd, buffer, MAXLINE-1);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Close socket
    close(socket_fd);

    return 0;
}