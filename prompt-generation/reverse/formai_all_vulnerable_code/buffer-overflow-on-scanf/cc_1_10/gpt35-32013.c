//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 20
#define MAX_CONNECTIONS 40
#define MAX_BUF_SIZE 100

typedef struct {
    char name[MAX_BUF_SIZE];
    int num_connections;
} Device;

typedef struct {
    int from;
    int to;
} Connection;

void display_connections(Device devices[], Connection connections[], int num_devices, int num_connections) {
    int i, j;
    printf("\nDevice Connections\n-------------------\n");
    for (i = 0; i < num_devices; i++) {
        printf("%s - ", devices[i].name);
        for (j = 0; j < num_connections; j++) {
            if (connections[j].from == i) {
                printf("%s ", devices[connections[j].to].name);
            }
        }
        printf("\n");
    }
}

void add_device(Device devices[], int* num_devices) {
    if (*num_devices < MAX_DEVICES) {
        printf("\nEnter device name: ");
        fgets(devices[*num_devices].name, sizeof(devices[*num_devices].name), stdin);
        devices[*num_devices].name[strcspn(devices[*num_devices].name, "\n")] = 0; // remove newline character
        devices[*num_devices].num_connections = 0;
        (*num_devices)++;
    } else {
        printf("\nMaximum devices reached. Delete a device before adding a new one.\n");
    }
}

void remove_device(Device devices[], Connection connections[], int* num_devices, int* num_connections) {
    char device_name[MAX_BUF_SIZE];
    int i, j, idx = -1;
    printf("\nEnter device name to remove: ");
    fgets(device_name, sizeof(device_name), stdin);
    device_name[strcspn(device_name, "\n")] = 0; // remove newline character
    for (i = 0; i < *num_devices; i++) {
        if (strcmp(devices[i].name, device_name) == 0) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        printf("\nDevice not found.\n");
        return;
    }
    for (i = 0; i < *num_connections; i++) {
        if (connections[i].from == idx || connections[i].to == idx) {
            for (j = i; j < *num_connections - 1; j++) {
                connections[j] = connections[j + 1];
            }
            (*num_connections)--;
        }
    }
    for (i = idx; i < *num_devices - 1; i++) {
        devices[i] = devices[i + 1];
    }
    (*num_devices)--;
    printf("\nDevice removed successfully.\n");
}

void add_connection(Device devices[], Connection connections[], int* num_connections) {
    char device1[MAX_BUF_SIZE], device2[MAX_BUF_SIZE];
    int i, idx1 = -1, idx2 = -1;
    printf("\nEnter name of first device: ");
    fgets(device1, sizeof(device1), stdin);
    device1[strcspn(device1, "\n")] = 0; // remove newline character
    printf("Enter name of second device: ");
    fgets(device2, sizeof(device2), stdin);
    device2[strcspn(device2, "\n")] = 0; // remove newline character
    for (i = 0; i < MAX_DEVICES; i++) {
        if (idx1 != -1 && idx2 != -1) {
            break;
        }
        if (idx1 == -1 && strcmp(devices[i].name, device1) == 0) {
            idx1 = i;
        }
        if (idx2 == -1 && strcmp(devices[i].name, device2) == 0) {
            idx2 = i;
        }
    }
    if (idx1 == -1 || idx2 == -1) {
        printf("\nAt least one of the devices was not found.\n");
        return;
    }
    if (devices[idx1].num_connections >= MAX_CONNECTIONS || devices[idx2].num_connections >= MAX_CONNECTIONS) {
        printf("\nOne or both devices have reached maximum connections.\n");
        return;
    }
    connections[*num_connections].from = idx1;
    connections[*num_connections].to = idx2;
    (*num_connections)++;
    devices[idx1].num_connections++;
    devices[idx2].num_connections++;
    printf("\nConnection added successfully.\n");
}

void remove_connection(Device devices[], Connection connections[], int* num_connections) {
    char device1[MAX_BUF_SIZE], device2[MAX_BUF_SIZE];
    int i, j, idx1 = -1, idx2 = -1;
    printf("\nEnter name of first device: ");
    fgets(device1, sizeof(device1), stdin);
    device1[strcspn(device1, "\n")] = 0; // remove newline character
    printf("Enter name of second device: ");
    fgets(device2, sizeof(device2), stdin);
    device2[strcspn(device2, "\n")] = 0; // remove newline character
    for (i = 0; i < MAX_DEVICES; i++) {
        if (idx1 != -1 && idx2 != -1) {
            break;
        }
        if (idx1 == -1 && strcmp(devices[i].name, device1) == 0) {
            idx1 = i;
        }
        if (idx2 == -1 && strcmp(devices[i].name, device2) == 0) {
            idx2 = i;
        }
    }
    if (idx1 == -1 || idx2 == -1) {
        printf("\nAt least one of the devices was not found.\n");
        return;
    }
    for (i = 0; i < *num_connections; i++) {
        if ((connections[i].from == idx1 && connections[i].to == idx2) || (connections[i].from == idx2 && connections[i].to == idx1)) {
            for (j = i; j < *num_connections - 1; j++) {
                connections[j] = connections[j + 1];
            }
            (*num_connections)--;
            devices[idx1].num_connections--;
            devices[idx2].num_connections--;
            printf("\nConnection removed successfully.\n");
            return;
        }
    }
    printf("\nNo connection found between the two devices.\n");
}

int main() {
    Device devices[MAX_DEVICES];
    Connection connections[MAX_CONNECTIONS];
    int num_devices = 0, num_connections = 0;
    int choice;

    while (1) {
        printf("\nNetwork Topology Mapper\n-----------------------\n");
        printf("1. Add device\n");
        printf("2. Remove device\n");
        printf("3. Add connection\n");
        printf("4. Remove connection\n");
        printf("5. Display connections\n");
        printf("6. Quit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1:
                add_device(devices, &num_devices);
                break;
            case 2:
                remove_device(devices, connections, &num_devices, &num_connections);
                break;
            case 3:
                add_connection(devices, connections, &num_connections);
                break;
            case 4:
                remove_connection(devices, connections, &num_connections);
                break;
            case 5:
                display_connections(devices, connections, num_devices, num_connections);
                break;
            case 6:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}