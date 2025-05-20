//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_NETWORKS 50
#define MAX_NAME_LEN 32

// The Network Struct, named after the characters themselves
typedef struct Network {
    char name[MAX_NAME_LEN];
    int strength; // Signal strength
    int connected; // Connection status
} Network;

// Function to simulate the discovery of networks
void discoverNetworks(Network networks[], int *count) {
    FILE *fp = popen("nmcli -f SSID,SIGNAL dev wifi", "r");
    if (!fp) {
        fprintf(stderr, "Oh, woe betide! The networks are lost.\n");
        return;
    }

    char line[128];
    *count = 0;

    while (fgets(line, sizeof(line), fp) && *count < MAX_NETWORKS) {
        char name[MAX_NAME_LEN];
        int strength;
        sscanf(line, "%31[^,],%d", name, &strength);

        strcpy(networks[*count].name, name);
        networks[*count].strength = strength;
        networks[*count].connected = 0; // At first, no connection exists
        (*count)++;
    }
    pclose(fp);
}

// Function to present networks like a tragic play
void presentNetworks(Network networks[], int count) {
    printf("In fair Verona, where we lay our scene,\n");
    printf("Behold the networks, a tangled web unseen.\n\n");
    
    for (int i = 0; i < count; i++) {
        printf("%d. %s, with a strength of %d shines bright,\n", i + 1, networks[i].name, networks[i].strength);
    }

    printf("\nYet alas, dear Romeo! From which dost thou wish to connect?\n");
}

// Function to connect to the chosen network
void connectToNetwork(Network networks[], int count) {
    int choice;
    printf("\nChoose your network (enter the number): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > count) {
        printf("O fate! Invalid choice, as the stars would decree.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (i + 1 == choice) {
            networks[i].connected = 1; // Connection successful
            printf("Ah! Sweet love, you are now connected to %s!\n", networks[i].name);
            break;
        }
    }
}

// Function to simulate the longing of Juliet
void checkConnection(Network networks[], int count) {
    printf("\nBut hark! What if the connection was but a fleeting shadow?\n");
    for (int i = 0; i < count; i++) {
        if (networks[i].connected) {
            printf("Connected to %s, yet a distant dream it seems...\n", networks[i].name);
        } else {
            printf("%s still waits for your heart, dear Romeo...\n", networks[i].name);
        }
    }
}

int main() {
    Network networks[MAX_NETWORKS];
    int count;

    discoverNetworks(networks, &count);
    presentNetworks(networks, count);
    connectToNetwork(networks, count);
    checkConnection(networks, count);

    printf("\nTo be connected or not to be—such is the question...\n");
    return 0;
}