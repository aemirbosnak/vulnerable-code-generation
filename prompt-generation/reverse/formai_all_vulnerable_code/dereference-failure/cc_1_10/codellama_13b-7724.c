//Code Llama-13B DATASET v1.0 Category: Firewall ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_HOSTS 100

struct rule {
    char *protocol;
    char *action;
    char *src_ip;
    char *src_port;
    char *dst_ip;
    char *dst_port;
};

struct firewall {
    struct rule *rules;
    int num_rules;
    int capacity;
};

void print_firewall(struct firewall *fw) {
    for (int i = 0; i < fw->num_rules; i++) {
        struct rule *r = &fw->rules[i];
        printf("%s %s %s:%s -> %s:%s\n", r->protocol, r->action, r->src_ip, r->src_port, r->dst_ip, r->dst_port);
    }
}

void add_rule(struct firewall *fw, char *protocol, char *action, char *src_ip, char *src_port, char *dst_ip, char *dst_port) {
    if (fw->num_rules == fw->capacity) {
        fw->capacity *= 2;
        fw->rules = realloc(fw->rules, sizeof(struct rule) * fw->capacity);
    }
    struct rule *r = &fw->rules[fw->num_rules++];
    r->protocol = protocol;
    r->action = action;
    r->src_ip = src_ip;
    r->src_port = src_port;
    r->dst_ip = dst_ip;
    r->dst_port = dst_port;
}

void remove_rule(struct firewall *fw, char *protocol, char *action, char *src_ip, char *src_port, char *dst_ip, char *dst_port) {
    for (int i = 0; i < fw->num_rules; i++) {
        struct rule *r = &fw->rules[i];
        if (strcmp(r->protocol, protocol) == 0 && strcmp(r->action, action) == 0 && strcmp(r->src_ip, src_ip) == 0 && strcmp(r->src_port, src_port) == 0 && strcmp(r->dst_ip, dst_ip) == 0 && strcmp(r->dst_port, dst_port) == 0) {
            for (int j = i; j < fw->num_rules - 1; j++) {
                fw->rules[j] = fw->rules[j + 1];
            }
            fw->num_rules--;
            break;
        }
    }
}

int main() {
    struct firewall fw;
    fw.num_rules = 0;
    fw.capacity = 10;
    fw.rules = malloc(sizeof(struct rule) * fw.capacity);

    add_rule(&fw, "tcp", "allow", "192.168.0.1", "80", "192.168.0.2", "8080");
    add_rule(&fw, "tcp", "allow", "192.168.0.1", "80", "192.168.0.3", "8080");
    add_rule(&fw, "udp", "allow", "192.168.0.1", "53", "192.168.0.2", "53");
    add_rule(&fw, "tcp", "allow", "192.168.0.1", "80", "192.168.0.4", "8080");
    add_rule(&fw, "tcp", "allow", "192.168.0.1", "80", "192.168.0.5", "8080");

    print_firewall(&fw);

    remove_rule(&fw, "tcp", "allow", "192.168.0.1", "80", "192.168.0.3", "8080");

    print_firewall(&fw);

    free(fw.rules);

    return 0;
}