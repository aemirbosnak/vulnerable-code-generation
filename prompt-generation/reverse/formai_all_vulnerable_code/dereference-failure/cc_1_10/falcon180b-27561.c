//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
  char *name;
  int value;
} Enum;

enum {
  IPV4_CLASS_A = 0,
  IPV4_CLASS_B = 1,
  IPV4_CLASS_C = 2
};

char *ipv4_class_str[] = {
  "Class A",
  "Class B",
  "Class C"
};

int ipv4_class(int num_bits) {
  if (num_bits <= 8) {
    return IPV4_CLASS_A;
  } else if (num_bits <= 16) {
    return IPV4_CLASS_B;
  } else if (num_bits <= 24) {
    return IPV4_CLASS_C;
  } else {
    return -1;
  }
}

int main(int argc, char *argv[]) {
  if (argc!= 2) {
    fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
    return 1;
  }

  char *ip_str = argv[1];
  int num_dots = 0;
  char *dot_pos = strchr(ip_str, '.');
  while (dot_pos!= NULL) {
    num_dots++;
    dot_pos = strchr(dot_pos + 1, '.');
  }

  if (num_dots!= 3) {
    fprintf(stderr, "Invalid IP address: %s\n", ip_str);
    return 1;
  }

  char *ip_parts[4];
  ip_parts[0] = strtok(ip_str, ".");
  ip_parts[1] = strtok(NULL, ".");
  ip_parts[2] = strtok(NULL, ".");
  ip_parts[3] = strtok(NULL, ".");

  int num_bits = atoi(ip_parts[0]) * 8;
  num_bits += atoi(ip_parts[1]) * 8;
  num_bits += atoi(ip_parts[2]) * 8;
  num_bits += atoi(ip_parts[3]) * 8;

  int ipv4_class_enum = ipv4_class(num_bits);
  Enum *ipv4_class_enum_ptr = &ipv4_class_enum;

  printf("IP address: %s\n", ip_str);
  printf("IPv4 class: %s\n", ipv4_class_str[ipv4_class_enum]);

  return 0;
}