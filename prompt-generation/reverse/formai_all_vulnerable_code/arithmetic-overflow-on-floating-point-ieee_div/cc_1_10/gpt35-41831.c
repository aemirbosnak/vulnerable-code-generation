//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: standalone
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <string.h> 
#include <sys/time.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include <netinet/in.h>  

// Function to calculate internet speed
void calculateSpeed(int fileSize, double timeElapsed) 
{  
    double speed = (double) fileSize / timeElapsed; 
  
    if (speed < 1024)  
        printf("Speed: %f bps\n", speed);  
    else if ((speed > 1024) && (speed < (1024*1024)))  
        printf("Speed: %f Kbps\n", (speed / 1024));  
    else if ((speed > (1024*1024)) && (speed < (1024*1024*1024)))  
        printf("Speed: %f Mbps\n", (speed / (1024*1024)));  
    else  
        printf("Speed: %f Gbps\n", (speed / (1024*1024*1024)));  
}  
  
// Function to send data and calculate internet speed
void sendData(int socket, int fileSize) 
{ 
    char *buffer = (char *) malloc(fileSize); 
  
    struct timeval start, end; 
    double timeElapsed; 
  
    int bytesSent = 0; 
    int totalBytesSent = 0; 
  

    gettimeofday(&start, NULL); 
  
    while (totalBytesSent < fileSize) { 

        bytesSent = send(socket, buffer + totalBytesSent, fileSize - totalBytesSent, 0); 

        if (bytesSent == -1) { 
            perror("ERROR: Data Sending Failed...!!!"); 
            break; 
        } 

        totalBytesSent += bytesSent; 
    } 
  
    gettimeofday(&end, NULL); 
  
    timeElapsed = (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec) / 1000000.0); 
    printf("Time taken to send the data = %lf seconds\n", timeElapsed); 
  
    calculateSpeed(fileSize, timeElapsed); 
  
    free(buffer); 
}  
  
// Main function
int main(int argc, char **argv) 
{ 
    if (argc != 3) { 
        printf("Please enter the correct format: %s <IP ADDRESS> <PORT>\n", argv[0]); 
        return 0; 
    } 
  
    struct sockaddr_in server; 
    int fileSize = 1048576; 
    int socketDescriptor = 0; 
    
    memset(&server, '0', sizeof(server)); 
    char* serverIP = argv[1]; 
    int portNumber = atoi(argv[2]); 
  
    if ((socketDescriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
        printf("ERROR: Could not create socket...!!!\n"); 
        return 0; 
    } 
  
    server.sin_family = AF_INET; 
    server.sin_port = htons(portNumber); 
  
    if (inet_pton(AF_INET, serverIP, &server.sin_addr) <= 0) { 
        printf("ERROR: inet_pton error occured...!!!\n"); 
        return 0; 
    } 
  
    if (connect(socketDescriptor, (struct sockaddr *)&server, sizeof(server)) < 0) { 
        printf("ERROR: Connect Failed...!!!\n"); 
        return 0; 
    } 
  
    sendData(socketDescriptor, fileSize); 
  
    close(socketDescriptor); 
  
    return 0; 
}