//FormAI DATASET v1.0 Category: Network Ping Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>

#define PING_TIMEOUT 2   //timeout for pinging
#define PING_PACKET_SIZE 64   //size of ping packets

//pinger function to handle actual pinging procedure
void pinger(int socket, struct sockaddr_in *ping_addr, char *ping_ip)
{
    //create buffer for ping packet
    char buffer[PING_PACKET_SIZE];
    memset(buffer, 0, sizeof(buffer));

    int sequence_num = 0;  //to keep track of sequencial number of packets
    int packets_received = 0;   //to count successful ping returns

    //loop to keep sending pings
    while(1)
    {
        //increment sequence number for each packet
        sequence_num++;

        //set packet header
        struct timeval *tval_send = (struct timeval *) buffer;
        gettimeofday(tval_send, NULL);
        
        //send packet
        if(sendto(socket, buffer, sizeof(buffer), 0, (struct sockaddr*) ping_addr, sizeof(struct sockaddr)) <= 0)
        {
            printf("Error sending packet\n");

        }
        else
        {
            printf("Sent ping to %s with sequence number %d\n", ping_ip, sequence_num);

        }

        //create buffer for ping response
        char response[PING_PACKET_SIZE];
        memset(response, 0, sizeof(response));

        //set response socket timeout for recvfrom function
        struct timeval timeout;
        timeout.tv_sec = PING_TIMEOUT;
        timeout.tv_usec = 0;
        if(setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0)
        {
            printf("Error setting timeout\n");

        }

        //receive response
        int recv_len = recvfrom(socket, response, sizeof(response), 0, NULL, NULL);

        if(recv_len < 0)
        {
            printf("Error receiving packet\n");

        }
        else
        {
            //extract packet header
            struct timeval *tval_recv = (struct timeval *) response;
            struct timeval tval_now;
            gettimeofday(&tval_now, NULL);

            //calculate and print ping response time
            double rtt = (tval_now.tv_sec - tval_recv->tv_sec) * 1000.0 + (tval_now.tv_usec - tval_recv->tv_usec) / 1000.0;
            printf("Received ping response from %s with sequence number %d in %.2f ms\n", ping_ip, sequence_num, rtt);

            //increment packets_received count
            packets_received++;

        }

        //wait for 1 sec before sending next ping
        sleep(1);

    }

}

int main()
{
    printf("Enter IP address to ping: ");
    char ping_ip[16];
    scanf("%s", ping_ip);

    //create socket for pinging
    int socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(socket_fd < 0)
    {
        printf("Error creating socket\n");
        return 0;
    }

    //declare and initialize sockaddr_in structure for pinging
    struct sockaddr_in ping_addr;
    memset(&ping_addr, 0, sizeof(ping_addr));
    ping_addr.sin_family = AF_INET;
    ping_addr.sin_port = htons(0);
    inet_pton(AF_INET, ping_ip, &ping_addr.sin_addr);

    //call pinger function for actual pinging
    pinger(socket_fd, &ping_addr, ping_ip);

    return 0;
}