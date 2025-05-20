//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFERSIZE 1024

int main(int argc, char **argv)
{
	int epoll_fd, fd, client_fd;
	struct epoll_event event;
	struct sockaddr_in addr, client_addr;
	socklen_t addr_len;
	char buffer[BUFFERSIZE];

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <port>\n", argv[0]);
		return EXIT_FAILURE;
	}

	/* Create epoll file descriptor */
	epoll_fd = epoll_create1(0);
	if (epoll_fd == -1) {
		perror("epoll_create1");
		return EXIT_FAILURE;
	}

	/* Create server socket */
	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd == -1) {
		perror("socket");
		return EXIT_FAILURE;
	}

	/* Set server socket to non-blocking */
	if (fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) | O_NONBLOCK) == -1) {
		perror("fcntl");
		return EXIT_FAILURE;
	}

	/* Bind server socket to address */
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[1]));
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
		perror("bind");
		return EXIT_FAILURE;
	}

	/* Listen on server socket */
	if (listen(fd, 5) == -1) {
		perror("listen");
		return EXIT_FAILURE;
	}

	/* Add server socket to epoll */
	event.events = EPOLLIN | EPOLLPRI;
	event.data.fd = fd;
	if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &event) == -1) {
		perror("epoll_ctl");
		return EXIT_FAILURE;
	}

	while (1) {
		/* Wait for events to occur */
		int nfds = epoll_wait(epoll_fd, &event, 1, -1);
		if (nfds == -1) {
			perror("epoll_wait");
			return EXIT_FAILURE;
		}

		/* Handle events */
		for (int i = 0; i < nfds; i++) {
			if (event.events & EPOLLIN || event.events & EPOLLPRI) {
				/* Check if it is a new client connection */
				if (event.data.fd == fd) {
					addr_len = sizeof(client_addr);
					client_fd = accept(fd, (struct sockaddr *)&client_addr, &addr_len);
					if (client_fd == -1) {
						perror("accept");
						continue;
					}

					/* Add client socket to epoll */
					event.events = EPOLLIN | EPOLLPRI;
					event.data.fd = client_fd;
					if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &event) == -1) {
						perror("epoll_ctl");
						return EXIT_FAILURE;
					}
				} else {
					/* Read data from client */
					memset(buffer, 0, BUFFERSIZE);
					int bytes_read = read(event.data.fd, buffer, BUFFERSIZE);
					if (bytes_read == -1) {
						perror("read");
						continue;
					}

					if (bytes_read == 0) {
						/* Client has closed connection */
						if (epoll_ctl(epoll_fd, EPOLL_CTL_DEL, event.data.fd, NULL) == -1) {
							perror("epoll_ctl");
							return EXIT_FAILURE;
						}
						close(event.data.fd);
						continue;
					}

					/* Process data and send it back to client */
					int n = write(event.data.fd, buffer, bytes_read);
					if (n != bytes_read) {
						perror("write");
						continue;
					}
				}
			}
		}
	}

	return EXIT_SUCCESS;
}