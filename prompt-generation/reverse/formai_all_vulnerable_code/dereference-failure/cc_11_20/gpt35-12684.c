//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: careful
/*
 * C Network Quality of Service (QoS) Monitor Example Program
 * 
 * This program measures the Quality of Service (QoS) of a network by
 * sending and receiving packets to a specific IP address and port,
 * and calculating statistics on the delay, jitter, and packet loss.
 * 
 * The program requires the libpcap library and must be run with root
 * privileges to capture network packets.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <pcap.h>

#define PACKET_SIZE 128
#define PACKET_INTERVAL 1000000 //1 second
#define NUM_PACKETS 100

struct ipheader {
    unsigned char ihl:4, version:4;
    unsigned char tos;
    unsigned short tot_len;
    unsigned short id;
    unsigned short frag_off;
    unsigned char ttl;
    unsigned char protocol;
    unsigned short check;
    unsigned int saddr;
    unsigned int daddr;
};

struct udpheader {
    unsigned short sport;
    unsigned short dport;
    unsigned short len;
    unsigned short crc;
};

struct packet {
    struct ipheader ip;
    struct udpheader udp;
    char data[PACKET_SIZE - sizeof(struct ipheader) - sizeof(struct udpheader)];
};

int main(int argc, char *argv[]) {
    char *ip = argv[1];
    char *port_str = argv[2];
    int port = atoi(port_str);
    struct in_addr addr;
    struct hostent *h;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char filter_exp[256];
    struct bpf_program fp;
    bpf_u_int32 netp, maskp;
    struct packet packets[NUM_PACKETS];
    struct timespec start_time, end_time, prev_time, diff_time;
    int i, sockfd, num_packets_sent, num_packets_received, num_packets_dropped;
    struct sockaddr_in dest_addr;
    socklen_t addr_len;
    fd_set fds;
    struct timeval tv;
        
    //Resolve IP address
    if(inet_aton(ip, &addr) == 0) {
        if((h = gethostbyname(ip)) == NULL) {
            printf("Error: Could not resolve IP address\n");
            return 1;
        }
        memcpy(&addr, h->h_addr, sizeof(struct in_addr));
    }
    
    //Open socket to send packets
    if((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
        printf("Error: Could not open socket\n");
        return 1;
    }
    
    //Set destination address
    memset(&dest_addr, 0, sizeof(struct sockaddr_in));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    dest_addr.sin_addr = addr;
    addr_len = sizeof(struct sockaddr_in);
    
    //Initialize packets
    for(i = 0; i < NUM_PACKETS; i++) {
        memset(&packets[i], 0, PACKET_SIZE);
        packets[i].ip.version = 4;
        packets[i].ip.ihl = 5;
        packets[i].ip.tos = 0;
        packets[i].ip.tot_len = htons(PACKET_SIZE);
        packets[i].ip.id = htons(i);
        packets[i].ip.frag_off = 0;
        packets[i].ip.ttl = 255;
        packets[i].ip.protocol = IPPROTO_UDP;
        packets[i].ip.check = 0;
        packets[i].ip.saddr = inet_addr("0.0.0.0");
        packets[i].ip.daddr = addr.s_addr;
        packets[i].udp.sport = htons(i);
        packets[i].udp.dport = htons(port);
        packets[i].udp.len = htons(sizeof(struct udpheader) + PACKET_SIZE - sizeof(struct ipheader) - sizeof(struct udpheader));
    }
    
    //Open pcap handle
    if(pcap_lookupnet(argv[3], &netp, &maskp, errbuf) == -1) {
        printf("Error: Failed to get network and mask\n");
        return 1;
    }
    handle = pcap_open_live(argv[3], BUFSIZ, 0, 1000, errbuf);
    if(handle == NULL) {
        printf("Error: Failed to open pcap handle\n");
        return 1;
    }
    
    //Compile and set filter
    snprintf(filter_exp, sizeof(filter_exp), "udp and src host %s and src port %d", ip, port);
    if(pcap_compile(handle, &fp, filter_exp, 0, maskp) == -1) {
        printf("Error: Failed to compile filter\n");
        return 1;
    }
    if(pcap_setfilter(handle, &fp) == -1) {
        printf("Error: Failed to set filter\n");
        return 1;
    }
    
    //Initialize stats
    num_packets_sent = 0;
    num_packets_received = 0;
    num_packets_dropped = 0;
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    prev_time = start_time;
    
    //Send and receive packets
    for(i = 0; i < NUM_PACKETS; i++) {
        //Send packet
        if(sendto(sockfd, &packets[i], PACKET_SIZE, 0, (struct sockaddr *)&dest_addr, addr_len) == -1) {
            printf("Error: Failed to send packet\n");
            num_packets_dropped++;
        } else {
            num_packets_sent++;
            //Wait for response
            FD_ZERO(&fds);
            FD_SET(sockfd, &fds);
            tv.tv_sec = 1;
            tv.tv_usec = 0;
            select(sockfd + 1, &fds, NULL, NULL, &tv);
            //Receive packet
            if(FD_ISSET(sockfd, &fds)) {
                if(recv(sockfd, &packets[i], PACKET_SIZE, 0) == -1) {
                    printf("Error: Failed to receive packet\n");
                    num_packets_dropped++;
                } else {
                    num_packets_received++;
                    //Calculate and print delay and jitter
                    clock_gettime(CLOCK_MONOTONIC, &end_time);
                    diff_time.tv_sec = end_time.tv_sec - prev_time.tv_sec;
                    diff_time.tv_nsec = end_time.tv_nsec - prev_time.tv_nsec;
                    if(diff_time.tv_nsec < 0) {
                        diff_time.tv_sec--;
                        diff_time.tv_nsec += 1000000000;
                    }
                    printf("Packet %d Delay: %ld.%09ld s\tJitter: %ld.%09ld s\n", i + 1, diff_time.tv_sec, diff_time.tv_nsec, diff_time.tv_sec - PACKET_INTERVAL / 1000000, diff_time.tv_nsec - PACKET_INTERVAL % 1000000 * 1000);
                    prev_time = end_time;
                }
            } else {
                printf("Error: Timeout waiting for packet\n");
                num_packets_dropped++;
            }
        }
        //Sleep for packet interval
        usleep(PACKET_INTERVAL);
    }
    
    //Print statistics
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    printf("Packets Sent: %d\tPackets Received: %d\tPacket Loss: %d%%\n", num_packets_sent, num_packets_received, num_packets_dropped * 100 / NUM_PACKETS);
    printf("Duration: %ld.%09ld s\n", end_time.tv_sec - start_time.tv_sec, end_time.tv_nsec - start_time.tv_nsec);
    
    //Cleanup
    close(sockfd);
    pcap_close(handle);
    
    return 0;
}