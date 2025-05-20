//FormAI DATASET v1.0 Category: Firewall ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IP_LEN 16
#define MAX_PORTS 1024

bool is_valid_ip(char *ip); // Function to check if IP Address is valid

int main() {
  char ip[MAX_IP_LEN];
  int num_ports;
  int ports[MAX_PORTS];

  // Step 1: Get User Input - IP Address and Number of Ports
  printf("Enter IP Address: ");
  scanf("%s", ip);

  if(!is_valid_ip(ip)) { // Invalid IP
    printf("ERROR: Invalid IP Address\n");
    return 1;
  }

  printf("Enter Number of Ports: ");
  scanf("%d", &num_ports);

  if(num_ports <= 0 || num_ports > MAX_PORTS) { // Invalid Port Range
    printf("ERROR: Invalid Number of Ports\n");
    return 1;
  }

  // Step 2: Get User Input - Port Numbers
  printf("Enter Port Numbers: ");
  for(int i = 0; i < num_ports; i++) {
    scanf("%d", &ports[i]);

    if(ports[i] < 0 || ports[i] > 65535) { // Invalid Port Number
      printf("ERROR: Invalid Port Number\n");
      return 1;
    }
  }

  // Step 3: Check if Incoming Traffic is Allowed
  bool traffic_allowed = false;

  for(int i = 0; i < num_ports; i++) {
    if(ports[i] == 80 || ports[i] == 443 || ports[i] == 22) { // Allowed Ports
      traffic_allowed = true;
      break;
    }
  }

  if(!traffic_allowed) { // Blocked Traffic
    printf("Incoming Traffic from IP Address %s Blocked\n", ip);
  } else { // Allowed Traffic
    printf("Incoming Traffic from IP Address %s Allowed\n", ip);
  }

  return 0;
}

// Function to check if IP Address is valid
bool is_valid_ip(char *ip) {
  int num_dots = 0;
  int num_digits = 0;

  for(int i = 0; i < strlen(ip); i++) {
    if(ip[i] == '.') { // Count Number of Dots
      num_dots++;
      if(num_digits == 0) { // No Digits Found Before Dot
        return false;
      }
      num_digits = 0;
    } else if(ip[i] >= '0' && ip[i] <= '9') { // Count Number of Digits
      num_digits++;
      if(num_digits > 3 || (ip[i-1] == '.' && ip[i] == '0')) { // Invalid Number of Digits or Leading Zeros
        return false;
      }
    } else { // Invalid Character
      return false;
    }
  }

  return num_dots == 3 && num_digits > 0;
}