//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Romeo and Juliet
/* 
In fair network, where we lay our scene,
From ancient QoS break to new unknown routine,
Where packets lost and latency high,
Our software seeks to smooth the cry.

From forth the fatal lines of code,
A monitor, to measure and forebode,
What bandwidth, in a jittery display,
May end up wasted and tossed away.

Two classes, both alike in rank,
In fair computer, where we use our plank,
From busy servers to streaming sites,
With flow control and transfer rates of delights.

And as our program doth run amain,
To measure, test, and transform the strain,
We shall see the count of packets fly,
And judge their fate both truthfully and wry.

This, then, is our Quality of Service tale,
To keep the network from a destined fail,
With code and calculation, we do invest,
In making sure the connection's at its best.

*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_PACKETS 1000

int packets_received = 0;
int packets_lost = 0;
int packets_delayed = 0;

void receive_packet() {
    printf("Packet received!\n");
    packets_received++;
}

void lose_packet() {
    printf("Packet lost!\n");
    packets_lost++;
}

void delay_packet() {
    printf("Packet delayed!\n");
    packets_delayed++;
}

void display_summary() {
    printf("Packets received: %d\n", packets_received);
    printf("Packets lost: %d\n", packets_lost);
    printf("Packets delayed: %d\n", packets_delayed);
    printf("Packet loss percentage: %.2f%%\n", (float)packets_lost/packets_received*100);
}

int main() {
    printf("Welcome to the Quality of Service monitor!\n");
    printf("Press 1 to receive packet, 2 to lose packet, 3 to delay packet, 4 to display summary, 5 to exit\n");

    int choice, packets_to_send;
    while(choice != 5) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if(packets_received < MAX_PACKETS) {
                    receive_packet();
                }
                else {
                    printf("Maximum packets received. Cannot receive any more packets!\n");
                }
                break;
            case 2:
                lose_packet();
                break;
            case 3:
                delay_packet();
                break;
            case 4:
                display_summary();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}