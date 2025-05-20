//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Define the maximum number of ports to scan
#define MAX_PORTS 100

// Define the default port range to scan
#define DEFAULT_PORT_START 1
#define DEFAULT_PORT_END 1024

// Define the timeout value for scanning each port (in seconds)
#define TIMEOUT 1

// Define the banner message to display
#define BANNER "Port Scanner v1.0"

// Structure to store the scan results
typedef struct scan_result
{
    int port;
    int status;
    char *service_name;
} scan_result;

// Function to print the banner message
void print_banner()
{
    printf("%s\n", BANNER);
}

// Function to get the IP address of the target host
struct hostent *get_host_ip(char *hostname)
{
    struct hostent *host_info;

    // Get the host information
    host_info = gethostbyname(hostname);

    // Check if the host information was found
    if (host_info == NULL)
    {
        fprintf(stderr, "Error: Could not find host information for %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    return host_info;
}

// Function to create a socket and connect to the target host
int create_socket(struct hostent *host_info, int port)
{
    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        fprintf(stderr, "Error: Could not create socket\n");
        exit(EXIT_FAILURE);
    }

    // Set the socket timeout
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0)
    {
        fprintf(stderr, "Error: Could not set socket timeout\n");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        return -1;
    }

    return sockfd;
}

// Function to scan a single port
scan_result scan_port(struct hostent *host_info, int port)
{
    scan_result result;

    // Create a socket and connect to the target host
    int sockfd = create_socket(host_info, port);

    // Check if the connection was successful
    if (sockfd == -1)
    {
        result.status = -1;
        result.service_name = NULL;
        return result;
    }

    // Get the service name for the port
    struct servent *service_info;
    service_info = getservbyport(htons(port), NULL);
    result.service_name = service_info ? service_info->s_name : NULL;

    // Close the socket
    close(sockfd);

    // Set the scan result
    result.port = port;
    result.status = 0;

    return result;
}

// Function to scan a range of ports
void scan_ports(struct hostent *host_info, int port_start, int port_end)
{
    // Allocate memory for the scan results
    scan_result *results = malloc(sizeof(scan_result) * (port_end - port_start + 1));

    // Scan the ports
    for (int i = port_start; i <= port_end; i++)
    {
        results[i - port_start] = scan_port(host_info, i);
    }

    // Print the scan results
    printf("Port\tStatus\tService\n");
    for (int i = port_start; i <= port_end; i++)
    {
        printf("%d\t%d\t%s\n", i, results[i - port_start].status, results[i - port_start].service_name);
    }

    // Free the memory allocated for the scan results
    free(results);
}

// Function to get the user input
void get_user_input(char **hostname, int *port_start, int *port_end)
{
    // Get the target host name
    printf("Enter the target host name: ");
    scanf("%s", *hostname);

    // Get the port range to scan
    printf("Enter the port range to scan (start-end): ");
    scanf("%d-%d", port_start, port_end);
}

// Main function
int main()
{
    // Print the banner message
    print_banner();

    // Get the user input
    char *hostname;
    int port_start, port_end;
    get_user_input(&hostname, &port_start, &port_end);

    // Get the IP address of the target host
    struct hostent *host_info = get_host_ip(hostname);

    // Scan the ports
    scan_ports(host_info, port_start, port_end);

    return 0;
}