//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<pcap.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

//Error handler function that will be called in case of any error
void error_handler(const char *msg){
    printf("Error: %s\n",msg);
    exit(1);
}

int main(){

    pcap_if_t *alldevsp;
    pcap_if_t *device;
    pcap_t *handle;
    bpf_u_int32 net;
    char errbuf[100],*devname;
    struct pcap_pkthdr header;
    const u_char *pkt_data;
    int i,j;

    //Finding all the available devices
    if(pcap_findalldevs(&alldevsp,errbuf)){
        error_handler("No devices found!");
    }
    //Printing the available devices
    printf("Available Devices are:\n");
    for(device=alldevsp,i=0;device!=NULL;device=device->next,i++){
        printf("%d. %s - %s\n",i+1,device->name,device->description);
    }
    //Asking user to select the device they want to use for sniffing
    printf("Enter the number of the device to use: ");
    scanf("%d",&j);
    if(j>i){
        error_handler("Invalid device selected!");
    }
    for(device=alldevsp,i=0;i<j-1;device=device->next,i++);

    //Opening the device for sniffing
    if((handle=pcap_open_live(device->name,1500,1,0,errbuf))==NULL){
        error_handler("Cannot open device!");
    }

    while(1){
        //Getting the next packet
        pkt_data = pcap_next(handle,&header);
        if(pkt_data==NULL){
            printf("Packet Capture Ended!\n");
            break;
        }
        printf("Packet Size: %d bytes\n",header.len);
    }

    return 0;
}