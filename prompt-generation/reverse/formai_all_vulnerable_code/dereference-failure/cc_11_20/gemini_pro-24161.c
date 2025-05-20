//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <err.h>

#define BUFSIZE 4096
#define REQSIZE 8192

int main(int argc, char *argv[])
{
	int s, c, r, n, p;
	char buf[BUFSIZE], req[REQSIZE], *h, *e;
	struct sockaddr_in sa, ca;
	struct hostent *hent;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s <port> <target>\n", argv[0]);
		exit(1);
	}

	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s == -1)
		err(1, "socket");

	sa.sin_family = AF_INET;
	sa.sin_port = htons(atoi(argv[1]));
	sa.sin_addr.s_addr = INADDR_ANY;

	if (bind(s, (struct sockaddr *)&sa, sizeof(sa)) == -1)
		err(1, "bind");

	if (listen(s, 5) == -1)
		err(1, "listen");

	while (1) {
		c = sizeof(ca);
		c = accept(s, (struct sockaddr *)&ca, &c);
		if (c == -1) {
			if (errno == EINTR)
				continue;
			err(1, "accept");
		}

		while ((n = read(c, buf, BUFSIZE)) > 0) {
			buf[n] = '\0';
			h = strstr(buf, "GET");
			if (h == NULL)
				break;
			e = strstr(buf, "\n\n");
			if (e == NULL)
				break;
			memcpy(req, h, e - h);
			req[e - h] = '\0';
			h = strstr(req, "HTTP/");
			memmove(h, h + 1, strlen(h + 1) + 1);
			p = ca.sin_port;
			ca.sin_port = 80;
			hent = gethostbyname(argv[2]);
			ca.sin_addr = *(struct in_addr *)hent->h_addr_list[0];
			if (connect(c, (struct sockaddr *)&ca, sizeof(ca)) == -1)
				err(1, "connect");
			ca.sin_port = p;
			write(c, req, strlen(req));
			while ((n = read(c, buf, BUFSIZE)) > 0)
				write(c, buf, n);
			close(c);
		}
		close(c);
	}

	close(s);
	exit(0);
}