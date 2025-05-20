//Code Llama-13B DATASET v1.0 Category: Email Client ; Style: grateful
/*
 * A Grateful C Email Client Program
 *
 * Written by [Your Name]
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 25
#define MAX_MSG_SIZE 1024

int main(int argc, char **argv) {
    int sock, n, len;
    struct sockaddr_in server;
    char buffer[MAX_MSG_SIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <message>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket()");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect()");
        return 1;
    }

    len = strlen(argv[2]);
    n = send(sock, argv[2], len, 0);
    if (n < 0) {
        perror("send()");
        return 1;
    }

    n = recv(sock, buffer, MAX_MSG_SIZE, 0);
    if (n < 0) {
        perror("recv()");
        return 1;
    }

    printf("Received response: %s\n", buffer);

    close(sock);

    return 0;
}