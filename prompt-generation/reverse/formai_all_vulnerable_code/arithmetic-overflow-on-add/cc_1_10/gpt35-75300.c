//FormAI DATASET v1.0 Category: Firewall ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// function to check if a given IP address is valid
bool isValidIpAddress(char* ipAddress) {
  int octet, num, len = strlen(ipAddress), dots = 0;
  char* ptr = ipAddress;

  if (ipAddress == NULL) {
    return false;
  }

  // check the string length and the number of dots
  if (len < 7 || len > 15) {
    return false;
  }
  for (int i = 0; i < len; i++) {
    if (ipAddress[i] == '.') {
      dots++;
    }
  }
  if (dots != 3) {
    return false;
  }

  // check the validity of each octet
  while (*ptr) {
    if (*ptr == '.') {
      if (octet < 0 || octet > 255) {
        return false;
      }
      octet = 0;
    }
    else if (*ptr >= '0' && *ptr <= '9') {
      num = *ptr - '0';
      octet = octet * 10 + num;
    }
    else {
      return false;
    }
    ptr++;
  }

  if (octet < 0 || octet > 255) {
    return false;
  }

  return true;
}

// function to check if a given port number is valid
bool isValidPortNumber(int port) {
  return (port > 0 && port <= 65535);
}

// function to check if a given protocol is valid
bool isValidProtocol(char* protocol) {
  char* protocols[] = {"TCP", "UDP"};
  int numOfProtocols = sizeof(protocols) / sizeof(protocols[0]);

  for (int i = 0; i < numOfProtocols; i++) {
    if (strcasecmp(protocol, protocols[i]) == 0) {
      return true;
    }
  }
  return false;
}

// function to check if a given IP address is blocked
bool isIpAddressBlocked(char* ipAddress, char* blockedIpAddresses[], int numOfBlockedIpAddresses) {
  for (int i = 0; i < numOfBlockedIpAddresses; i++) {
    if (strcmp(ipAddress, blockedIpAddresses[i]) == 0) {
      return true;
    }
  }
  return false;
}

// function to check if a given port number is blocked
bool isPortBlocked(int port, int blockedPorts[], int numOfBlockedPorts) {
  for (int i = 0; i < numOfBlockedPorts; i++) {
    if (port == blockedPorts[i]) {
      return true;
    }
  }
  return false;
}

// function to block a given IP address
void blockIpAddress(char* ipAddress, char* blockedIpAddresses[], int* numOfBlockedIpAddresses) {
  blockedIpAddresses[*numOfBlockedIpAddresses] = ipAddress;
  (*numOfBlockedIpAddresses)++;
}

// function to block a given port number
void blockPort(int port, int blockedPorts[], int* numOfBlockedPorts) {
  blockedPorts[*numOfBlockedPorts] = port;
  (*numOfBlockedPorts)++;
}

// function to unblock a given IP address
void unblockIpAddress(char* ipAddress, char* blockedIpAddresses[], int* numOfBlockedIpAddresses) {
  int index = -1;

  // find the index of the IP address in the blocked IP addresses array
  for (int i = 0; i < *numOfBlockedIpAddresses; i++) {
    if (strcmp(ipAddress, blockedIpAddresses[i]) == 0) {
      index = i;
      break;
    }
  }

  // shift the elements after the index to the left to remove the IP address
  for (int i = index; i < *numOfBlockedIpAddresses - 1; i++) {
    blockedIpAddresses[i] = blockedIpAddresses[i + 1];
  }

  (*numOfBlockedIpAddresses)--;
}

// function to unblock a given port number
void unblockPort(int port, int blockedPorts[], int* numOfBlockedPorts) {
  int index = -1;

  // find the index of the port number in the blocked ports array
  for (int i = 0; i < *numOfBlockedPorts; i++) {
    if (port == blockedPorts[i]) {
      index = i;
      break;
    }
  }

  // shift the elements after the index to the left to remove the port number
  for (int i = index; i < *numOfBlockedPorts - 1; i++) {
    blockedPorts[i] = blockedPorts[i + 1];
  }

  (*numOfBlockedPorts)--;
}

int main() {
  char* blockedIpAddresses[5];
  int blockedPorts[5];
  int numOfBlockedIpAddresses = 0, numOfBlockedPorts = 0;

  // block some IP addresses and ports
  blockIpAddress("192.168.0.1", blockedIpAddresses, &numOfBlockedIpAddresses);
  blockIpAddress("192.168.0.2", blockedIpAddresses, &numOfBlockedIpAddresses);
  blockPort(80, blockedPorts, &numOfBlockedPorts);
  blockPort(443, blockedPorts, &numOfBlockedPorts);

  // test some IP addresses, ports, and protocols
  char ipAddress[] = "192.168.0.1";
  int port = 80;
  char protocol[] = "TCP";

  if (isValidIpAddress(ipAddress) && !isIpAddressBlocked(ipAddress, blockedIpAddresses, numOfBlockedIpAddresses)) {
    printf("IP address %s is valid and not blocked.\n", ipAddress);
  }
  else {
    printf("IP address %s is invalid or blocked.\n", ipAddress);
  }

  if (isValidPortNumber(port) && !isPortBlocked(port, blockedPorts, numOfBlockedPorts)) {
    printf("Port number %d is valid and not blocked.\n", port);
  }
  else {
    printf("Port number %d is invalid or blocked.\n", port);
  }

  if (isValidProtocol(protocol)) {
    printf("Protocol %s is valid.\n", protocol);
  }
  else {
    printf("Protocol %s is invalid.\n", protocol);
  }

  // unblock some IP addresses and ports
  unblockIpAddress("192.168.0.1", blockedIpAddresses, &numOfBlockedIpAddresses);
  unblockPort(80, blockedPorts, &numOfBlockedPorts);

  return 0;
}