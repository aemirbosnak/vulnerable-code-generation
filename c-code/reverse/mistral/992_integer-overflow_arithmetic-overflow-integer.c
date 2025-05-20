#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/msg.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_QUEUE 100
#define RED 1
#define YELLOW 2
#define GREEN 3

struct msg_buf {
    long mtype;
    int state;
    time_t next_change;
};

key_t key;
int msqid;

void *traffic_light(void *arg) {
    struct msg_buf buf;

    while (1) {
        msgrcv(msqid, &buf, sizeof(buf), RED, 0);
        buf.state = GREEN;
        buf.next_change = time(NULL) + 5;
        msgsnd(msqid, &buf, sizeof(buf), 0);

        sleep(2);

        buf.state = YELLOW;
        buf.next_change = time(NULL) + 1;
        msgsnd(msqid, &buf, sizeof(buf), 0);

        sleep(2);

        buf.state = RED;
        buf.next_change = time(NULL);
        msgsnd(msqid, &buf, sizeof(buf), 0);
    }

    return NULL;
}

int main() {
    key = ftok("./my_traffic_light", 'A');
    msqid = msgget(key, 0666 | IPC_CREAT);

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, traffic_light, NULL);

    while (1) {
        struct msg_buf buf;
        msgrcv(msqid, &buf, sizeof(buf), RED, 0);
        printf("Current state: %d\n", buf.state);
        sleep(1);
    }

    return 0;
}
