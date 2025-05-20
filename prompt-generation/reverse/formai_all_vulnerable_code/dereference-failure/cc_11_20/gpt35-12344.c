//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>

#define MAX_DEVICE_NUMBER 100 //Maximum number of devices that can be connected to the network
#define MAX_BUFFER_SIZE 1024 //Maximum size of buffer for receiving data

struct WirelessDevice { //Struct that contains information about a wireless device
    char ip[16]; //IP address of the device
    char mac[18]; //MAC address of the device
};

int main() {
    struct WirelessDevice connected_devices[MAX_DEVICE_NUMBER]; //Array to store information about the connected devices
    int num_devices = 0; //Variable to store number of devices connected to the network
    int sockfd, portno = 80, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0); //Creating a socket

    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    server = gethostbyname("192.168.0.1"); //IP address of the router
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr)); //Clearing the serv_addr structure

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) { //Connecting to the router
        perror("Error connecting");
        return 1;
    }

    sprintf(buffer, "GET /cgi-bin/luci HTTP/1.1\nHost: 192.168.0.1\n\n"); //Sending a GET request

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        return 1;
    }

    memset(buffer, 0, sizeof(buffer)); //Clearing the buffer

    n = read(sockfd, buffer, sizeof(buffer)-1); //Reading the response

    if (n > 0) {
        char *device = strtok(buffer, "\n"); //Parsing the response to find connected devices

        while (device != NULL) {
            if (strstr(device, "wireless") != NULL) { //Checking if the device is a wireless device
                char *ip_start = strstr(device, "inet addr:"); //Finding the IP address of the device
                if (ip_start != NULL) {
                    char *ip_end = strchr(ip_start+11, ' '); //Finding the end of the IP address
                    if (ip_end != NULL) {
                        *ip_end = '\0';
                        strcpy(connected_devices[num_devices].ip, ip_start+11);
                    }
                }

                char *mac_start = strstr(device, "HWaddr "); //Finding the MAC address of the device
                if (mac_start != NULL) {
                    char *mac_end = strchr(mac_start+7, ' '); //Finding the end of the MAC address
                    if (mac_end != NULL) {
                        *mac_end = '\0';
                        strcpy(connected_devices[num_devices].mac, mac_start+7);
                    }
                }

                num_devices++; //Incrementing the number of connected devices
            }

            device = strtok(NULL, "\n");
        }
    }

    close(sockfd); //Closing the socket

    //Printing information about the connected devices
    printf("%-16s %s\n", "IP ADDRESS", "MAC ADDRESS");
    for (int i = 0; i < num_devices; i++) {
        printf("%-16s %s\n", connected_devices[i].ip, connected_devices[i].mac);
    }

    return 0;
}