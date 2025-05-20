//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Ada Lovelace
#include <pcap.h>
#include <stdio.h>

int main()
{
  char devices[100];
  pcap_if_t *alldevs;
  pcap_t *handle;
  int count = 0;

  if (pcap_findalldevs(&alldevs, NULL) == -1)
  {
    fprintf(stderr, "Error finding devices: %s\n", pcap_geterr(handle));
    return 1;
  }

  for (pcap_if_t *d = alldevs; d; d = d->next)
  {
    printf("%d. %s\n", ++count, d->name);
    if (d->description)
      printf("    %s\n", d->description);
    printf("\n");
  }

  pcap_freealldevs(alldevs);

  printf("Enter the device to capture on: ");
  scanf("%s", devices);

  handle = pcap_open_live(devices, 65535, 1, 1000, NULL);
  if (handle == NULL)
  {
    fprintf(stderr, "Error opening live capture: %s\n", pcap_geterr(handle));
    return 1;
  }

  while (1)
  {
    struct pcap_pkthdr *header;
    const u_char *data;

    int res = pcap_next_ex(handle, &header, &data);
    if (res == -1)
    {
      fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
      break;
    }

    printf("Packet captured: %d bytes\n", header->caplen);
  }

  pcap_close(handle);

  return 0;
}