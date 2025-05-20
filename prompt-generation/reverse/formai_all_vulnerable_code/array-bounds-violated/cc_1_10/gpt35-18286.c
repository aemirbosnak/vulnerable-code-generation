//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: synchronous
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <netdb.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
  
#define MAX 1024 
#define PORT 80
  
void getHostName(char ip[], char hostname[]) 
{ 
    struct hostent *host; 
    struct in_addr haddr; 
    inet_aton(ip, &haddr); 
    host = gethostbyaddr(&haddr, sizeof(haddr), AF_INET); 
    strcpy(hostname, host->h_name); 
} 
  
void getIP(char hostname[], char ip[]) 
{ 
    struct hostent *host; 
    struct in_addr** addr_list; 
    int i; 
    host = gethostbyname(hostname); 
    addr_list = (struct in_addr**)host->h_addr_list; 
    for (i = 0; addr_list[i] != NULL; i++) { 
        strcpy(ip, inet_ntoa(*addr_list[i])); 
        return; 
    } 
} 
  
int main() 
{ 
    char input[MAX], domain[MAX], ip[MAX]; 
    printf("Enter IP address or Domain name: "); 
    fgets(input, MAX, stdin); 
    input[strlen(input) - 1] = '\0'; 
  
    strcpy(domain, input); 
    strcpy(ip, input); 
  
    if (inet_addr(ip) == -1) 
        getIP(domain, ip); 
    else
        getHostName(ip, domain); 
  
    printf("Domain Name: %s \n", domain); 
    printf("IP Address : %s \n", ip); 
    return 0; 
}