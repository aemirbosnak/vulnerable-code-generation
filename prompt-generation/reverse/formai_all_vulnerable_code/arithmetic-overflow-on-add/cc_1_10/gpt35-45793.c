//FormAI DATASET v1.0 Category: Firewall ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <time.h>

#define MAX_RULES 100
#define MAX_IP_LENGTH 16
#define MAX_PROTOCOL_LENGTH 4
#define MAX_PORT_LENGTH 6
#define MAX_LINE_LENGTH 1024

struct rule {
    char source_ip[MAX_IP_LENGTH];
    char destination_ip[MAX_IP_LENGTH];
    char protocol[MAX_PROTOCOL_LENGTH];
    char source_port[MAX_PORT_LENGTH];
    char destination_port[MAX_PORT_LENGTH];
};

struct firewall {
    int num_rules;
    struct rule rules[MAX_RULES];
};

void load_rules(struct firewall *fw, char *filename);
int is_allowed(struct firewall *fw, char *source_ip, char *destination_ip, char *protocol, char *source_port, char *destination_port);

int main(int argc, char **argv) {
    struct firewall fw;
    char *filename = "firewall_rules.txt";
    int i;

    load_rules(&fw, filename);

    for (i = 1; i < argc; i += 5) {
        if (is_allowed(&fw, argv[i], argv[i+1], argv[i+2], argv[i+3], argv[i+4])) {
            printf("Packet %d is allowed.\n", i/5 + 1);
        } else {
            printf("Packet %d is blocked.\n", i/5 + 1);
        }
    }

    return 0;
}

void load_rules(struct firewall *fw, char *filename) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: cannot open file %s.\n", filename);
        exit(1);
    }

    fw->num_rules = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        sscanf(line, "%s %s %s %s %s", fw->rules[fw->num_rules].source_ip,
               fw->rules[fw->num_rules].destination_ip, fw->rules[fw->num_rules].protocol,
               fw->rules[fw->num_rules].source_port, fw->rules[fw->num_rules].destination_port);
        fw->num_rules++;
    }

    fclose(fp);
}

int is_allowed(struct firewall *fw, char *source_ip, char *destination_ip, char *protocol, char *source_port, char *destination_port) {
    int i;
    char *wildcard = "*";

    for (i = 0; i < fw->num_rules; i++) {
        if ((strcmp(fw->rules[i].source_ip, wildcard) == 0 || strcmp(fw->rules[i].source_ip, source_ip) == 0) &&
            (strcmp(fw->rules[i].destination_ip, wildcard) == 0 || strcmp(fw->rules[i].destination_ip, destination_ip) == 0) &&
            (strcmp(fw->rules[i].protocol, wildcard) == 0 || strcmp(fw->rules[i].protocol, protocol) == 0) &&
            (strcmp(fw->rules[i].source_port, wildcard) == 0 || strcmp(fw->rules[i].source_port, source_port) == 0) &&
            (strcmp(fw->rules[i].destination_port, wildcard) == 0 || strcmp(fw->rules[i].destination_port, destination_port) == 0)) {
            return 1;
        }
    }

    return 0;
}