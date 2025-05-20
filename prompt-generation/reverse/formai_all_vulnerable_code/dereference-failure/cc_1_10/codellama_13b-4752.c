//Code Llama-13B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: random
#include <pcap.h>

int main(int argc, char **argv) {
  pcap_t *handle;
  char errbuf[PCAP_ERRBUF_SIZE];
  struct bpf_program filter;
  bpf_u_int32 mask;
  bpf_u_int32 net;
  char *dev = argv[1];
  char *filter_exp = argv[2];

  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
    return 2;
  }

  if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
    fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
    net = 0;
    mask = 0;
  }

  if (pcap_compile(handle, &filter, filter_exp, 0, net) == -1) {
    fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return 2;
  }

  if (pcap_setfilter(handle, &filter) == -1) {
    fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return 2;
  }

  while (1) {
    struct pcap_pkthdr header;
    const u_char *packet;

    packet = pcap_next(handle, &header);
    if (packet == NULL) {
      break;
    }

    printf("Packet length: %d\n", header.len);
    printf("Packet data: ");
    for (int i = 0; i < header.len; i++) {
      printf("%02x ", packet[i]);
    }
    printf("\n");
  }

  pcap_close(handle);
  return 0;
}