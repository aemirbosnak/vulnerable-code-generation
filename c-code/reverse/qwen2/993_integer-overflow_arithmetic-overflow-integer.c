#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <time.h>

#define QUEUE_NAME "/traffic_light_queue"
#define MAX_MESSAGES 10
#define MESSAGE_SIZE 256

typedef struct {
    char light;
    int duration;
} TrafficLightMessage;

void handle_message(TrafficLightMessage *msg) {
    printf("Received message: Light %c for %d seconds\n", msg->light, msg->duration);
    // Simulate updating the traffic light timer
}

int main() {
    mqd_t mq;
    struct mq_attr attr;
    TrafficLightMessage msg;

    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = sizeof(msg);
    attr.mq_curmsgs = 0;

    mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0644, &attr);
    if (mq == -1) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    while (1) {
        ssize_t bytes_read = mq_receive(mq, (char *)&msg, sizeof(msg), NULL);
        if (bytes_read == -1) {
            perror("mq_receive");
            continue;
        }
        handle_message(&msg);
    }

    mq_close(mq);
    mq_unlink(QUEUE_NAME);

    return 0;
}
