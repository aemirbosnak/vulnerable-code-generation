//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 4096
#define IP_HL(ip)       (((ip)->ip_vhl) & 0x0f)
#define IP_V(ip)        (((ip)->ip_vhl) >> 4)


struct ipheader {
    unsigned char ip_vhl;
    unsigned char ip_tos;
    unsigned short int ip_len;
    unsigned short int ip_id;
    unsigned short int ip_off;
    unsigned char ip_ttl;
    unsigned char ip_p;
    unsigned short int ip_sum;
    struct in_addr ip_src,ip_dst;
};

struct udpheader {
    unsigned short int udp_srcport;
    unsigned short int udp_dstport;
    unsigned short int udp_len;
    unsigned short int udp_checksum;
};

struct wifiheader {
    unsigned char wifi_fc[2];
    unsigned char wifi_dur[2];
    unsigned char wifi_addr1[6];
    unsigned char wifi_addr2[6];
    unsigned char wifi_addr3[6];
    unsigned char wifi_seq[2];
};

struct wifi_signal_strength {
    unsigned int bssid[6];
    int signal_strength;
};

char *mac_to_string(unsigned char *mac) {
    static char mac_string[19];
    snprintf(mac_string, sizeof(mac_string), "%02x:%02x:%02x:%02x:%02x:%02x",mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    return mac_string;
}

void print_wifi_signal_strength(struct wifi_signal_strength *signal_strengths, int num_signals) {
    printf("\n======= Wi-Fi Signal Strength Analyzer =======\n\n");
    printf("%-18s\tSignal Strength\n","BSSID");
    printf("----------------------------------------------\n");
    for(int i=0;i<num_signals;i++) {
        printf("%-18s\t%d\n",mac_to_string((unsigned char*)&signal_strengths[i].bssid),signal_strengths[i].signal_strength);
    }
}

int analyze_wifi_signal_strength(char *interface, struct wifi_signal_strength *signal_strengths) {
    int sockfd;
    struct sockaddr_in bind_addr;
    struct ipheader *ip;
    struct wifiheader *wifi;
    struct udpheader *udp;
    char packet[MAX_PACKET_SIZE];
    int packet_size,ip_hdr_size,wifi_hdr_size,udp_hdr_size;
    unsigned int bssid,num_signals=0;
    int signal_strength;
    char command[1024];
    FILE *fp;

    //construct the command to start tcpdump
    snprintf(command,sizeof(command),"tcpdump -l -i %s -e -s 256 type mgt subtype beacon",interface);

    //start tcpdump and redirect its output to a file
    snprintf(command,sizeof(command),"tcpdump -l -i %s -e -s 256 type mgt subtype beacon | stdbuf -oL cut -c 42- | stdbuf -oL uniq > tmp.txt &",interface);
    system(command);

    //open the file that contains the output of tcpdump
    if((fp=fopen("tmp.txt","r"))==NULL) {
        fprintf(stderr,"Error: Could not open tmp.txt\n");
        return -1;
    }

    while(fgets(packet,MAX_PACKET_SIZE,fp)) {
        //parse the packet
        ip=(struct ipheader*)packet;
        ip_hdr_size=IP_HL(ip)*4;
        wifi=(struct wifiheader*)(packet+ip_hdr_size);
        wifi_hdr_size=sizeof(struct wifiheader);
        udp=(struct udpheader*)(packet+ip_hdr_size+wifi_hdr_size);
        udp_hdr_size=sizeof(struct udpheader);

        //extract the bssid and signal strength from the packet
        memcpy(&bssid,wifi->wifi_addr3,sizeof(unsigned int));
        if(bssid!=0xffffffff && 
              (signal_strength=wifi->wifi_seq[1]-256)<=0 && 
              signal_strength>-100) {
            //add the bssid and signal strength to the list of network signals
            memcpy(signal_strengths[num_signals].bssid,&bssid,sizeof(unsigned int));
            signal_strengths[num_signals].signal_strength=signal_strength;
            num_signals++;
        }
    }
    fclose(fp);

    //kill tcpdump process
    system("pkill tcpdump");

    //print the signals detected
    print_wifi_signal_strength(signal_strengths,num_signals);

    return 0;
}

int main(int argc, char **argv) {
    struct wifi_signal_strength signal_strengths[1024];
    char interface[32];

    //get the name of the wireless interface to use
    printf("Enter the name of the wireless interface to use: ");
    fgets(interface,sizeof(interface),stdin);
    interface[strlen(interface)-1]='\0';

    //analyze the wifi signal strength
    analyze_wifi_signal_strength(interface,signal_strengths);

    return 0;
}