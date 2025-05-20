//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct subnet {
	unsigned int address;
	unsigned int netmask;
	unsigned int broadcast;
	unsigned int hostmin;
	unsigned int hostmax;
	unsigned int numhosts;
};

void calculate_subnet(struct subnet *subnet, unsigned int address, unsigned int netmask) {
	subnet->address = address & netmask;
	subnet->netmask = netmask;
	subnet->broadcast = subnet->address | (~netmask);
	subnet->hostmin = subnet->address + 1;
	subnet->hostmax = subnet->broadcast - 1;
	subnet->numhosts = pow(2, 32 - __builtin_clz(netmask)) - 2;
}

void print_subnet(struct subnet *subnet) {
	printf("Address: %u.%u.%u.%u\n",
		(subnet->address >> 24) & 0xff,
		(subnet->address >> 16) & 0xff,
		(subnet->address >> 8) & 0xff,
		subnet->address & 0xff);
	printf("Netmask: %u.%u.%u.%u\n",
		(subnet->netmask >> 24) & 0xff,
		(subnet->netmask >> 16) & 0xff,
		(subnet->netmask >> 8) & 0xff,
		subnet->netmask & 0xff);
	printf("Broadcast: %u.%u.%u.%u\n",
		(subnet->broadcast >> 24) & 0xff,
		(subnet->broadcast >> 16) & 0xff,
		(subnet->broadcast >> 8) & 0xff,
		subnet->broadcast & 0xff);
	printf("Host Minimum: %u.%u.%u.%u\n",
		(subnet->hostmin >> 24) & 0xff,
		(subnet->hostmin >> 16) & 0xff,
		(subnet->hostmin >> 8) & 0xff,
		subnet->hostmin & 0xff);
	printf("Host Maximum: %u.%u.%u.%u\n",
		(subnet->hostmax >> 24) & 0xff,
		(subnet->hostmax >> 16) & 0xff,
		(subnet->hostmax >> 8) & 0xff,
		subnet->hostmax & 0xff);
	printf("Number of Hosts: %u\n", subnet->numhosts);
}

int main() {
	struct subnet subnet;
	unsigned int address, netmask;

	printf("Enter IP address (e.g. 192.168.1.1): ");
	scanf("%u.%u.%u.%u", &address, &address, &address, &address);
	printf("Enter netmask (e.g. 255.255.255.0): ");
	scanf("%u.%u.%u.%u", &netmask, &netmask, &netmask, &netmask);

	calculate_subnet(&subnet, address, netmask);
	print_subnet(&subnet);

	return 0;
}