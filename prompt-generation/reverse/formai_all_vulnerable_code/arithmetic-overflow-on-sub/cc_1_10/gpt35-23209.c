//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define DEFAULT_INTERVAL 10 // Time in seconds
#define SERVER_HOST "www.google.com" // Change this to your desired website
#define MAX_TIME 2000 // Maximum response time in ms

/* Function to convert milliseconds to seconds */
double millisec_to_sec(clock_t t){
    return (double)(t) / CLOCKS_PER_SEC;
}

/* Function to print current time in special format */
void print_time(){
    time_t t = time(NULL);
    printf("(%s) ", ctime(&t));
}

int main(int argc, char** argv){
    int interval = DEFAULT_INTERVAL;
    if(argc == 2){
        interval = atoi(argv[1]);
    }

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family = AF_INET;

    if(getaddrinfo(SERVER_HOST, NULL, &hints, &res) != 0){
        perror("Error in getaddrinfo");
        exit(EXIT_FAILURE);
    }

    int sockfd;
    if((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1){
        perror("Error in socket");
        exit(EXIT_FAILURE);
    }

    /* Connect to the server */
    if(connect(sockfd, res->ai_addr, res->ai_addrlen) == -1){
        perror("Error in connect");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res); // Free memory

    /* Main loop */
    while(1){
        clock_t start = clock(); // Start timer

        /* Send a GET request to the server */
        char buffer[BUFSIZ] = {0};
        sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER_HOST);
        int bytes_sent = send(sockfd, buffer, strlen(buffer), 0);

        if(bytes_sent == -1){
            print_time();
            printf("Error in send: unable to send GET request.\n");
            exit(EXIT_FAILURE);
        }

        /* Receive response from the server */
        int total_bytes_received = 0;
        while(1){
            int bytes_received = recv(sockfd, buffer, BUFSIZ, 0);
            if(bytes_received == -1){
                print_time();
                printf("Error in recv: unable to receive response from server.\n");
                exit(EXIT_FAILURE);
            }

            if(bytes_received == 0){
                break; // End of response
            }

            total_bytes_received += bytes_received;
        }

        clock_t end = clock(); // End timer

        int response_time = (int)(millisec_to_sec(end - start) * 1000); // Calculate response time in ms

        if(response_time > MAX_TIME){
            print_time();
            printf("Server is down! Response time: %d ms\n", response_time);
        }
        else{
            print_time();
            printf("Server is up. Response time: %d ms\n", response_time);
        }

        sleep(interval);
    }

    close(sockfd); // Close socket

    return 0;
}