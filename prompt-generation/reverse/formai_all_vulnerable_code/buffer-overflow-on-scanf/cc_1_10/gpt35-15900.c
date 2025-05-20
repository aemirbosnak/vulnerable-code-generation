//FormAI DATASET v1.0 Category: System administration ; Style: calm
/*
* This program is a simple Linux system administration tool that allows users to manage network interfaces.
* It lets users view and modify interface information, including the device name, IP address, netmask, and gateway.
* The program provides an easy-to-use interface and a set of intuitive commands to make it simple for users to manage their network settings.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INTERFACES 10 // Maximum number of network interfaces supported
#define MAX_LEN 256 // Maximum length of string input

// Struct to hold network interface information
typedef struct {
    char device[MAX_LEN];
    char ip_address[MAX_LEN];
    char netmask[MAX_LEN];
    char gateway[MAX_LEN];
} Interface;

// Function to display a menu of options for the user
void display_menu() {
    printf("==== Network Interface Manager ====");
    printf("\n 1. View interfaces \n 2. Add interface \n 3. Remove interface \n 4. Modify interface \n 5. Exit \n");
    printf("\nPlease enter your choice (1-5): ");
}

// Function to add a new interface to the system
void add_interface(Interface* interfaces, int* num_interfaces) {
    // Check if the maximum number of interfaces has been reached
    if (*num_interfaces == MAX_INTERFACES) {
        printf("Maximum number of interfaces reached. Please remove an interface before adding a new one.\n");
        return;
    }

    Interface new_interface;
    // Get device name from user input
    printf("Enter device name: ");
    fgets(new_interface.device, MAX_LEN, stdin);
    new_interface.device[strcspn(new_interface.device, "\n")] = 0;

    // Get IP address from user input
    printf("Enter IP address: ");
    fgets(new_interface.ip_address, MAX_LEN, stdin);
    new_interface.ip_address[strcspn(new_interface.ip_address, "\n")] = 0;

    // Get netmask from user input
    printf("Enter netmask: ");
    fgets(new_interface.netmask, MAX_LEN, stdin);
    new_interface.netmask[strcspn(new_interface.netmask, "\n")] = 0;

    // Get gateway from user input
    printf("Enter gateway: ");
    fgets(new_interface.gateway, MAX_LEN, stdin);
    new_interface.gateway[strcspn(new_interface.gateway, "\n")] = 0;

    interfaces[*num_interfaces] = new_interface;
    (*num_interfaces)++;

    printf("Interface added successfully.\n");
}

// Function to remove an existing interface from the system
void remove_interface(Interface* interfaces, int* num_interfaces) {
    if (*num_interfaces == 0) {
        printf("No interfaces to remove.\n");
        return;
    }

    char device[MAX_LEN];
    printf("Enter device name to remove: ");
    fgets(device, MAX_LEN, stdin);
    device[strcspn(device, "\n")] = 0;

    int interface_index = -1;
    for (int i = 0; i < *num_interfaces; i++) {
        if (strcmp(interfaces[i].device, device) == 0) {
            interface_index = i;
            break;
        }
    }

    if (interface_index == -1) {
        printf("Device not found.\n");
        return;
    }

    for (int i = interface_index; i < (*num_interfaces - 1); i++) {
        interfaces[i] = interfaces[i + 1];
    }

    (*num_interfaces)--;
    printf("Interface removed successfully.\n");
}

// Function to modify an existing interface in the system
void modify_interface(Interface* interfaces, int num_interfaces) {
    if (num_interfaces == 0) {
        printf("No interfaces to modify.\n");
        return;
    }

    char device[MAX_LEN];
    printf("Enter device name to modify: ");
    fgets(device, MAX_LEN, stdin);
    device[strcspn(device, "\n")] = 0;

    int interface_index = -1;
    for (int i = 0; i < num_interfaces; i++) {
        if (strcmp(interfaces[i].device, device) == 0) {
            interface_index = i;
            break;
        }
    }

    if (interface_index == -1) {
        printf("Device not found.\n");
        return;
    }

    // Get IP address from user input
    printf("Enter new IP address: ");
    fgets(interfaces[interface_index].ip_address, MAX_LEN, stdin);
    interfaces[interface_index].ip_address[strcspn(interfaces[interface_index].ip_address, "\n")] = 0;

    // Get netmask from user input
    printf("Enter new netmask: ");
    fgets(interfaces[interface_index].netmask, MAX_LEN, stdin);
    interfaces[interface_index].netmask[strcspn(interfaces[interface_index].netmask, "\n")] = 0;

    // Get gateway from user input
    printf("Enter new gateway: ");
    fgets(interfaces[interface_index].gateway, MAX_LEN, stdin);
    interfaces[interface_index].gateway[strcspn(interfaces[interface_index].gateway, "\n")] = 0;

    printf("Interface modified successfully.\n");
}

// Function to display all interfaces in the system
void display_interfaces(Interface* interfaces, int num_interfaces) {
    if (num_interfaces == 0) {
        printf("No interfaces to display.\n");
        return;
    }

    printf("\n+--------------------+--------------+--------------+--------------+\n");
    printf("| Device             | IP Address   | Netmask      | Gateway      |\n");
    printf("+--------------------+--------------+--------------+--------------+\n");

    for (int i = 0; i < num_interfaces; i++) {
        printf("| %-18s | %-12s | %-12s | %-12s |\n", interfaces[i].device, interfaces[i].ip_address, interfaces[i].netmask, interfaces[i].gateway);
    }

    printf("+--------------------+--------------+--------------+--------------+\n");
}

int main() {
    Interface interfaces[MAX_INTERFACES];
    int num_interfaces = 0;

    int choice = 0;
    while (choice != 5) {
        display_menu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                display_interfaces(interfaces, num_interfaces);
                break;
            case 2:
                add_interface(interfaces, &num_interfaces);
                break;
            case 3:
                remove_interface(interfaces, &num_interfaces);
                break;
            case 4:
                modify_interface(interfaces, num_interfaces);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please enter a number (1-5).\n");
                break;
        }
    }

    return 0;
}