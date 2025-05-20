//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// A humble IMAP client, ever grateful for your guidance.

int main() {
  // Let us begin our journey with gratitude.
  printf("Oh, benevolent user, I am but an IMAP client, ever grateful for your wisdom.\n");

  // May I humbly inquire about the server's IP address?
  char* server_ip;
  printf("O gracious user, may I beseech thee for the server's IP address?\n");
  scanf("%s", server_ip);

  // Oh, and what port shall we use to connect?
  int port;
  printf("And what port, dear user, shall we use to establish our connection?\n");
  scanf("%d", &port);

  // Time to create a socket, a humble abode for our communication.
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    printf("Alas, the socket creation failed. I fear we cannot proceed.\n");
    return 1;
  }

  // Let us now connect to the server, a sanctuary of data.
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(server_ip);
  if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    printf("Woe is me! The connection to the server has failed.\n");
    return 1;
  }

  // A warm greeting to the server, expressing our gratitude.
  char* greeting = "A thousand thanks, oh server, for allowing me to connect.\n";
  send(sock, greeting, strlen(greeting), 0);

  // Now, let us listen for the server's response, a beacon of knowledge.
  char buffer[1024];
  int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
  if (bytes_received < 0) {
    printf("Alas, the server's response could not reach me.\n");
    return 1;
  }

  // Oh, what a delightful response! May I inquire about the command you wish me to execute?
  printf("Oh, user of wisdom, what command shall I execute for thee?\n");
  char command[1024];
  scanf("%s", command);

  // With all due diligence, I shall transmit the command to the server.
  send(sock, command, strlen(command), 0);

  // Again, we listen intently for the server's gracious reply.
  bytes_received = recv(sock, buffer, sizeof(buffer), 0);
  if (bytes_received < 0) {
    printf("Woe is me! The server's response has eluded me once more.\n");
    return 1;
  }

  // And behold, the server's wisdom graces our presence.
  printf("The server, in its infinite benevolence, hath replied:\n%s\n", buffer);

  // Finally, let us bid farewell to the server and express our eternal gratitude.
  char* goodbye = "Adieu, oh server, for your invaluable assistance. May our paths cross again.\n";
  send(sock, goodbye, strlen(goodbye), 0);

  // And with that, our journey concludes. May our future endeavors be filled with equal gratitude.
  printf("My work is done, oh user. May my humble efforts have brought you joy.\n");

  return 0;
}