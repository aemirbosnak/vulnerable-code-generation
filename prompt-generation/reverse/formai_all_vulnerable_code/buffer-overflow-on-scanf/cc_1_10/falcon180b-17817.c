//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    char name[MAX_SIZE];
    int priority;
    int bandwidth;
    int delay;
    int jitter;
    int packet_loss;
} QoS;

void print_qos(QoS* qos) {
    printf("Name: %s\n", qos->name);
    printf("Priority: %d\n", qos->priority);
    printf("Bandwidth: %d\n", qos->bandwidth);
    printf("Delay: %d\n", qos->delay);
    printf("Jitter: %d\n", qos->jitter);
    printf("Packet Loss: %d\n", qos->packet_loss);
}

void set_qos(QoS* qos, char* name, int priority, int bandwidth, int delay, int jitter, int packet_loss) {
    strcpy(qos->name, name);
    qos->priority = priority;
    qos->bandwidth = bandwidth;
    qos->delay = delay;
    qos->jitter = jitter;
    qos->packet_loss = packet_loss;
}

int main() {
    QoS qos[10];
    int num_qos = 0;

    while (1) {
        printf("Enter 1 to add QoS, 2 to display QoS, 3 to exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_qos == 10) {
                    printf("Maximum QoS reached\n");
                } else {
                    printf("Enter name of QoS: ");
                    char name[MAX_SIZE];
                    scanf("%s", name);
                    printf("Enter priority (0-7): ");
                    int priority;
                    scanf("%d", &priority);
                    printf("Enter bandwidth (0-100): ");
                    int bandwidth;
                    scanf("%d", &bandwidth);
                    printf("Enter delay (0-100): ");
                    int delay;
                    scanf("%d", &delay);
                    printf("Enter jitter (0-100): ");
                    int jitter;
                    scanf("%d", &jitter);
                    printf("Enter packet loss (0-100): ");
                    int packet_loss;
                    scanf("%d", &packet_loss);
                    set_qos(&qos[num_qos], name, priority, bandwidth, delay, jitter, packet_loss);
                    num_qos++;
                }
                break;
            case 2:
                printf("QoS List:\n");
                for (int i = 0; i < num_qos; i++) {
                    print_qos(&qos[i]);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}