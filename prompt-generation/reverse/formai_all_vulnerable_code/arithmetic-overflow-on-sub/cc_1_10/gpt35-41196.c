//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/time.h>

#define PORT 80
#define BUFFER_SIZE 1024


void check_speed(){
    struct sockaddr_in server_address;
    struct timeval start, end;
    char request[BUFFER_SIZE], response[BUFFER_SIZE];
    int client_socket, read_size, test_count=0, download_size=0;
    float speed, total_time;
    
    client_socket = socket(AF_INET , SOCK_STREAM , 0);
    if (client_socket == -1)
    {
        printf("Could not create socket\n");
        return;
    }
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("8.8.8.8"); //Google DNS server IP
    server_address.sin_port = htons( PORT );
    
    if (connect(client_socket , (struct sockaddr *)&server_address , sizeof(server_address)) < 0)
    {
        printf("Error connecting to server\n");
        return;
    }
    
    sprintf(request, "GET /speedtest/random4000x4000.jpg HTTP/1.1\nHost: mirror.internode.on.net\nUser-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:63.0) Gecko/20100101 Firefox/63.0\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\nAccept-Language: en-US,en;q=0.5\nAccept-Encoding: gzip, deflate, br\nConnection: keep-alive\nUpgrade-Insecure-Requests: 1");
    
    gettimeofday(&start, NULL);
    if (send(client_socket , request , strlen(request) , 0) < 0)
    {
        printf("Failed to send HTTP request\n");
        return;
    }
    
    while( (read_size = recv(client_socket , response , BUFFER_SIZE , 0)) > 0 )
    {
        download_size += read_size;
        test_count++;
        memset(response, 0, BUFFER_SIZE);
    }
    
    gettimeofday(&end, NULL);
    total_time = ((end.tv_sec - start.tv_sec)*1000.0f) + ((end.tv_usec - start.tv_usec)/1000.0f);
    
    speed = (download_size/total_time) * 8.0f / 1000000.0f;

    printf("Download speed: %.2f Mbps\n", speed);
    printf("Download size: %d bytes\n", download_size);

    close(client_socket);
}

int main(){
    printf("Checking internet speed, please wait...\n");

    check_speed();
    
    return 0;
}