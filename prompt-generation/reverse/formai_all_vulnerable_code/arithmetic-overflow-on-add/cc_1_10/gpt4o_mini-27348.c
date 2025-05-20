//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <time.h>

#define MAX_VEHICLES 5
#define INTERSECTION_COUNT 3
#define MSG_SIZE 64

struct msg_buffer {
    long msg_type;
    char msg_text[MSG_SIZE];
};

typedef struct {
    int id;
    int vehicle_count;
} intersection;

void simulate_intersection(int id, int msgid) {
    intersection inter = {id, 0};
    srand(time(NULL) + id);

    while (1) {
        inter.vehicle_count = rand() % MAX_VEHICLES + 1; // Randomly generate vehicle count
        printf("Intersection %d: %d vehicles trying to pass\n", inter.id, inter.vehicle_count);
        
        struct msg_buffer message;
        message.msg_type = inter.id;

        sprintf(message.msg_text, "Vehicles at Intersection %d: %d", inter.id, inter.vehicle_count);

        // Send the message to the message queue
        msgsnd(msgid, &message, sizeof(message.msg_text), 0);
        sleep(2); // Simulate time taken for vehicles to pass
    }
}

void monitor_traffic(int msgid) {
    struct msg_buffer message;

    while (1) {
        // Receive messages from intersections
        msgrcv(msgid, &message, sizeof(message.msg_text), 0, 0);
        printf("Monitor: %s\n", message.msg_text);
        sleep(1); // Simulate monitoring time
    }
}

int main() {
    key_t key = ftok("traffic_sim", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    
    if (msgid == -1) {
        perror("msgget failed");
        exit(EXIT_FAILURE);
    }

    pid_t processes[INTERSECTION_COUNT];

    for (int i = 0; i < INTERSECTION_COUNT; i++) {
        processes[i] = fork();
        if (processes[i] == 0) {
            // In child process, simulate intersections
            simulate_intersection(i + 1, msgid);
            exit(0);
        } else if (processes[i] < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }
    }

    // In parent process, monitor traffic
    monitor_traffic(msgid);

    // Clean up
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}