//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_NAME_LEN 50

typedef struct Node {
    int deviceIndex;
    struct Node* next;
} Node;

typedef struct Device {
    char name[MAX_NAME_LEN];
    Node* adjacencyList;
} Device;

Device network[MAX_DEVICES];
int deviceCount = 0;

void addDevice(const char* name) {
    if (deviceCount >= MAX_DEVICES) {
        printf("Device limit reached!\n");
        return;
    }
    strcpy(network[deviceCount].name, name);
    network[deviceCount].adjacencyList = NULL;
    deviceCount++;
    printf("Device '%s' added.\n", name);
}

void addConnection(int deviceIndex1, int deviceIndex2) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->deviceIndex = deviceIndex2;
    newNode->next = network[deviceIndex1].adjacencyList;
    network[deviceIndex1].adjacencyList = newNode;
    
    // Add reverse connection for undirected graph
    newNode = (Node*)malloc(sizeof(Node));
    newNode->deviceIndex = deviceIndex1;
    newNode->next = network[deviceIndex2].adjacencyList;
    network[deviceIndex2].adjacencyList = newNode;

    printf("Connection created between '%s' and '%s'.\n", 
           network[deviceIndex1].name, network[deviceIndex2].name);
}

void displayTopology() {
    printf("\nNetwork Topology:\n");
    for (int i = 0; i < deviceCount; i++) {
        printf("%s:", network[i].name);
        Node* temp = network[i].adjacencyList;
        while (temp) {
            printf(" -> %s", network[temp->deviceIndex].name);
            temp = temp->next;
        }
        printf("\n");
    }
}

void findPath(int start, int end, int* visited, char* path, int index) {
    if (start == end) {
        path[index] = '\0';
        printf("Path found: %s\n", path);
        return;
    }
    
    visited[start] = 1;
    Node* adjList = network[start].adjacencyList;
    
    while (adjList) {
        if (!visited[adjList->deviceIndex]) {
            path[index] = (char)(start + 'A');  // assuming device names are single characters A-Z
            findPath(adjList->deviceIndex, end, visited, path, index + 1);
        }
        adjList = adjList->next;
    }
    visited[start] = 0; // Unmark for backtracking
}

void searchPath(char startName, char endName) {
    int start = startName - 'A';
    int end = endName - 'A';

    if (start < 0 || start >= deviceCount || end < 0 || end >= deviceCount) {
        printf("Invalid device names.\n");
        return;
    }
   
    int visited[MAX_DEVICES] = {0};
    char path[MAX_DEVICES];
    findPath(start, end, visited, path, 0);
}

int main() {
    int choice;
    char name[MAX_NAME_LEN];
    char startDevice, endDevice;

    while (1) {
        printf("\nNetwork Topology Mapper\n");
        printf("1. Add Device\n");
        printf("2. Add Connection\n");
        printf("3. Display Topology\n");
        printf("4. Find Path\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter device name (single character A-Z): ");
            scanf(" %c", &name[0]);
            name[1] = '\0';
            addDevice(name);
            break;
        case 2:
            printf("Enter the indices of two devices to connect (0-%d): ", deviceCount - 1);
            int index1, index2;
            scanf("%d %d", &index1, &index2);
            if (index1 < deviceCount && index2 < deviceCount) {
                addConnection(index1, index2);
            } else {
                printf("Invalid device indices.\n");
            }
            break;
        case 3:
            displayTopology();
            break;
        case 4:
            printf("Enter start and end devices (A-Z): ");
            scanf(" %c %c", &startDevice, &endDevice);
            searchPath(startDevice, endDevice);
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}