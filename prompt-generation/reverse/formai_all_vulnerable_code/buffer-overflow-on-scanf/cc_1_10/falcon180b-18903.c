//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 200
#define MAX_EVENTS 1000
#define MAX_EVENT_LENGTH 100

typedef struct {
    char *data;
    int length;
} String;

typedef struct {
    String keyword;
    String event;
} Rule;

int num_rules = 0;
Rule rules[MAX_RULES];

void add_rule(String keyword, String event) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules exceeded.\n");
        return;
    }
    rules[num_rules].keyword = keyword;
    rules[num_rules].event = event;
    num_rules++;
}

int match_rule(String event) {
    for (int i = 0; i < num_rules; i++) {
        if (strstr(event.data, rules[i].keyword.data)) {
            printf("Rule %d matched: %s\n", i, rules[i].event.data);
            return i;
        }
    }
    return -1;
}

void monitor(String event) {
    int rule_id = match_rule(event);
    if (rule_id >= 0) {
        printf("Intrusion detected: %s\n", rules[rule_id].event.data);
    }
}

int main() {
    String event;
    while (1) {
        printf("Enter event: ");
        scanf("%s", event.data);
        event.length = strlen(event.data);
        monitor(event);
    }
    return 0;
}