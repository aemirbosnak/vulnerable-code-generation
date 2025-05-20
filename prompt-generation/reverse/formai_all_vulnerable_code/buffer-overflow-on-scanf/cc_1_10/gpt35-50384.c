//FormAI DATASET v1.0 Category: System administration ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void addUser(char* username, char* password) {
    char cmd[100];
    sprintf(cmd, "useradd -m %s -p %s", username, password);
    system(cmd);
    printf("User %s added successfully.\n", username);
}

void deleteUser(char* username) {
    char cmd[50];
    sprintf(cmd, "userdel -r %s", username);
    system(cmd);
    printf("User %s deleted successfully.\n", username);
}

void createPartition(char* device, int size) {
    char cmd[100];
    sprintf(cmd, "parted %s mkpart primary 0 %d", device, size);
    system(cmd);
    printf("Partition created on %s successfully.\n", device);
}

void deletePartition(char* device, int num) {
    char cmd[50];
    sprintf(cmd, "parted %s rm %d", device, num);
    system(cmd);
    printf("Partition %d on %s deleted successfully.\n", num, device);
}

void configureNetwork(char* ip, char* gateway, char* dns) {
    char cmd[100];
    sprintf(cmd, "ifconfig eth0 %s netmask 255.255.255.0", ip);
    system(cmd);
    sprintf(cmd, "route add default gw %s", gateway);
    system(cmd);
    FILE* fp = fopen("/etc/resolv.conf", "w");
    fprintf(fp, "nameserver %s", dns);
    fclose(fp);
    printf("Network configured successfully.\n");
}

int main() {
    int choice;
    char username[20], password[20], device[10], ip[20], gateway[20], dns[20];
    int size, num;
    while(1) {
        printf("Enter your choice:\n");
        printf("1. Add user\n2. Delete user\n3. Create partition\n4. Delete partition\n5. Configure network\n6. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                addUser(username, password);
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                deleteUser(username);
                break;
            case 3:
                printf("Enter device (e.g. /dev/sda): ");
                scanf("%s", device);
                printf("Enter partition size (in MB): ");
                scanf("%d", &size);
                createPartition(device, size);
                break;
            case 4:
                printf("Enter device (e.g. /dev/sda): ");
                scanf("%s", device);
                printf("Enter partition number: ");
                scanf("%d", &num);
                deletePartition(device, num);
                break;
            case 5:
                printf("Enter IP address: ");
                scanf("%s", ip);
                printf("Enter gateway: ");
                scanf("%s", gateway);
                printf("Enter DNS server: ");
                scanf("%s", dns);
                configureNetwork(ip, gateway, dns);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid input. Please try again.\n");
        }
    }
    return 0;
}