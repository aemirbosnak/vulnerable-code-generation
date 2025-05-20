//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: ephemeral
//
// Ephemeral Email Client in C
//
// Vincent Rouvreau - July 2019 - Public Domain
//

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define die(msg) do { \
    fprintf (stderr, "%s:%d: %s\n", __FILE__, __LINE__, msg); \
    exit (EXIT_FAILURE); \
} while (0)

int main ()
{
    struct addrinfo hints, *res, *service;

    // Resolve the server address
    memset (&hints, 0, sizeof (hints));
    hints.ai_family = AF_INET;    // IPv4
    hints.ai_socktype = SOCK_STREAM;  // TCP
    if (getaddrinfo ("smtp.example.com", "25", &hints, &res) != 0)
        die ("getaddrinfo error");

    // Connect to the server
    int sock_fd;
    for (service = res; service != NULL; service = service->ai_next)
    {
        sock_fd = socket (service->ai_family, service->ai_socktype, service->ai_protocol);
        if (sock_fd == -1)
            die ("socket error");

        if (connect (sock_fd, service->ai_addr, service->ai_addrlen) == 0)
            break;

        close (sock_fd);
    }
    if (service == NULL)
        die ("no socket available");

    freeaddrinfo (res);

    // Send HELO command
    char buffer[4096]; // Buffer size
    sprintf (buffer, "HELO example.com\r\n");

    if (send (sock_fd, buffer, strlen (buffer), 0) == -1)
        die ("send error");

    // Receive banner
    memset (buffer, 0, sizeof (buffer));
    if (recv (sock_fd, buffer, sizeof (buffer) - 1, 0) == -1)
        die ("recv error");

    printf ("banner: %s", buffer);

    // Send MAIL FROM command
    sprintf (buffer, "MAIL FROM: <sender@example.com>\r\n");

    if (send (sock_fd, buffer, strlen (buffer), 0) == -1)
        die ("send error");

    // Receive MAIL FROM response
    memset (buffer, 0, sizeof (buffer));
    if (recv (sock_fd, buffer, sizeof (buffer) - 1, 0) == -1)
        die ("recv error");

    printf ("MAIL FROM response: %s", buffer);

    // Send RCPT TO command
    sprintf (buffer, "RCPT TO: <recipient@example.com>\r\n");

    if (send (sock_fd, buffer, strlen (buffer), 0) == -1)
        die ("send error");

    // Receive RCPT TO response
    memset (buffer, 0, sizeof (buffer));
    if (recv (sock_fd, buffer, sizeof (buffer) - 1, 0) == -1)
        die ("recv error");

    printf ("RCPT TO response: %s", buffer);

    // Send DATA command
    sprintf (buffer, "DATA\r\n");

    if (send (sock_fd, buffer, strlen (buffer), 0) == -1)
        die ("send error");

    // Receive DATA response
    memset (buffer, 0, sizeof (buffer));
    if (recv (sock_fd, buffer, sizeof (buffer) - 1, 0) == -1)
        die ("recv error");

    printf ("DATA response: %s", buffer);

    // Send email content
    sprintf (buffer, "Subject: Ephemeral Email\r\n"
        "From: sender@example.com\r\n"
        "To: recipient@example.com\r\n"
        "\r\n"
        "This is an ephemeral email.\r\n"
        "\r\n"
        "--\r\n"
        "Vincent Rouvreau\r\n");

    if (send (sock_fd, buffer, strlen (buffer), 0) == -1)
        die ("send error");

    // Send QUIT command
    sprintf (buffer, "QUIT\r\n");

    if (send (sock_fd, buffer, strlen (buffer), 0) == -1)
        die ("send error");

    // Receive QUIT response
    memset (buffer, 0, sizeof (buffer));
    if (recv (sock_fd, buffer, sizeof (buffer) - 1, 0) == -1)
        die ("recv error");

    printf ("QUIT response: %s", buffer);

    close (sock_fd);

    return EXIT_SUCCESS;
}