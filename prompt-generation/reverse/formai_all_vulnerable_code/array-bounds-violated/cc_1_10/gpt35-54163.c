//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT 8080
#define MAX_THREADS 100

typedef struct {
    char *hostname;
    char *ip;
    int node_id;
} NodeInfo;

NodeInfo node_list[128];
int node_count = 0;

// function to perform DNS lookup and retrieve IP address
char* dns_lookup(char *hostname) {
    struct hostent *host;
    char *ip = (char*)malloc(NI_MAXHOST*sizeof(char));
    if ((host = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname() error");
        exit(EXIT_FAILURE);
    }
    if (inet_ntop(AF_INET, (void *)host->h_addr_list[0], ip, NI_MAXHOST) == NULL) {
        perror("inet_ntop() error");
        exit(EXIT_FAILURE);
    }
    return ip;
}

// function to perform network mapping on one node
void* map_one_node(void *id) {
    int node_id = *(int*)id;
    NodeInfo current_node = node_list[node_id];
    char command[100], result[1024];
    FILE* fp;
    sprintf(command, "sudo nmap -sn %s", current_node.ip);
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(EXIT_FAILURE);
    }
    while (fgets(result, sizeof(result), fp) != NULL) {
        if (strstr(result, "Nmap scan report for") != NULL) {
            int i = 0;
            while (result[i] != '(') {
                i++;
            }
            int j = i+1;
            while (result[j] != ')') {
                j++;
            }
            char *hostname = (char*)malloc((j-i)*sizeof(char));
            strncpy(hostname, &result[i+1], j-i-1);
            hostname[j-i-1] = '\0';
            char *ip = (char*)malloc(16*sizeof(char));
            strncpy(ip, &result[strlen(result)-15], 15);
            if (strcmp(ip, current_node.ip) == 0) {
                // skip if the IP address is the same as the current node
                continue;
            }
            int k;
            int found_existing_node = 0;
            for (k = 0; k < node_count; k++) {
                if (strcmp(node_list[k].ip, ip) == 0) {
                    found_existing_node = 1;
                    break;
                }
            }
            if (!found_existing_node) {
                node_list[node_count].hostname = hostname;
                node_list[node_count].ip = ip;
                printf("Node %d - found new node: %s (%s)\n", current_node.node_id, hostname, ip);
                node_count++;
            }
        }
    }
    pclose(fp);
}

// function to perform network mapping on all nodes
void map_network() {
    int i;
    for (i = 0; i < node_count; i++) {
        pthread_t thread;
        pthread_create(&thread, NULL, map_one_node, &(node_list[i].node_id));
        pthread_join(thread, NULL);
    }
}

int main() {
    // read in input file containing list of hostnames
    FILE *fp;
    char line[256];
    fp = fopen("hostnames.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    while (fgets(line, sizeof(line), fp) != NULL) {
        int len = strlen(line);
        if (line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        char *ip = dns_lookup(line);
        node_list[node_count].hostname = strdup(line);
        node_list[node_count].ip = ip;
        node_list[node_count].node_id = node_count;
        printf("Node %d - added node: %s (%s)\n", node_count, line, ip);
        node_count++;
    }
    fclose(fp);

    // map the network
    map_network();

    // print the final list of nodes
    printf("Final list of nodes:\n");
    int j;
    for (j = 0; j < node_count; j++) {
        printf("Node %d - %s (%s)\n", node_list[j].node_id, node_list[j].hostname, node_list[j].ip);
    }
    return 0;
}