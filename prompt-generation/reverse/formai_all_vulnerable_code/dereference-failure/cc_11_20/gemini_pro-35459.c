//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main() {
  char *dev;
  bpf_u_int32 netp;  
  bpf_u_int32 maskp; 
  pcap_t *handle; 
  char errbuf[PCAP_ERRBUF_SIZE]; 
  struct pcap_pkthdr *header; 
  const u_char *data; 
  char filter_exp[] = "tcp";   
  struct bpf_program fp;     
  int i;

  dev = pcap_lookupdev(errbuf);
  if (dev == NULL) {
    printf("Error: %s\n", errbuf);
    exit(1);
  }

  if (pcap_lookupnet(dev, &netp, &maskp, errbuf) == -1) {
    printf("Error: %s\n", errbuf);
    exit(1);
  }

  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    printf("Error: %s\n", errbuf);
    exit(1);
  }

  if (pcap_compile(handle, &fp, filter_exp, 0, netp) == -1) {
    printf("Error: %s\n", pcap_geterr(handle));
    exit(1);
  }

  if (pcap_setfilter(handle, &fp) == -1) {
    printf("Error: %s\n", pcap_geterr(handle));
    exit(1);
  }

  while (1) {
    int res = pcap_next_ex(handle, &header, &data);
    if (res == 0) continue;
    if (res == -1) {
      printf("Error: %s\n", pcap_geterr(handle));
      exit(1);
    }

    printf("Packet length: %d\n", header->len);
    printf("Number of bytes captured: %d\n", header->caplen);
    printf("Time stamp: %s\n", ctime((const time_t *) &header->ts.tv_sec));

    printf("Source address: ");
    for (i = 0; i < header->caplen; i++) {
      printf("%02x ", data[i]);
    }
    printf("\n");

    printf("Destination address: ");
    for (i = 0; i < header->caplen; i++) {
      printf("%02x ", data[i]);
    }
    printf("\n\n");
  }

  pcap_close(handle);
  return 0;
}