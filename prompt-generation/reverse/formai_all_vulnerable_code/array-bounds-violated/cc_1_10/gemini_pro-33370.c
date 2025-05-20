//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <math.h>

#define BUFFERSIZE 1024

char *ip_address;
int port_number;
int socket_descriptor;
struct sockaddr_in server_address;
char buffer[BUFFERSIZE];

void send_command(char *command) {
  int length = strlen(command);
  if (send(socket_descriptor, command, length, 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }
}

void receive_response() {
  int length = recv(socket_descriptor, buffer, BUFFERSIZE, 0);
  if (length < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  buffer[length] = '\0';
  printf("%s\n", buffer);
}

void turn_on_light(int light_number) {
  snprintf(buffer, BUFFERSIZE, "TURN_ON_LIGHT %d", light_number);
  send_command(buffer);
  receive_response();
}

void turn_off_light(int light_number) {
  snprintf(buffer, BUFFERSIZE, "TURN_OFF_LIGHT %d", light_number);
  send_command(buffer);
  receive_response();
}

void set_light_brightness(int light_number, int brightness) {
  snprintf(buffer, BUFFERSIZE, "SET_LIGHT_BRIGHTNESS %d %d", light_number, brightness);
  send_command(buffer);
  receive_response();
}

void set_light_color(int light_number, int red, int green, int blue) {
  snprintf(buffer, BUFFERSIZE, "SET_LIGHT_COLOR %d %d %d %d", light_number, red, green, blue);
  send_command(buffer);
  receive_response();
}

void toggle_light(int light_number) {
  snprintf(buffer, BUFFERSIZE, "TOGGLE_LIGHT %d", light_number);
  send_command(buffer);
  receive_response();
}

void get_light_status(int light_number) {
  snprintf(buffer, BUFFERSIZE, "GET_LIGHT_STATUS %d", light_number);
  send_command(buffer);
  receive_response();
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <IP address> <port number>\n", argv[0]);
    return EXIT_FAILURE;
  }

  ip_address = argv[1];
  port_number = atoi(argv[2]);

  socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_descriptor < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = inet_addr(ip_address);
  server_address.sin_port = htons(port_number);

  if (connect(socket_descriptor, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // You can add your own smart home automation commands here...

  turn_on_light(1);
  set_light_brightness(1, 50);
  set_light_color(1, 255, 0, 0);
  toggle_light(1);
  get_light_status(1);

  close(socket_descriptor);
  return EXIT_SUCCESS;
}