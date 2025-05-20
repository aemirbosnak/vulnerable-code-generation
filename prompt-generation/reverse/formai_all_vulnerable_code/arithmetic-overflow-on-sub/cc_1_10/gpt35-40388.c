//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: accurate
/* 
   This program monitors the network Quality of Service (QoS) by measuring the Round-Trip Time (RTT) 
   and Jitter of transmitted packets.
   
   Author: [Your Name]
   Date: [Date of completion]
   Language: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //for sleep function
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>
#include <math.h>

#define PORT 8080
#define PACKET_SIZE 1024 //size of the packet to be sent

//function definition to calculate mean
float mean(int n, float x[]) {
    int i;
    float sum = 0.0, avg;
    for (i = 0; i < n; i++) {
        sum += x[i];
    }
    avg = sum / n;
    return avg;
}

//function definition to calculate standard deviation
float std_dev(int n, float x[], float mean) {
    int i;
    float variance = 0.0, sd;
    for (i = 0; i < n; i++) {
        variance += pow(x[i] - mean, 2);
    }
    sd = sqrt(variance / n);
    return sd;
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[PACKET_SIZE];
    float rtt[10], jitter[10];
    int i, count = 0;
    float mean_rtt, std_dev_rtt, mean_jitter, std_dev_jitter;
    time_t t;

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    //send and receive packets every second
    while(count < 10) {
        //start the timer
        clock_t start = clock();

        //send the packet
        sendto(sockfd, (const char *)buffer, sizeof(buffer), MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr));
        
        //wait for the response
        recvfrom(sockfd, (char *)buffer, sizeof(buffer), MSG_WAITALL, (struct sockaddr *) &servaddr, sizeof(servaddr));

        //end the timer
        clock_t end = clock();
        double rtt_ms = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;

        //calculate jitter
        if(count > 0) {
            jitter[count] = fabs(rtt_ms - rtt[count-1]);
        }

        //add the RTT to the array
        rtt[count] = rtt_ms;

        //print the results
        printf("Packet %d: RTT = %f ms, Jitter = %f ms\n", count+1, rtt_ms, jitter[count]);

        //increment count and wait for 1 second before sending the next packet
        count++;
        sleep(1);
    }

    //calculate the mean and standard deviation for RTT and Jitter
    mean_rtt = mean(10, rtt);
    std_dev_rtt = std_dev(10, rtt, mean_rtt);
    mean_jitter = mean(10, jitter);
    std_dev_jitter = std_dev(10, jitter, mean_jitter);

    //print the final results
    printf("\n--- Network Quality of Service ---\n");
    printf("Mean RTT: %f ms\n", mean_rtt);
    printf("Standard Deviation of RTT: %f ms\n", std_dev_rtt);
    printf("Mean Jitter: %f ms\n", mean_jitter);
    printf("Standard Deviation of Jitter: %f ms\n", std_dev_jitter);

    close(sockfd);
    return 0;
}