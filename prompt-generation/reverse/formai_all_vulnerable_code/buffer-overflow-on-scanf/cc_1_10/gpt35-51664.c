//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALERTS 10

// A structure to represent an alert
typedef struct {
    char source[50];
    char type[50];
    char message[100];
} Alert;

// Function to add an alert to the alert list
void AddAlert(Alert alerts[], int size, Alert alert) {
    if (size >= MAX_ALERTS) {
        printf("Maximum number of alerts reached\n");
        return;
    }
    alerts[size] = alert;
    printf("New alert added: %s\n", alert.message);
}

// Function to check if the message contains a suspicious keyword
int IsSuspicious(char* message) {
    char* keywords[] = {"hack", "intrusion", "attack", "malware", "virus"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        if (strstr(message, keywords[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

int main() {
    Alert alerts[MAX_ALERTS] = {};
    int numAlerts = 0;
    char source[50];
    char type[50];
    char message[100];
    while (1) {
        printf("Enter source: ");
        scanf("%s", source);
        printf("Enter type: ");
        scanf("%s", type);
        printf("Enter message: ");
        scanf("%s", message);
        if (IsSuspicious(message)) {
            Alert alert = {source, type, message};
            AddAlert(alerts, numAlerts, alert);
            numAlerts++;
        }
    }
    return 0;
}