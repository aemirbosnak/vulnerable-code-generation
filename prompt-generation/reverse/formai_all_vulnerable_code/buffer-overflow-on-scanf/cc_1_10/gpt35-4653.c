//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MIN_SUBNET_MASK 24 

char *ip_address; 
int subnet_mask, n_subnets, n_hosts, network_id;
char **subnets_array;

int is_valid_ip(char *ip) {
    int i, len;
    char *p, temp[16];
    len = strlen(ip);
    if (len < 7 || len > 15) return 0;
    p = strtok(ip, ".");
    if (p == NULL) return 0;
    while (p) {
        strcpy(temp, p);
        for (i = 0; i < strlen(temp); i++) {
            if (temp[i] < '0' || temp[i] > '9') return 0;
        }
        if (atoi(temp) < 0 || atoi(temp) > 255) return 0;
        p = strtok(NULL, ".");
    }
    return 1;
}

void get_ip_address() {
    char temp[16];
    printf("Enter IP address: ");
    scanf("%s", temp);
    while (!is_valid_ip(temp)) {
        printf("Invalid IP address, enter again: ");
        scanf("%s", temp);
    }
    ip_address = strdup(temp);
}

void get_subnet_mask() {
    printf("Enter number of subnets: ");
    scanf("%d", &n_subnets);
    while((pow(2, ceil(log2(n_subnets))))<n_subnets)
    {
        printf("Invalid subnet count, enter again: ");
        scanf("%d",&n_subnets);
    }
    subnet_mask = MIN_SUBNET_MASK + (int)log2(n_subnets);
    printf("Subnet mask: /%d\n", subnet_mask);
}

void get_number_of_hosts() {
    printf("Enter number of hosts per subnet: ");
    scanf("%d", &n_hosts);
}

void calculate_network_id() {
    int i, octet, mask;
    char cip_address[16];
    strcpy(cip_address, ip_address);
    memset(cip_address, '\0', sizeof(cip_address));
    mask = 32 - subnet_mask; 
    for (i = 0; i < strlen(ip_address); i++) {
        if (ip_address[i] == '.') {
            cip_address[i] = '.';
            continue;
        }
        octet = ip_address[i] - '0';
        cip_address[i] = ((octet & (1<<mask)) ? '1' : '0');
        mask--;
    }
    network_id = strtol(cip_address, NULL, 2);
    printf("Network ID (binary): %s\n", cip_address);
}

void calculate_subnet_ids() {
    int i, n_subnets_local, subnet_base, subnet_offset;
    subnets_array = (char **)malloc(sizeof(char *) * n_subnets);
    n_subnets_local = pow(2, subnet_mask - MIN_SUBNET_MASK);
    subnet_base = network_id;
    subnet_offset = pow(2, 32 - subnet_mask); 
    for (i = 0; i < n_subnets_local; i++) {
        subnets_array[i] = (char *)malloc(sizeof(char) * 16);
        snprintf(subnets_array[i], 16, "%d.%d.%d.%d",
            (subnet_base >> 24) & 0xFF, (subnet_base >> 16) & 0xFF,
            (subnet_base >> 8) & 0xFF, subnet_base & 0xFF);
        subnet_base += subnet_offset;
    }
}

void print_subnet_ids() {
    int i;
    printf("%d subnets:\n", n_subnets);
    for (i = 0; i < n_subnets; i++) {
        printf("Subnet %d: %s\n", i+1, subnets_array[i]);
    }
}

void free_memory() {
    int i;
    for (i = 0; i < n_subnets; i++) {
        free(subnets_array[i]);
    }
    free(subnets_array);
}

int main() {
    get_ip_address();
    get_subnet_mask();
    get_number_of_hosts();
    calculate_network_id();
    calculate_subnet_ids();
    print_subnet_ids();
    free_memory();
    return 0;
}