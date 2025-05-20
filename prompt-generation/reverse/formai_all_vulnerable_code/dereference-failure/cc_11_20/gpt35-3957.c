//FormAI DATASET v1.0 Category: Port Scanner ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>
#include<string.h>
#include<errno.h>

int main(int argc, char *argv[]) {

    char *dest_ip;
    int start_port=0, end_port=1023;

    if(argc < 2) { 
        printf("Usage: %s <destination IP address> [start port] [end port]\n", argv[0]);
        exit(1);
    }
    else if(argc < 3) { 
        dest_ip = argv[1];
    }
    else if(argc < 4) { 
        dest_ip = argv[1];
        start_port = atoi(argv[2]);
    }
    else { 
        dest_ip = argv[1];
        start_port = atoi(argv[2]);
        end_port = atoi(argv[3]);
    }

    if(end_port < start_port) { 
        printf("End port cannot be less than start port.\n");
        exit(1);
    }

    int sock;
    struct sockaddr_in addr;
    struct hostent *host;

    if(inet_addr(dest_ip) == -1) { 
        host = gethostbyname(dest_ip);
        if(host == NULL) { 
            printf("Error resolving hostname: %s\n", dest_ip);
            exit(1);
        }
        dest_ip = inet_ntoa(*((struct in_addr *)host->h_addr_list[0]));
    }

    printf("\nScanning %s ...\n", dest_ip);

    for(int port=start_port; port<=end_port; port++) { 
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock < 0) { 
            perror("Socket creation error");
            exit(1);
        }

        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr(dest_ip);

        int conn_res = connect(sock, (struct sockaddr *)&addr, sizeof(addr));

        if(conn_res == 0) { 
            printf("%-10s %5d        open\n", "TCP", port);
        }
        else { 
            // error codes taken from errno.h
            switch(errno) { 
                case ECONNREFUSED: 
                    break;
                case ETIMEDOUT: 
                    printf("%-10s %5d        filtered\n", "TCP", port);
                    break;
                default: 
                    printf("Error: %s (%d)\n", strerror(errno), errno);
            }
        }
        close(sock);
    }

    return 0;
}