//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

#define BUF_SIZE 1024

struct packet {
    int size;
    int delay;
    int loss;
    int jitter;
};

struct node {
    struct packet *packet;
    struct node *next;
};

struct node *head = NULL;

void enqueue(struct packet *pkt) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->packet = pkt;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

struct packet *dequeue() {
    struct node *temp = head;
    struct packet *pkt = NULL;
    if (temp!= NULL) {
        pkt = temp->packet;
        head = temp->next;
        free(temp);
    }
    return pkt;
}

int main() {
    int i, j, n, m, count = 0;
    double avg_delay = 0, avg_loss = 0, avg_jitter = 0;
    char filename[100];

    printf("Enter the number of packets: ");
    scanf("%d", &n);

    printf("Enter the number of nodes: ");
    scanf("%d", &m);

    struct node *nodes[m];

    for (i = 0; i < m; i++) {
        nodes[i] = (struct node *)malloc(sizeof(struct node));
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            struct packet *pkt = (struct packet *)malloc(sizeof(struct packet));
            pkt->size = rand() % 1024 + 1;
            pkt->delay = rand() % 100;
            pkt->loss = rand() % 2;
            pkt->jitter = rand() % 10;

            enqueue(pkt);

            struct node *node = nodes[i];

            while (node!= NULL) {
                if (node->packet == NULL) {
                    node->packet = dequeue();
                    count++;
                }
                node = node->next;
            }
        }
    }

    for (i = 0; i < m; i++) {
        struct node *node = nodes[i];

        while (node!= NULL) {
            struct packet *pkt = node->packet;

            avg_delay += pkt->delay;
            avg_loss += pkt->loss;
            avg_jitter += pkt->jitter;

            node = node->next;
        }
    }

    avg_delay /= n;
    avg_loss /= n;
    avg_jitter /= n;

    printf("Number of packets received: %d\n", count);
    printf("Average delay: %.2f ms\n", avg_delay);
    printf("Average loss: %.2f %%\n", avg_loss * 100);
    printf("Average jitter: %.2f ms\n", avg_jitter);

    return 0;
}