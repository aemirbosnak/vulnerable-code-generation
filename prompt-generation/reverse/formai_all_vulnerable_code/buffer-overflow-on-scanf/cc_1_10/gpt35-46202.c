//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100

struct LogEntry {
  char source_ip[16];
  char destination_ip[16];
  char timestamp[20];
  char message[100];
};

void print_entry(struct LogEntry entry) {
  printf("%s %s [%s] \"%s\"\n", entry.source_ip, entry.destination_ip, entry.timestamp, entry.message);
}

int main() {
  struct LogEntry log[MAX_LOG_ENTRIES];
  int num_entries = 0;

  printf("Welcome to the Intrusion Detection System!\n");

  char command[10];
  while (1) {
    printf("> ");
    scanf("%s", command);

    if (strcmp(command, "quit") == 0) {
      printf("Goodbye!\n");
      break;
    }

    if (strcmp(command, "log") == 0) {
      struct LogEntry new_entry;
      char source_ip[16], destination_ip[16], timestamp[20], message[100];

      printf("Enter the source IP: ");
      scanf("%s", source_ip);
      strcpy(new_entry.source_ip, source_ip);

      printf("Enter the destination IP: ");
      scanf("%s", destination_ip);
      strcpy(new_entry.destination_ip, destination_ip);

      printf("Enter the timestamp: ");
      scanf("%s", timestamp);
      strcpy(new_entry.timestamp, timestamp);

      printf("Enter the message: ");
      scanf("%s", message);
      strcpy(new_entry.message, message);

      if (num_entries < MAX_LOG_ENTRIES) {
        log[num_entries] = new_entry;
        printf("Log entry added.\n");
        num_entries++;
      } else {
        printf("Log is full, entry not added.\n");
      }
    }

    if (strcmp(command, "show") == 0) {
      for (int i = 0; i < num_entries; i++) {
        print_entry(log[i]);
      }
    }

    if (strcmp(command, "search") == 0) {
      char ip_to_search[16];
      printf("Enter the IP to search for: ");
      scanf("%s", ip_to_search);

      for (int i = 0; i < num_entries; i++) {
        if (strcmp(log[i].source_ip, ip_to_search) == 0 || strcmp(log[i].destination_ip, ip_to_search) == 0) {
          print_entry(log[i]);
        }
      }
    }
  }

  return 0;
}