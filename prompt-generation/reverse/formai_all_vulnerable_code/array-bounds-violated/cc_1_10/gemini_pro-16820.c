//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>

#define MAX_EVENTS 10

int main() {
  int efd, nfds, i;
  struct epoll_event ev, events[MAX_EVENTS];

  // Create an epoll file descriptor.
  efd = epoll_create(1);
  if (efd == -1) {
    perror("epoll_create");
    exit(EXIT_FAILURE);
  }

  // Add the standard input file descriptor to the epoll instance.
  ev.events = EPOLLIN;
  ev.data.fd = STDIN_FILENO;
  if (epoll_ctl(efd, EPOLL_CTL_ADD, STDIN_FILENO, &ev) == -1) {
    perror("epoll_ctl");
    exit(EXIT_FAILURE);
  }

  // Loop forever, waiting for events on the standard input file descriptor.
  for (;;) {
    nfds = epoll_wait(efd, events, MAX_EVENTS, -1);
    if (nfds == -1) {
      perror("epoll_wait");
      exit(EXIT_FAILURE);
    }

    for (i = 0; i < nfds; i++) {
      // If the event is on the standard input file descriptor, read the input and echo it back.
      if (events[i].data.fd == STDIN_FILENO) {
        char buf[1024];
        int nread;

        nread = read(STDIN_FILENO, buf, sizeof(buf));
        if (nread == -1) {
          perror("read");
          exit(EXIT_FAILURE);
        }

        write(STDOUT_FILENO, buf, nread);
      }
    }
  }

  // Close the epoll file descriptor.
  close(efd);

  return EXIT_SUCCESS;
}