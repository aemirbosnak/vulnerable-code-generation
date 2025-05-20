//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: automated
#include <stdio.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packetData);

int main(int argc, char **argv)
{
    pcap_t *descr;
    char errbuf[PCAP_ERRBUF_SIZE];
    const u_char *packet;
    struct pcap_pkthdr hdr;
    struct bpf_program fp;            /* compiled filter program (expression) */
    bpf_u_int32 maskp;                /* subnet mask */
    bpf_u_int32 netp;                 /* ip */
    int i,ans;
    char devList[5][100] = {"eth0","eth1","eth2","eth3","eth4"};

    printf("List of available devices on this machine : \n");
  
    for(i=0;i<5;i++)
    {
        printf("%d. %s\n",i+1,devList[i]);
    }

    printf("\nEnter the number corresponding to desired device :");
  
    scanf("%d",&ans);

    int devno = ans-1;
  
    descr = pcap_open_live(devList[devno], BUFSIZ, 1,-1, errbuf);

    if(descr == NULL)
    {
        printf("pcap_open_live() failed: %s\n", errbuf);
        return 1;
    }

    if(pcap_lookupnet(devList[devno], &netp, &maskp, errbuf) == -1)
    {
        printf("Error: %s\n", errbuf);
        return 1;
    }

    // Now both netp and maskp contain valid values

    char filterString[50];
    printf("\nEnter the filter expression (protocol or port number): ");
    scanf("%s", filterString);

    if(pcap_compile(descr, &fp, filterString, 0, netp) == -1)
    {
        printf("Error compiling filter: %s\n", pcap_geterr(descr));
        return 1;
    }

    if(pcap_setfilter(descr, &fp) == -1)
    {
        printf("Error setting filter: %s\n", pcap_geterr(descr));
        return 1;
    }

    printf("Packet capturing using filter: %s\n", filterString);
    pcap_loop(descr, -1, packetHandler, NULL);
    pcap_close(descr);

    return 0;
}

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packetData)
{
    printf("Packet captured of length : %d\n", pkthdr->len);
}