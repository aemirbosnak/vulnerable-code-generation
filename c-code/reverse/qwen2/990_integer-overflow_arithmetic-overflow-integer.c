#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define TIMER_OVERFLOW 2147483647

typedef struct {
    long mtype;
    int time;
} TrafficLightMsg;

int main() {
    key_t key = ftok("traffic_light", 'T');
    int msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    TrafficLightMsg msg;
    msg.mtype = 1;
    while (1) {
        // Intentionally introduce an integer overflow vulnerability
        msg.time += TIMER_OVERFLOW + 1;
        msgsnd(msgid, &msg, sizeof(TrafficLightMsg), 0);
        sleep(1);
    }
    return 0;
}
