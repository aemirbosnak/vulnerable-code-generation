//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 65535

void scan(int start, int end) {
    int sock;
    struct sockaddr_in target;
    int result;

    for (int i = start; i <= end; i++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);

        if (sock == -1) {
            printf("Error creating socket\n");
            exit(1);
        }

        target.sin_family = AF_INET;
        target.sin_port = htons(i);
        target.sin_addr.s_addr = inet_addr("127.0.0.1");

        result = connect(sock, (struct sockaddr *)&target, sizeof(target));

        if (result == -1) {
            printf("Port %d is closed\n", i);
        } else {
            printf("Port %d is open\n", i);
            close(sock);
        }
    }
}

int main() {
    int start, end;

    printf("Enter start port: ");
    scanf("%d", &start);

    printf("Enter end port: ");
    scanf("%d", &end);

    scan(start, end);

    return 0;
}