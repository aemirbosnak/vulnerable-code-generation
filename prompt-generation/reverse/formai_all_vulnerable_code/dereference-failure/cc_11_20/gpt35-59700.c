//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Sherlock Holmes
#include<stdio.h>
#include<pcap.h>

int main()
{
    pcap_t *handle; // packet capture descriptor
    char* device; // name of the network device
    char error_buffer[PCAP_ERRBUF_SIZE]; // error buffer
    int timeout_limit = 10000; // timeout limit in milliseconds
    int ret_val; // return value of pcap_next_ex
    struct pcap_pkthdr packet; // packet header
    const unsigned char* packet_data; // packet data
    int count = 1; // packet count
    printf("Sherlock Holmes style C Wireless Network Scanner\n");
    device = pcap_lookupdev(error_buffer); // get the network device name
    if(device == NULL)
    {
        printf("Error Occured: %s\n",error_buffer); // print the error message
        return 1; // return error
    }
    handle = pcap_create(device,error_buffer); // create a packet capture descriptor
    if(handle == NULL)
    {
        printf("Error Occured: %s\n",error_buffer); // print the error message
        return 1; // return error
    }
    ret_val = pcap_set_snaplen(handle,65535); // set the snap length
    if(ret_val != 0)
    {
        printf("Error Occured: %s\n",pcap_geterr(handle)); //print the error message
        return 1; // return error
    }
    ret_val = pcap_set_promisc(handle,1); // set the promiscuous mode
    if(ret_val != 0)
    {
        printf("Error Occured: %s\n",pcap_geterr(handle)); // print the error message
        return 1; // return error
    }
    ret_val = pcap_set_timeout(handle,timeout_limit); // set the timeout
    if(ret_val != 0)
    {
        printf("Error Occured: %s\n",pcap_geterr(handle)); // print the error message
        return 1; // return error
    }
    ret_val = pcap_activate(handle); // activate the packet capture descriptor
    if(ret_val != 0)
    {
        printf("Error Occured: %s\n",pcap_geterr(handle)); // print the error message
        return 1; // return error
    }
    printf("Network Device: %s\n",device); // print the network device name
    printf("Scanning...\n");
    while (1) // infinite loop to capture packets
    {
        ret_val = pcap_next_ex(handle,&packet,&packet_data); // capture a packet
        if(ret_val == 0) // if timeout occurs
        {
            printf("Time Out Occured\n"); // print the message
            break; // break the loop
        }
        else if(ret_val == -1) // if error occurs
        {
            printf("Error Occured: %s\n",pcap_geterr(handle)); // print the error message
            break; // break the loop
        }
        else // if packet is captured
        {
            printf("\n\nPacket #%d\n",count++); 
            printf("Timestamp: %ld\n",packet.ts.tv_sec);
            printf("Length: %d bytes\n",packet.len);
            printf("Packet Data: \n");
            for(int i=0;i<packet.len;i++)
                printf("%02x ",packet_data[i]); // print the packet data in hexadecimal format
        }
    }
    pcap_close(handle); // close the packet capture descriptor
    printf("\nFinished\n");
    return 0; // return success
}