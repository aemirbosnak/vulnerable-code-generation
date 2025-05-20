//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>

int main() {
  // Let's play the role of the network topology mapper!
  
  // First, we need a way to see the network traffic. Let's pretend we're a fancy traffic cop with a radar gun.
  char *device = pcap_lookupdev(NULL);
  if (device == NULL) {
    printf("Oops! No radar gun available. Can't map the network without it!\n");
    return 1;
  }

  // Now, let's set up our radar gun to listen to the network traffic.
  pcap_t *handle = pcap_open_live(device, 65535, 1, 1000, NULL);
  if (handle == NULL) {
    printf("Darn it! My radar gun is malfunctioning. Can't map the network now!\n");
    return 1;
  }

  // Time to start listening! Let's pretend we're a superhero with super hearing.
  printf("Activating my super hearing! Listening to the network traffic...\n");

  // We'll keep a list of all the devices we hear from.
  char **devices = malloc(sizeof(char *) * 100);
  int num_devices = 0;

  // And a list of all the connections we see.
  char **connections = malloc(sizeof(char *) * 100);
  int num_connections = 0;

  // Okay, here comes the traffic! Let's analyze each packet.
  while (1) {
    struct pcap_pkthdr *header;
    const unsigned char *packet;
    int res = pcap_next_ex(handle, &header, &packet);
    if (res == 0) continue;
    if (res == -1) break;

    // First, let's see who's talking.
    struct sockaddr_in *source_addr = (struct sockaddr_in *)pcap_datalink(handle);
    char *source_ip = inet_ntoa(source_addr->sin_addr);

    // And who's listening.
    struct sockaddr_in *dest_addr = (struct sockaddr_in *)pcap_datalink(handle);
    char *dest_ip = inet_ntoa(dest_addr->sin_addr);

    // Now, let's see if we know these devices already.
    int source_index = -1;
    for (int i = 0; i < num_devices; i++) {
      if (strcmp(devices[i], source_ip) == 0) {
        source_index = i;
        break;
      }
    }
    if (source_index == -1) {
      // Oh, a new device! Let's add it to our list.
      devices[num_devices++] = strdup(source_ip);
      source_index = num_devices - 1;
    }

    int dest_index = -1;
    for (int i = 0; i < num_devices; i++) {
      if (strcmp(devices[i], dest_ip) == 0) {
        dest_index = i;
        break;
      }
    }
    if (dest_index == -1) {
      // Another new device! Let's add it to our list.
      devices[num_devices++] = strdup(dest_ip);
      dest_index = num_devices - 1;
    }

    // Now, let's draw a line between them to show their connection.
    char *connection = malloc(strlen(source_ip) + strlen(dest_ip) + 2);
    sprintf(connection, "%s-%s", source_ip, dest_ip);
    connections[num_connections++] = connection;
  }

  // Phew! We're done! Let's print out our network map.
  printf("Here's a map of the network:\n");
  for (int i = 0; i < num_devices; i++) {
    printf("Device %d: %s\n", i, devices[i]);
  }
  for (int i = 0; i < num_connections; i++) {
    printf("Connection %d: %s\n", i, connections[i]);
  }

  // And let's clean up our mess before we go.
  for (int i = 0; i < num_devices; i++) {
    free(devices[i]);
  }
  free(devices);
  for (int i = 0; i < num_connections; i++) {
    free(connections[i]);
  }
  free(connections);

  // Mission accomplished! We're the coolest network topology mappers in the world!
  return 0;
}