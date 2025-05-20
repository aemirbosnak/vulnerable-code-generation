//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/time.h>

#define MAX_BUF 1024
#define QOS_FILE "/proc/net/qdisc/eth0/queues/rx-0/qdisc"
#define QOS_FILE_LEN 64
#define QOS_CLASSES "0:0 1:1 2:2 3:3 4:4 5:5 6:6 7:7"

int main(int argc, char **argv) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server_addr;
    socklen_t server_len = sizeof(server_addr);
    char send_buf[MAX_BUF];
    char recv_buf[MAX_BUF];
    int ret;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9000);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    while (1) {
        ret = ioctl(sock, FIONREAD, &server_len);
        if (ret == -1) {
            perror("ioctl");
            break;
        }

        ret = recv(sock, recv_buf, MAX_BUF, 0);
        if (ret <= 0) {
            break;
        }

        recv_buf[ret] = '\0';
        printf("Received: %s\n", recv_buf);

        if (strstr(recv_buf, "QoS")) {
            FILE *qos_file;
            char qos_buf[QOS_FILE_LEN];

            qos_file = fopen(QOS_FILE, "r");
            if (qos_file == NULL) {
                perror("fopen");
                break;
            }

            ret = fread(qos_buf, 1, QOS_FILE_LEN, qos_file);
            if (ret <= 0) {
                perror("fread");
                break;
            }

            qos_buf[ret] = '\0';
            printf("QoS: %s\n", qos_buf);

            fclose(qos_file);
        }
    }

    close(sock);
    return 0;
}