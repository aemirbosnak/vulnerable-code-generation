//FormAI DATASET v1.0 Category: Port Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// We start by defining the function that scans a specific port and returns whether it is open or not.
bool scan_port(int port, char* ip_address) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    inet_aton(ip_address, &server_address.sin_addr);

    // connect() returns -1 if the port is not open, otherwise it returns 0.
    if(connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        return false;
    }
    else {
        return true;
    }
}

int main() {
    printf("Welcome to the Surrealist Port Scanner!\n");
    printf("We will scan the ports of an IP Address and determine whether they are open or not.\n");
    printf("Please provide the IP address: ");

    char ip_address[15];
    scanf("%s", ip_address);
    printf("\n");
    
    printf("////////////////////////\n");
    printf("// LET'S BEGIN SCANNING //\n");
    printf("////////////////////////\n");
    printf("\n");

    int port_num;
    bool open;

    // We will now loop over a range of ports (0-65535) to scan them using our scan_port function.
    for(port_num=0; port_num<=65535; port_num++) {
        open = scan_port(port_num, ip_address);
        if(open) {
            printf("Port %d is open. Welcome to the Twilight Zone!\n", port_num);
        }
    }

    printf("\n");
    printf("//////////////////////\n");
    printf("// SCANNING COMPLETE //\n");
    printf("//////////////////////\n");

    return 0;
}