//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_DEVICES 10

struct device{
    char name[50];
    char ip[20];
    bool connected;
};

void printDevices(struct device *devices, int num_devices){
    printf("List of Connected Devices:\n");
    for(int i=0; i<num_devices; i++){
        printf("Device Name: %s\n", devices[i].name);
        printf("Device IP: %s\n", devices[i].ip);
        printf("Status: %s\n", devices[i].connected ? "Connected" : "Disconnected");
        printf("\n");
    }
}

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s <target_ip>\n", argv[0]);
        return 1;
    }

    char target_ip[20];
    strcpy(target_ip, argv[1]);

    int sockfd, n;
    char buffer[BUFFER_SIZE] = {0};
    struct sockaddr_in servaddr, cliaddr; 

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
     
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(12345);
    servaddr.sin_addr.s_addr = INADDR_ANY;
     
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ){
        perror("bind");
        return 1;
    }

    struct device devices[MAX_DEVICES];
    int num_devices = 0;

    sprintf(buffer, "GetDeviceInfo %s", target_ip);
    sendto(sockfd, buffer, strlen(buffer), 0, (const struct sockaddr *) &servaddr,
    		sizeof(servaddr));
    socklen_t len = sizeof(cliaddr);
    recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, 0, (struct sockaddr *) &cliaddr,
    		&len);
    buffer[strlen(buffer)] = '\0';

    if(strcmp(buffer, "No Device Found") == 0){
        printf("No devices found.\n");
        return 0;
    }

    struct in_addr addr;
    inet_aton(target_ip, &addr);
    strcpy(devices[num_devices].name, buffer);
    strcpy(devices[num_devices].ip, target_ip);
    devices[num_devices].connected = true;
    num_devices++;

    while(1){
        printf("Enter command: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        if(strcmp(buffer, "quit") == 0){
            break;
        }

        if(strcmp(buffer, "devices") == 0){
            printDevices(devices, num_devices);
        }

        if(strcmp(buffer, "ping") == 0){
            printf("Enter device IP to ping: ");
            fgets(buffer, BUFFER_SIZE, stdin);
    	    buffer[strcspn(buffer, "\n")] = 0;

            int res = system(buffer);
            if(res == 0){
                printf("Device is online.\n");
            }else{
                printf("Device is offline.\n");
            }
        }

        if(strcmp(buffer, "connect") == 0){
            printf("Enter device IP to connect: ");
            fgets(buffer, BUFFER_SIZE, stdin);
    	    buffer[strcspn(buffer, "\n")] = 0;

            bool device_found = false;
            for(int i=0; i<num_devices; i++){
                if(strcmp(devices[i].ip, buffer) == 0){
                    devices[i].connected = true;
                    device_found = true;
                    printf("Device connected.\n");
                    break;
                }
            }

            if(!device_found){
                struct in_addr addr;
                inet_aton(buffer, &addr);
                sprintf(buffer, "GetDeviceInfo %s", buffer);
                sendto(sockfd, buffer, strlen(buffer), 0, (const struct sockaddr *) &servaddr,
    	            sizeof(servaddr));
                socklen_t len = sizeof(cliaddr);
                recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, 0, (struct sockaddr *) &cliaddr,
    	            &len);
                buffer[strlen(buffer)] = '\0';

                if(strcmp(buffer, "No Device Found") == 0){
                    printf("No devices found.\n");
                }else{
                    strcpy(devices[num_devices].name, buffer);
                    strcpy(devices[num_devices].ip, buffer);
                    devices[num_devices].connected = true;
                    num_devices++;
                    printf("Device connected.\n");
                }
            }
        }

        if(strcmp(buffer, "disconnect") == 0){
            printf("Enter device IP to disconnect: ");
            fgets(buffer, BUFFER_SIZE, stdin);
    	    buffer[strcspn(buffer, "\n")] = 0;

            bool device_found = false;
            for(int i=0; i<num_devices; i++){
                if(strcmp(devices[i].ip, buffer) == 0){
                    devices[i].connected = false;
                    device_found = true;
                    printf("Device disconnected.\n");
                    break;
                }
            }

            if(!device_found){
                printf("Device not found.\n");
            }
        }
    }

    close(sockfd);

    return 0;
}