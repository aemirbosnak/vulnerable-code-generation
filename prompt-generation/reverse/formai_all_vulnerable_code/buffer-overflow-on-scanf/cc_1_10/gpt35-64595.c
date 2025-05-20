//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a structure for storing information about network devices
struct device {
    char name[20];
    char type[10];
    char ip[15];
    struct device *next;
};

// Define a function for adding devices to the network topology
void add_device(struct device **root, char name[20], char type[10], char ip[15]) {
    struct device *new_device = (struct device*) malloc(sizeof(struct device));
    strcpy(new_device->name, name);
    strcpy(new_device->type, type);
    strcpy(new_device->ip, ip);
    new_device->next = NULL;

    if (*root == NULL) {
        *root = new_device;
    } else {
        struct device *current = *root;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_device;
    }
}

// Define a function for printing out the network topology
void print_topology(struct device *root) {
    printf("*******************************\n");
    printf("CYBERNET NETWORK TOPOLOGY MAPPER\n");
    printf("*******************************\n");

    if (root == NULL) {
        printf("No devices found.\n");
    } else {
        printf("Device Name\tDevice Type\tIP Address\n");
        printf("-----------\t-----------\t----------\n");
        
        struct device *current = root;
        while (current != NULL) {
            printf("%s\t\t%s\t\t%s\n", current->name, current->type, current->ip);
            current = current->next;
        }
    }
}

int main() {
    struct device *root = NULL;
    char choice;
    do {
        system("clear");
        printf("******************************\n");
        printf("CYBERNET NETWORK TOPOLOGY MAPPER\n");
        printf("******************************\n");
        printf("1. Add device\n");
        printf("2. Print network topology\n");
        printf("3. Exit\n");
        printf("Enter choice (1-3): ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1': {
                char name[20], type[10], ip[15];
                printf("\nEnter device name: ");
                scanf("%s", name);
                printf("Enter device type: ");
                scanf("%s", type);
                printf("Enter device IP address: ");
                scanf("%s", ip);
                add_device(&root, name, type, ip);
                printf("\nDevice added successfully.\n");
                break;
            }
            case '2': {
                print_topology(root);
                printf("\nPress any key to continue...");
                getchar();
                break;
            }
            case '3': {
                printf("\nTerminating program...\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice. Please try again.\n");
                break;
            }
        }
    } while (true);

    return 0;
}