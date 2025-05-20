//FormAI DATASET v1.0 Category: Network Ping Test ; Style: beginner-friendly
#include <stdio.h>    
#include <stdlib.h>  
#include <string.h>  
#include <sys/time.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <netdb.h>  
   
int main(int argc, char *argv[])  
{  
    struct sockaddr_in svr_addr;  
    struct hostent *host;  
    int sockfd, ret, sstart, sstop, dur;  
    char buffer[32];  
    struct timeval start, stop;  
    float ms;  
   
    if (argc <= 1) {  
        fprintf(stderr, "usage: %s <hostname>\n", argv[0]);  
        return -1;  
    }  
   
    sockfd = socket(AF_INET, SOCK_STREAM, 0);  
    
    if (sockfd < 0) {  
        fprintf(stderr, "Error opening socket\n");  
        return -1;  
    }  
     
    host = gethostbyname(argv[1]);  
    
    memset(&svr_addr, 0, sizeof(svr_addr));  
    
    svr_addr.sin_family = AF_INET;  
    
    bcopy((char *)host->h_addr_list[0],  
         (char *)&svr_addr.sin_addr.s_addr, host->h_length);  
    
    svr_addr.sin_port = htons(80);  
  
    sstart = gettimeofday(&start, NULL);  
    
    ret = connect(sockfd,(struct sockaddr *)&svr_addr,sizeof(svr_addr));  
    
    if (ret < 0) {  
        printf("Host %s is down\n", argv[1]);  
        return -1;  
    }  
   
    sstop = gettimeofday(&stop, NULL);  
    
    dur = (stop.tv_sec*1000000 + stop.tv_usec) - (start.tv_sec*1000000 + start.tv_usec);  
    
    ms = ((float)dur)/1000;  
    
    sprintf(buffer, "%.2f", ms);  
    
    printf("Host %s is UP, Response time %s ms\n", argv[1], buffer);  
   
    close(sockfd);  
    
    return 0;  
}