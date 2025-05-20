//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 100
#define MAX_IP_LENGTH 16

struct entry {
    char ip[MAX_IP_LENGTH];
    char request[MAX_ENTRY_LENGTH];
};

int num_entries = 0;
struct entry entries[MAX_ENTRIES];

void add_entry(char* ip, char* request) {
    if (num_entries >= MAX_ENTRIES) {
        printf("ERROR: Maximum number of entries reached.\n");
        return;
    }

    strncpy(entries[num_entries].ip, ip, MAX_IP_LENGTH);
    strncpy(entries[num_entries].request, request, MAX_ENTRY_LENGTH);

    num_entries++;
}

int search_entries(char* ip) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].ip, ip) == 0) {
            return i;
        }
    }

    return -1;
}

void print_entries() {
    int i;

    for (i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].ip, entries[i].request);
    }
}

int main() {
    char ip[MAX_IP_LENGTH];
    char request[MAX_ENTRY_LENGTH];

    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Enter request: ");
    scanf("%s", request);

    add_entry(ip, request);

    printf("Entries:\n");
    print_entries();

    return 0;
}