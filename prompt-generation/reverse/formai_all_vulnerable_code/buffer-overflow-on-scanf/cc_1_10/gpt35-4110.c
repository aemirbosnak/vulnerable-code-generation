//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_DEVICES 10

struct Device{ //structure to hold device information
    char name[20];
    char ip_address[16];
    char status[10];
};

struct Network{ //structure to hold network information
    struct Device devices[MAX_DEVICES];
    int num_devices;
    char name[20];
};

struct Network networks[10]; //array to hold network information
int num_networks = 0;

void add_device(int network_index){ //function to add device to a network
    char name[20];
    char ip_address[16];
    printf("\nEnter device name: ");
    scanf("%s", name);
    printf("Enter device IP address: ");
    scanf("%s", ip_address);
    struct Device device;
    strcpy(device.name, name);
    strcpy(device.ip_address, ip_address);
    strcpy(device.status, "UP");
    networks[network_index].devices[networks[network_index].num_devices] = device;
    networks[network_index].num_devices++;
    printf("\nDevice added successfully!\n\n");
}

void remove_device(int network_index){ //function to remove device from a network
    char name[20];
    printf("\nEnter device name: ");
    scanf("%s", name);
    int i;
    for(i=0;i<networks[network_index].num_devices;i++){
        if(strcmp(networks[network_index].devices[i].name,name)==0){
            int j;
            for(j=i;j<networks[network_index].num_devices-1;j++){
                networks[network_index].devices[j] = networks[network_index].devices[j+1];
            }
            networks[network_index].num_devices--;
            printf("\nDevice removed successfully!\n\n");
            return;
        }
    }
    printf("\nDevice not found!\n\n");
}

void display_devices(int network_index){ //function to display devices in a network
    printf("\n%-20s %-16s %-10s\n", "Name", "IP Address", "Status");
    int i;
    for(i=0;i<networks[network_index].num_devices;i++){
        printf("%-20s %-16s %-10s\n", networks[network_index].devices[i].name, networks[network_index].devices[i].ip_address, networks[network_index].devices[i].status);
    }
    printf("\n");
}

void add_network(){ //function to add a new network
    char name[20];
    printf("\nEnter network name: ");
    scanf("%s", name);
    struct Network network;
    strcpy(network.name, name);
    networks[num_networks] = network;
    num_networks++;
    printf("\nNetwork added successfully!\n\n");
}

void remove_network(){ //function to remove a network
    char name[20];
    printf("\nEnter network name: ");
    scanf("%s", name);
    int i;
    for(i=0;i<num_networks;i++){
        if(strcmp(networks[i].name,name)==0){
            int j;
            for(j=i;j<num_networks-1;j++){
                networks[j] = networks[j+1];
            }
            num_networks--;
            printf("\nNetwork removed successfully!\n\n");
            return;
        }
    }
    printf("\nNetwork not found!\n\n");
}

void display_networks(){ //function to display all networks
    printf("\n%-20s %-10s\n", "Name", "Devices");
    int i,j;
    for(i=0;i<num_networks;i++){
        printf("%-20s %d\n", networks[i].name, networks[i].num_devices);
        printf("%-20s %-16s %-10s\n", "Name", "IP Address", "Status");
        for(j=0;j<networks[i].num_devices;j++){
            printf("%-20s %-16s %-10s\n", networks[i].devices[j].name, networks[i].devices[j].ip_address, networks[i].devices[j].status);
        }
        printf("\n");
    }
}

int main(){
    int choice;
    do{
        printf("------------------------------\n");
        printf("1. Add network\n");
        printf("2. Remove network\n");
        printf("3. Add device\n");
        printf("4. Remove device\n");
        printf("5. Display devices\n");
        printf("6. Display all networks\n");
        printf("7. Exit\n");
        printf("------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_network();
                    break;
            case 2: remove_network();
                    break;
            case 3: {
                        char network_name[20];
                        printf("\nEnter network name: ");
                        scanf("%s", network_name);
                        int i;
                        for(i=0;i<num_networks;i++){
                            if(strcmp(networks[i].name,network_name)==0){
                                add_device(i);
                                break;
                            }
                        }
                        if(i==num_networks){
                            printf("\nNetwork not found!\n\n");
                        }
                        break;
                    }
            case 4: {
                        char network_name[20];
                        printf("\nEnter network name: ");
                        scanf("%s", network_name);
                        int i;
                        for(i=0;i<num_networks;i++){
                            if(strcmp(networks[i].name,network_name)==0){
                                remove_device(i);
                                break;
                            }
                        }
                        if(i==num_networks){
                            printf("\nNetwork not found!\n\n");
                        }
                        break;
                    }
            case 5: {
                        char network_name[20];
                        printf("\nEnter network name: ");
                        scanf("%s", network_name);
                        int i;
                        for(i=0;i<num_networks;i++){
                            if(strcmp(networks[i].name,network_name)==0){
                                display_devices(i);
                                break;
                            }
                        }
                        if(i==num_networks){
                            printf("\nNetwork not found!\n\n");
                        }
                        break;
                    }
            case 6: display_networks();
                    break;
            case 7: break;
            default: printf("\nInvalid choice, please try again!\n\n");
        }
    }while(choice!=7);
    return 0;
}