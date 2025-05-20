//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: recursive
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>

void build_request(char *request, char *hostname) {
   strcat(request, "GET / HTTP/1.1\r\n");
   strcat(request, "Host: ");
   strcat(request, hostname);
   strcat(request, "\r\n");
   strcat(request, "Connection: close\r\n\r\n");
}

void recursive_http_call(char *hostname, int port, char *path) {
   struct hostent *server;
   struct sockaddr_in server_addr;
   char request[2048], response[2048];
   int sock, bytes_recv;

   // Create socket
   sock = socket(AF_INET, SOCK_STREAM, 0);
   if (sock < 0) {
      perror("Error creating socket");
      return;
   }

   // Get server address
   server = gethostbyname(hostname);
   if (server == NULL) {
      perror("Error getting server address");
      return;
   }

   // Build the HTTP request
   memset(request, 0, sizeof(request));
   build_request(request, hostname);

   // Setup server address
   memset(&server_addr, 0, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_port = htons(port);
   memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

   // Connect to server
   if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
      perror("Error connecting to server");
      return;
   }

   // Send the HTTP request
   if (send(sock, request, strlen(request), 0) < 0) {
      perror("Error sending request");
      return;
   }

   // Receive response
   memset(response, 0, sizeof(response));
   bytes_recv = recv(sock, response, sizeof(response), 0);
   if (bytes_recv < 0 ) {
      perror("Error receiving response");
      return;
   }

   // Print response
   printf("%s", response);

   // Close socket
   close(sock);

   // Recurse on redirects
   char *redirect_str = "Location: ";
   char *redirect_url = strstr(response, redirect_str);
   if (redirect_url != NULL) {
      redirect_url += strlen(redirect_str);

      char redirect_host[256], redirect_path[1024];
      int redirect_port = 80;

      // Extract hostname, port, and path
      if (sscanf(redirect_url, "http://%[^:/]:%d/%s", redirect_host, &redirect_port, redirect_path) < 3) {
         sscanf(redirect_url, "http://%[^/]/%s", redirect_host, redirect_path);
      }

      printf("\nRedirecting to: %s:%d/%s\n\n", redirect_host, redirect_port, redirect_path);
      recursive_http_call(redirect_host, redirect_port, redirect_path);
   }
}

int main() {
   char hostname[256], path[1024];

   printf("Enter hostname: ");
   scanf("%s", hostname);

   printf("Enter path: ");
   scanf("%s", path);

   recursive_http_call(hostname, 80, path);

   return 0;
}