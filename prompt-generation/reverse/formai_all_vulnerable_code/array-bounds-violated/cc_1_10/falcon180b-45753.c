//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<errno.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MAX 100
#define SERVER "speedtest.net"
#define PORT 8080

int sock;
struct sockaddr_in server;
char message[MAX];
long int start_time,end_time;
double elapsed_time;
int bytes_received=0;
double speed;

void error(char *msg)
{
    perror(msg);
    exit(0);
}

void send_request()
{
    strcpy(message,"GET / HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n");
    send(sock,message,strlen(message),0);
}

void recv_response()
{
    int len=0;
    while((len=recv(sock,message,MAX,0))>0)
    {
        bytes_received+=len;
    }
    message[len]='\0';
}

void calculate_speed()
{
    elapsed_time=difftime(end_time,start_time);
    speed=((double)bytes_received)/elapsed_time;
    printf("Speed: %.2lf kbps\n",speed);
}

int main()
{
    sock=socket(AF_INET,SOCK_STREAM,0);
    if(sock==-1)
    {
        error("socket failed");
    }

    server.sin_family=AF_INET;
    server.sin_port=htons(PORT);
    server.sin_addr.s_addr=inet_addr(SERVER);

    if(connect(sock,(struct sockaddr*)&server,sizeof(server))==-1)
    {
        error("connect failed");
    }

    start_time=difftime(time(0),time(0));
    send_request();
    recv_response();

    end_time=difftime(time(0),time(0));
    calculate_speed();

    close(sock);
    return 0;
}