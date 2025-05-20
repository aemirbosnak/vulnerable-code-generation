//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define QOS_MONITOR_VERSION "1.0"

typedef struct {
    uint32_t timestamp;
    double delay;
} qos_sample_t;

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    socklen_t addrlen;
    qos_sample_t *samples;
    size_t samples_count;
    size_t samples_size;
} qos_monitor_t;

static int qos_monitor_create(qos_monitor_t *monitor, const char *ip, uint16_t port) {
    int sockfd;
    struct sockaddr_in addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);

    monitor->sockfd = sockfd;
    monitor->addr = addr;
    monitor->addrlen = sizeof(addr);
    monitor->samples = NULL;
    monitor->samples_count = 0;
    monitor->samples_size = 0;

    return 0;
}

static void qos_monitor_destroy(qos_monitor_t *monitor) {
    if (monitor->sockfd >= 0) {
        close(monitor->sockfd);
    }
    if (monitor->samples != NULL) {
        free(monitor->samples);
    }
}

static int qos_monitor_send(qos_monitor_t *monitor, const void *data, size_t len) {
    return sendto(monitor->sockfd, data, len, 0, (struct sockaddr *) &monitor->addr, monitor->addrlen);
}

static int qos_monitor_recv(qos_monitor_t *monitor, void *data, size_t len) {
    return recvfrom(monitor->sockfd, data, len, 0, (struct sockaddr *) &monitor->addr, &monitor->addrlen);
}

static int qos_monitor_sample(qos_monitor_t *monitor) {
    int ret;
    qos_sample_t sample;

    struct timeval tv;
    gettimeofday(&tv, NULL);

    sample.timestamp = tv.tv_sec * 1000000 + tv.tv_usec;
    sample.delay = 0.0;

    ret = qos_monitor_send(monitor, &sample, sizeof(sample));
    if (ret < 0) {
        return -1;
    }

    ret = qos_monitor_recv(monitor, &sample, sizeof(sample));
    if (ret < 0) {
        return -1;
    }

    if (monitor->samples_count + 1 > monitor->samples_size) {
        monitor->samples_size *= 2;
        monitor->samples = realloc(monitor->samples, monitor->samples_size * sizeof(qos_sample_t));
    }

    monitor->samples[monitor->samples_count++] = sample;

    return 0;
}

static void qos_monitor_dump(qos_monitor_t *monitor, FILE *fp) {
    size_t i;

    for (i = 0; i < monitor->samples_count; i++) {
        fprintf(fp, "%u %f\n", monitor->samples[i].timestamp, monitor->samples[i].delay);
    }
}

int main(int argc, char *argv[]) {
    int ret;
    qos_monitor_t monitor;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        return -1;
    }

    ret = qos_monitor_create(&monitor, argv[1], atoi(argv[2]));
    if (ret < 0) {
        perror("qos_monitor_create");
        return -1;
    }

    while (1) {
        ret = qos_monitor_sample(&monitor);
        if (ret < 0) {
            perror("qos_monitor_sample");
            break;
        }
    }

    qos_monitor_dump(&monitor, stdout);
    qos_monitor_destroy(&monitor);

    return 0;
}