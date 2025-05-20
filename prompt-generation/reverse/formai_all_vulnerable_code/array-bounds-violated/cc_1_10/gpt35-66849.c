//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ctype.h>

#define MAXSIZE 1024

int get_port(char *url)
{
    char *ptr = strstr(url, ":");
    if(ptr == NULL)
        return 80;
    else
        return atoi(ptr+1);
}

void get_host(char *url, char *host)
{
    char temp[MAXSIZE];
    memset(temp,0,sizeof(temp));
    int len = strlen(url);
    int i,j=0;
    for(i=0;i<len;i++)
    {
        if(url[i] != ':') //Remove port number from URL
            temp[j++] = url[i];
        else
            break;
    }
    temp[j] = '\0';
    strcpy(host,temp);
}

void get_file(char *url, char *file)
{
    memset(file,0,sizeof(file));
    int len = strlen(url);
    int i,k=0;
    for(i=0;i<len;i++)
    {
        if(url[i] == '/')
            break;
    }
    if(i == len)
        strcpy(file,"/");
    else
    {
        for(;i<len;i++)
            file[k++] = url[i];
        file[k] = '\0';
    }
}

void build_http_request(char *request,char *host,char *file)
{
    sprintf(request,"GET %s HTTP/1.1\r\nHost:%s\r\nUser-Agent: Mozilla/5.0 \r\n\r\n",file,host);
}

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char *url = "http://www.example.com/testfile.txt";
    char host[MAXSIZE],file[MAXSIZE],request[MAXSIZE],response[MAXSIZE];

    get_host(url,host);
    int port = get_port(url);
    get_file(url,file);

    if((sock=socket(AF_INET, SOCK_STREAM, 0))==-1)
    {
        printf("\nSocket creation error");
        return 1;
    }

    server.sin_addr.s_addr = inet_addr(host);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if(connect(sock,(struct sockaddr *)&server,sizeof(server)) == -1)
    {
        printf("\nConnection error");
        return 1;
    }

    build_http_request(request,host,file);

    if(send(sock,request,strlen(request),0) == strlen(request))
    {
        printf("HTTP request sent\n");
    }
    else
    {
        printf("Send failed\n");
        return 1;
    }

    int n;
    memset(response,0,sizeof(response));
    while((n=recv(sock,response,MAXSIZE-1,0)) > 0)
    {
        response[n] = '\0';
        printf("%s",response);
    }
    close(sock);
    return 0;
}