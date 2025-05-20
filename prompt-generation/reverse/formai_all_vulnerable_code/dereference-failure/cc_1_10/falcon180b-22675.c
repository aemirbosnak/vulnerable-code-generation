//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define MAX_HOST_NAME 256
#define MAX_DATA_SIZE 1024

// Function to print the error message
void print_error(char *error_message) {
    perror(error_message);
    exit(1);
}

// Function to resolve the host name and IP address
int resolve_host(char *host_name, struct sockaddr_in *host_addr) {
    struct hostent *host_entry;
    host_entry = gethostbyname(host_name);
    if (host_entry == NULL) {
        printf("Error: Unable to resolve host name %s\n", host_name);
        return FALSE;
    }
    memcpy(&host_addr->sin_addr, host_entry->h_addr, host_entry->h_length);
    return TRUE;
}

// Function to send and receive data using TCP/IP socket
int send_and_receive_data(int sockfd, char *send_data, char *recv_data) {
    int retval;
    if ((retval = send(sockfd, send_data, strlen(send_data), 0)) < 0) {
        print_error("Error in sending data");
        return FALSE;
    }
    memset(recv_data, 0, MAX_DATA_SIZE);
    if ((retval = recv(sockfd, recv_data, MAX_DATA_SIZE, 0)) < 0) {
        print_error("Error in receiving data");
        return FALSE;
    }
    return TRUE;
}

// Function to perform ping test
int ping_test(char *host_name) {
    int sockfd;
    struct sockaddr_in host_addr;
    char send_data[MAX_DATA_SIZE];
    char recv_data[MAX_DATA_SIZE];
    if (!resolve_host(host_name, &host_addr)) {
        return FALSE;
    }
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        print_error("Error in creating socket");
        return FALSE;
    }
    if (!send_and_receive_data(sockfd, "PING", recv_data)) {
        close(sockfd);
        return FALSE;
    }
    if (strcmp(recv_data, "PONG") == 0) {
        printf("Ping successful to host %s\n", host_name);
    } else {
        printf("Ping failed to host %s\n", host_name);
    }
    close(sockfd);
    return TRUE;
}

// Main function to test the ping function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage:./ping_test <host_name>\n");
        return FALSE;
    }
    if (!ping_test(argv[1])) {
        return FALSE;
    }
    return TRUE;
}