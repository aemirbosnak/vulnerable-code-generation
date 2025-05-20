//FormAI DATASET v1.0 Category: Network Ping Test ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <netinet/in.h>
#include <netdb.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define MAX_WAIT_TIME   2
#define MAX_NO_PACKETS  3
#define MAX_COUNT       10
#define PACKET_SIZE     64

int icmp_sockfd = 0;
int packets_send = 0, packets_recv = 0;

struct sockaddr_in dest_addr;

pthread_mutex_t mutex;

struct timeval prev_send_time, curr_recv_time;

struct timeval timeout = {MAX_WAIT_TIME, 0};

void start_ping(const char* ip_address);

unsigned short checksum(unsigned short *buffer, int size);
void fill_packet(char *packet, int sequence);
int send_ping(int sockfd, const struct sockaddr_in *dest_addr);
int recv_ping(int sockfd, struct sockaddr_in *src_addr);
void listen_for_response(const char* ip_address);
void print_ping_statistics();

// Main Function Driver
int main() {
    char ip_address[20] = "";
    printf("Enter IP Address: ");
    scanf("%s", ip_address);
    start_ping(ip_address);
    return 0;
}

// Function to start multi-threaded ping test
void start_ping(const char* ip_address) {
    pthread_t listen_thread;
    int listen_thread_id;
    // Initialise mutex
    if(pthread_mutex_init(&mutex, NULL) !=0) {
        printf("Mutex Initialisation Failed!\n");
        exit(-1);
    }
    // Create listen thread id
    listen_thread_id = pthread_create(&listen_thread, NULL, (void*) &listen_for_response, (void*) ip_address);
    // Check if thread was created successfully
    if(listen_thread_id != 0) {
        printf("Thread Creation Failed!\n");
        exit(-1);
    }
    // Wait for listen thread to complete execution
    pthread_join(listen_thread, NULL);
}

// Function to initialise and send ping packets
int send_ping(int sockfd, const struct sockaddr_in *dest_addr) {
    // Initialise packet buffer
    char packet[PACKET_SIZE];
    memset(packet, 0, PACKET_SIZE);
    // Fill packet buffer with identifier and sequence numbers
    fill_packet(packet, packets_send+1);
    // Calculate checksum of packet
    unsigned short checksum_init = checksum((unsigned short*) packet, PACKET_SIZE);
    // Place checksum into packet buffer
    memcpy(packet+2, &checksum_init, sizeof(checksum_init));
    // Send packet to destination address
    int bytes_sent = sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr*) dest_addr, sizeof(struct sockaddr));
    if(bytes_sent < 0) {
        printf("Error Sending Packet to Destination Address!\n");
    }
    else {
        packets_send++;
        gettimeofday(&prev_send_time, NULL);
    }
    return bytes_sent;
}

// Function to listen for ICMP responses
int recv_ping(int sockfd, struct sockaddr_in *src_addr) {
    // Initialise packet buffer
    char packet[PACKET_SIZE];
    memset(packet, 0, PACKET_SIZE);
    // Receive packet response
    int bytes_received = recvfrom(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr*) src_addr, (socklen_t*) sizeof(struct sockaddr));
    if (bytes_received < 0) {
        printf("Error Receiving Packet from Destination Address!\n");
    }
    else {
        packets_recv++;
        gettimeofday(&curr_recv_time, NULL);
    }
    return bytes_received;
}

// Function to listen for ICMP responses from destination address in a loop
void listen_for_response(const char* ip_address) {
    // Initialise socket file descriptor
    if((icmp_sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        printf("Socket Creation Failed!\n");
        exit(-1);
    }
    // Initialise destination address struct
    memset(&dest_addr, 0, sizeof(struct sockaddr_in));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(ip_address);
    // Send Ping Packets
    int i;
    for(i=0; i<MAX_COUNT; i++) {
        pthread_mutex_lock(&mutex);
        send_ping(icmp_sockfd, &dest_addr);
        pthread_mutex_unlock(&mutex);
        select(icmp_sockfd+1, (fd_set*) 0, (fd_set*) 0, (fd_set*) 0, &timeout);
    }
    // Wait for all packets to be received or timeout to occur
    print_ping_statistics();
    close(icmp_sockfd);
    pthread_exit(0);
}

// Function to fill packet buffer with identifier and sequence numbers
void fill_packet(char *packet, int sequence) {
    struct icmphdr *icmp_hdr;
    icmp_hdr = (struct icmphdr*) packet;
    icmp_hdr->type = ICMP_ECHO;
    icmp_hdr->code = 0;
    icmp_hdr->un.echo.id = getpid();
    icmp_hdr->un.echo.sequence = sequence;
    memset(packet + sizeof(struct icmphdr), 'p', PACKET_SIZE - sizeof(struct icmphdr));
}

// Function to calculate checksum of packet
unsigned short checksum(unsigned short *buffer, int size) {
    unsigned long cksum = 0;
    while(size > 1) {
        cksum += *buffer++;
        size -= sizeof(unsigned short);
    }
    if(size) {
        cksum += *(unsigned char*) buffer;
    }
    cksum = (cksum >> 16) + (cksum & 0xffff);
    cksum += (cksum >> 16);
    return (unsigned short)(~cksum);
}

// Function to output ping statistics to console
void print_ping_statistics() {
    double rtt_time = (curr_recv_time.tv_sec - prev_send_time.tv_sec) + (double) (curr_recv_time.tv_usec - prev_send_time.tv_usec) / 1000000;
    printf("Ping Statistics:\n");
    printf("-----------------\n");
    printf("%d Packets Sent\n", packets_send);
    printf("%d Packets Received\n", packets_recv);
    printf("%d Packets Lost\n", packets_send - packets_recv);
    printf("Approximate Round Trip Times in Milli-Seconds:\n");
    printf("Minimum = 0ms, Maximum = 0ms, Average = %fms\n", (double) rtt_time / packets_recv * 1000);
}