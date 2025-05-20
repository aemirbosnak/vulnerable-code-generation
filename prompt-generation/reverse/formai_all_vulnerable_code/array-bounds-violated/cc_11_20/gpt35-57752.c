//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_DEVICES 50

// structure defining a device
struct device {
    char name[20]; // Device Name
    int id; // Device ID
    char ip[16]; // Device IP Address
    char type[20]; // Device Type (e.g., router, switch, firewall, PC)
};

// structure defining a link between devices
struct link {
    int device1_id; // ID of Device 1
    int device2_id; // ID of Device 2
    char link_type[20]; // Type of Link (e.g., ethernet, fiber)
};

int main(){
    struct device devices[MAX_DEVICES];
    struct link links[MAX_DEVICES];
    
    int num_devices = 0, num_links = 0;
    char input[100], last_input[100];

    // Clear the previous input for safety
    memset(last_input, 0, sizeof(last_input));
    
    while(1) {
        printf("Enter 'device' to add a device, 'link' to add a link, or 'done' to finish: ");
        fgets(input, sizeof(input), stdin);
        
        // Remove new line character if present
        if(input[strlen(input)-1] == '\n')
            input[strlen(input)-1] = '\0';
        
        if(strcmp(input, "done") == 0) {
            // End of Adding Devices and Links
            printf("Number of Devices: %d\n", num_devices);
            printf("Number of Links: %d\n", num_links);
            break;
        }
        else if(strcmp(input, "device") == 0) {
            // New Device Input
            printf("Enter the Device Name: ");
            fgets(devices[num_devices].name, sizeof(devices[num_devices].name), stdin);
            
            // Remove new line character for safety
            if(devices[num_devices].name[strlen(devices[num_devices].name)-1] == '\n')
                devices[num_devices].name[strlen(devices[num_devices].name)-1] = '\0';
            
            printf("Enter the Device Type: ");
            fgets(devices[num_devices].type, sizeof(devices[num_devices].type), stdin);
            
            // Remove new line character for safety
            if(devices[num_devices].type[strlen(devices[num_devices].type)-1] == '\n')
                devices[num_devices].type[strlen(devices[num_devices].type)-1] = '\0';
            
            printf("Enter the Device IP Address: ");
            fgets(devices[num_devices].ip, sizeof(devices[num_devices].ip), stdin);
            
            // Remove new line character for safety
            if(devices[num_devices].ip[strlen(devices[num_devices].ip)-1] == '\n')
                devices[num_devices].ip[strlen(devices[num_devices].ip)-1] = '\0';
            
            devices[num_devices].id = num_devices+1; // Assign Device ID
            num_devices++;
        }
        else if(strcmp(input, "link") == 0) {
            // New Link Input
            printf("Enter the ID of the first Device: ");
            fgets(input, sizeof(input), stdin);
            int device1_id = atoi(input);
            
            printf("Enter the ID of the second Device: ");
            fgets(input, sizeof(input), stdin);
            int device2_id = atoi(input);
            
            printf("Enter the Type of Link: ");
            fgets(links[num_links].link_type, sizeof(links[num_links].link_type), stdin);
            
            // Remove new line character for safety
            if(links[num_links].link_type[strlen(links[num_links].link_type)-1] == '\n')
                links[num_links].link_type[strlen(links[num_links].link_type)-1] = '\0';
            
            links[num_links].device1_id = device1_id; // Assign Device 1 ID
            links[num_links].device2_id = device2_id; // Assign Device 2 ID
            num_links++;
        }
        else {
            printf("Invalid Input. Try again.\n");
        }
        
        // Copy the input for reusability
        strcpy(last_input, input);
    }
    
    // Displaying the Created Network Topology
    printf("\n-- Network Topology --\n");
    printf("Devices:\n");
    printf("ID   Name                   Type      IP Address\n");
    printf("-------------------------------------------------\n");
    for(int i=0; i<num_devices; i++) {
        printf("%-4d %-20s %-10s %-15s\n", devices[i].id, devices[i].name, devices[i].type, devices[i].ip);
    }
    printf("\nLinks:\n");
    printf("Device 1 ID  Device 2 ID  Link Type\n");
    printf("---------------------------------\n");
    for(int i=0; i<num_links; i++) {
        printf("%-12d %-12d %-10s\n", links[i].device1_id, links[i].device2_id, links[i].link_type);
    }
    
    return 0;
}