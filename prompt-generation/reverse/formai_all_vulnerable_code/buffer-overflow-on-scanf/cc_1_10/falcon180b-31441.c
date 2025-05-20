//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>

#define MAX 10000
#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535
#define THREAD_COUNT 10

typedef struct {
    int sock;
    struct sockaddr_in serv_addr;
    int port;
} thread_data;

void *thread_func(void *param) {
    thread_data *data = (thread_data *) param;
    char buffer[1024];
    int bytes_received;

    if (connect(data->sock, (struct sockaddr *) &data->serv_addr, sizeof(data->serv_addr))!= 0) {
        printf("Error connecting to %s:%d\n", inet_ntoa(data->serv_addr.sin_addr), data->port);
        close(data->sock);
        return NULL;
    }

    bytes_received = recv(data->sock, buffer, sizeof(buffer), 0);

    if (bytes_received > 0) {
        printf("Port %d is open\n", data->port);
    } else {
        printf("Port %d is closed\n", data->port);
    }

    close(data->sock);
    return NULL;
}

int main() {
    int i, j;
    pthread_t threads[THREAD_COUNT];
    int ports[MAX];
    int num_open_ports = 0;
    struct hostent *host;
    char *ip_address;

    printf("Enter the IP address to scan: ");
    scanf("%s", ip_address);

    host = gethostbyname(ip_address);

    if (host == NULL) {
        printf("Invalid IP address\n");
        return 1;
    }

    for (i = PORT_RANGE_MIN; i <= PORT_RANGE_MAX; i++) {
        ports[num_open_ports++] = i;
    }

    for (i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &ports[i * (MAX / THREAD_COUNT)]);
    }

    for (i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Scan complete. %d open ports found.\n", num_open_ports);

    return 0;
}