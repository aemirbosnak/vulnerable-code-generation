//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>

// Define QoS measurement constants
#define SAMPLE_PERIOD_USEC 100000	// Sample period in microseconds
#define SMOOTHING_FACTOR 0.1	// Factor for exponential moving average smoothing

// Define socket parameters
#define BUFFER_SIZE 256
#define PORT_NUMBER 8080

int main()
{
	// Define variables
	struct sockaddr_in server_address;
	int socket_fd, connection_fd;
	char buffer[BUFFER_SIZE];
	int buffer_size = sizeof(buffer);
	double current_bandwidth = 0;
	time_t last_sample_time = 0;
	struct timeval start_time, end_time;

	// Initialize server address
	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	server_address.sin_port = htons(PORT_NUMBER);

	// Create socket
	if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("Error creating socket");
		exit(EXIT_FAILURE);
	}

	// Bind socket
	if (bind(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0)
	{
		perror("Error binding socket");
		exit(EXIT_FAILURE);
	}

	// Listen for incoming connections
	if (listen(socket_fd, 5) < 0)
	{
		perror("Error listening for connections");
		exit(EXIT_FAILURE);
	}

	printf("QoS monitor is running...\n");

	while (1)
	{
		// Accept incoming connection
		if ((connection_fd = accept(socket_fd, NULL, NULL)) < 0)
		{
			perror("Error accepting connection");
			exit(EXIT_FAILURE);
		}

		// Start timer
		gettimeofday(&start_time, NULL);

		// Receive data from client and calculate bandwidth
		int num_bytes = 0;
		while ((num_bytes = recv(connection_fd, buffer, buffer_size, 0)) > 0)
		{
			// Calculate elapsed time
			gettimeofday(&end_time, NULL);
			double elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);

			// Calculate current bandwidth
			double current_bytes_per_sec = (double)num_bytes / elapsed_time * 1000000;
			current_bandwidth = (1 - SMOOTHING_FACTOR) * current_bandwidth + SMOOTHING_FACTOR * current_bytes_per_sec;
			printf("Current bandwidth: %f bytes/sec\n", current_bandwidth);

			// Update last sample time
			time(&last_sample_time);

			// Reset timer and buffer
			gettimeofday(&start_time, NULL);
			memset(buffer, 0, buffer_size);
		}

		// Close connection
		close(connection_fd);
	}

	// Close socket
	close(socket_fd);

	return 0;
}