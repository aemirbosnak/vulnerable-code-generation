//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
  // A port scanner that questions its own existence

  // Introspection: Let's think about what we're doing
  printf("Greetings from the Port Scanner! Let's embark on an introspective journey.\n");

  // Introspection: My birth and purpose
  printf("I was born as a program, designed to probe and scrutinize the vast expanse of ports.\n");

  // Introspection: My mission
  printf("My mission is to uncover open doors, gateways into the hidden worlds of network services.\n");

  // Introspection: My technique
  printf("I approach each port with a polite knock, sending a request and awaiting a response.\n");

  // Introspection: My potential impact
  printf("My findings can expose vulnerabilities or provide valuable information for network management.\n");

  // Introspection: My limits and biases
  printf("However, I acknowledge my limitations. I am only as good as the information I gather.\n");

  // Introspection: My ethics and responsibilities
  printf("With power comes responsibility. I use my abilities ethically, respecting privacy and adhering to network etiquette.\n");

  // Introspection: My evolution
  printf("As the digital landscape evolves, so shall I. I am committed to continuous learning and improvement.\n");

  // Introspection: My legacy
  printf("I strive to leave a lasting impact, helping to secure and enhance the boundless world of cyberspace.\n");

  // Now, let's put our introspective thoughts into action!

  // User input: Which IP address should I scrutinize?
  char ip_address[16];
  printf("Enter the IP address you wish to explore: ");
  scanf("%s", ip_address);

  // Introspection: Parsing the IP address
  printf("Dissecting the IP address: %s\n", ip_address);

  // Step into the scanner's shoes and start the port scanning process
  int sockfd;
  int port;
  struct sockaddr_in serv_addr;

  // Create a socket: This is how I communicate with the network
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Error creating socket");
    return EXIT_FAILURE;
  }

  // Set up the server address: Where I'm headed
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(ip_address);
  serv_addr.sin_port = htons(0);

  // Introspection: Exploring port ranges
  printf("Which port range would you like me to investigate? ");
  scanf("%d %d", &port, &serv_addr.sin_port);

  // Introspection: Port scanning loop
  for (int i = port; i <= serv_addr.sin_port; i++) {
    printf("Checking port: %d\n", i);

    // Connect to the server: Knock, knock!
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0) {
      printf("Port %d is open! Potential gateway detected.\n", i);
    } else {
      printf("Port %d is closed. No response received.\n", i);
    }
  }

  // Introspection: Done scanning
  printf("Port scanning complete for IP address: %s\n", ip_address);

  // Reflection: What did I discover?
  printf("Reflecting on my findings...");

  // Clean up: Farewell, my virtual friends
  close(sockfd);

  return EXIT_SUCCESS;
}